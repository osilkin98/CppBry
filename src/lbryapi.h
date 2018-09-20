// include/string is used for passing strings in and out of functions

#ifndef LBRY_BASEAPI_H
#define LBRY_BASEAPI_H


#include <string>   // includes the definition for string
#include <cstddef>  // Includes the definition for size_t
#include <map>
#include "namespace.h"
#include <nlohmann/json.hpp>

/* define type macros here to make readability not an issue */
#define std_str std::string
#define json nlohmann::json

class lbry::BaseApi {
private:
    static size_t request_id;

public:
    /** Makes a POST Request to the given `URL` with the specified method with the given params and the authorization
     *
     * @param url URL to which we make the POST request to
     * @param method Method we wish to call from the API
     * @param params Parameters which we wish to put into our request
     * @param username Username to enter for the LbryCrd API
     * @param password Password corresponding to the given Username
     * @return JSON Object Representing the Response received from Server
     */
    static json make_request(const std_str &url, const std_str &method,
                             const std::map<std::string, std::string> &params = std::map<std_str, std_str>(),
                             const std_str &username = "", const std_str &password = "");

};


class lbry::LbryApi : public lbry::BaseApi {

};


#undef std_str
#undef json

#endif
