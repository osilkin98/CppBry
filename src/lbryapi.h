// include/string is used for passing strings in and out of functions
#include <string>   // includes the definition for string
#include <cstddef>  // Includes the definition for size_t
#include <list>
#include <utility>
#include "namespace.h"

#ifndef LBRY_BASEAPI_H
#define LBRY_BASEAPI_H

class lbry::BaseApi {
private:
    static size_t request_id;

public:
    /** Makes a POST Request to the given `URL` with the specified method with the given params and the authorization
     *
     * @param url URL to which we make the POST request to
     * @param method Method we wish to call from the API
     * @param params Parameters
     * @param basic_auth
     * @return
     */

    template <typename Container>
    static std::string make_request(std::string url, std::string method, Container<std::string> params,
            std::pair<std::string> basic_auth);

};



#endif //CPPBRY_LBRYAPI_H
