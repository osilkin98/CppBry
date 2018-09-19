//
// Created by oleg on 9/18/18.
//

#include <string>    // includes the definition for string
#include <cstddef>   // Includes the definition for size_t
#include <map>
#include "lbryapi.h"
#include "../include/json.hpp"

size_t lbry::BaseApi::request_id = 0;

json lbry::BaseApi::make_request(const std::string& url, const std::string& method,
                                      std::map<std::string, std::string> params, const std::string& username,
                                      const std::string& password) {


}
