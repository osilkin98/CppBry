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
#include "lbryapi.h"


#define string std::string
#define map std::map

std::once_flag once_flag;

size_t lbry::BaseApi::request_id = 0;

using json = nlohmann::json;

/*using namespace curlpp;*/

json lbry::BaseApi::make_request(const string& url, const string& method,
                                      map<string, string> params, const string& username,
                                      const string& password) {

    /* INITIALIZE CurlPP ONCE */
    std::call_once(once_flag, curlpp::initialize, CURL_GLOBAL_ALL);


    json data;
    return data;

}
