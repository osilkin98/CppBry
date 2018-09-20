//
// Created by oleg on 9/18/18.
//
#include <string>    // includes the definition for string
#include <cstddef>   // Includes the definition for size_t
#include <map>
#include <mutex>
#include <nlohmann/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Info.hpp>
#include <list>
#include <sstream>
#include "lbryapi.h"
#include "LBRYException.h"

#define string std::string
#define map std::map<string, string>

std::once_flag once_flag;

size_t lbry::BaseApi::request_id = 0;

using json = nlohmann::json;

/*using namespace curlpp;*/

json lbry::BaseApi::make_request(const string &url, const string &method,
                                 const map&params, const string &username,
                                 const string &password) {

    try {
        /* INITIALIZE CurlPP ONCE */
        std::call_once(once_flag, curlpp::initialize, CURL_GLOBAL_ALL);

        curlpp::Cleanup cleaner;
        curlpp::Easy request;

        // to store the json data to be used as a string stream
        // that we'll retrieve later
        std::ostringstream json_stream_data;

        request.setOpt(new curlpp::options::Url(url));

        // We write to the stream using the WriteStream function
        request.setOpt(new curlpp::options::WriteStream(&json_stream_data));

        // create the headers
        std::list<string> headers = {"Content-Type: application/json-rpc",
                                     "user-agent: LBRY C++ API"};

        request.setOpt(new curlpp::options::HttpHeader(headers));

        // set the username and password
        request.setOpt(new curlpp::options::UserPwd(username + ":" + password));

        string body = R"({"jsonrpc": "2.0", "id": ")" +
                      std::to_string(++lbry::BaseApi::request_id) +    // increment id with prefix to start at 1
                      R"(", "method": ")" + method +                   // add the method
                      (!params.empty() ? R"(", "params": {)" : "\"}"); // end the body with or without the params.

        if (!params.empty()) {
            auto myit = params.begin();
            auto end = params.end();

            for (size_t count = 1; myit != end; myit++) {
                body += "\"" + (*myit).first + "\": \"" + (*myit).second + "\"" +
                        (count++ < params.size() ? ", " : "}");
            }
            body += "}";
        }

        // put the body into the Request
        request.setOpt(new curlpp::options::PostFields(body));
        request.setOpt(new curlpp::options::PostFieldSize(body.length()));

        // fire the request
        request.perform();

        auto resp = json::parse(json_stream_data.str());

        if(resp.find("result") != resp.end()) {
            // returns a copy of the decoded json stream.
            return resp;
        } else {
            throw lbry::LBRYException("POST Request made to LBRY API received LBRY Error", resp);

        }
    } catch(curlpp::LogicError& e) {
        std::cerr << e.what() << "\n";

    } catch(lbry::LBRYException& e) {
        std::cerr << e.what() << "\n";
        return e.lbry_response();

    } catch(curlpp::RuntimeError& e) {
        std::cerr << e.what() << "\n";
    }
    return json();

}



json lbry::LbryApi::call(const string &method, const map &params) {
    return lbry::BaseApi::make_request(lbry::LbryApi::LBRYD_URL, method, params);
}

lbry::LbryCrdApi::LbryCrdApi(const string &username, const string &password)
    : username(username), password(password) {

}

json lbry::LbryCrdApi::call(const string &method, const map &params) {
    return lbry::BaseApi::make_request(lbry::LbryCrdApi::LBRYCRD_URL, method, params, username, password);
}
