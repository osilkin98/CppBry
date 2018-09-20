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

std::once_flag once_flag;

size_t lbry::BaseApi::request_id = 0;

/*using namespace curlpp;*/

json lbry::BaseApi::make_request(const std::string& url, const std::string& method,
                                      std::map<std::string, std::string> params, const std::string& username,
                                      const std::string& password) {



    json data;
    return data;

}
