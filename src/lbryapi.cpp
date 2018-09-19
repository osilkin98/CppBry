//
// Created by oleg on 9/18/18.
//

#include <string>    // includes the definition for string
#include <cstddef>   // Includes the definition for size_t
#include <map>
#include "lbryapi.h"
#include "../include/json.hpp"
/*
#include "../curlpp/include/curlpp/cURLpp.hpp"
#include "../curlpp/include/curlpp/Easy.hpp"
#include "../curlpp/include/curlpp/Options.hpp"
#include "../curlpp/include/curlpp/Exception.hpp"
*/
size_t lbry::BaseApi::request_id = 0;

/*using namespace curlpp;*/

json lbry::BaseApi::make_request(const std::string& url, const std::string& method,
                                      std::map<std::string, std::string> params, const std::string& username,
                                      const std::string& password) {


    /*
    Cleanup cleaner;
    Easy request;

    request.setOpt(new options::Url(url));
    request.setOpt(new options::Post);
    */

    json data; // this is the data that will actually be sent

    data["method"] = method;
    data["jsonrpc"] = "2.0";
    data["id"] = ++lbry::BaseApi::request_id;
    if(not params.empty()) {
        data["params"] = params;
    }

    json headers;
    headers["Content-Type"] = "application/json-rpc";
    headers["user-agent"] = "LBRY C++ API";

    data["headers"] = headers;

    return data;

}
