// include/string is used for passing strings in and out of functions

#ifndef LBRY_BASEAPI_H
#define LBRY_BASEAPI_H


#include <string>   // includes the definition for string
#include <cstddef>  // Includes the definition for size_t
#include <map>
#include "namespace.h"
#include <nlohmann/json.hpp>

/* define type macros here to make readability not an issue */
#define str std::string
#define json nlohmann::json
#define map std::map<str, str>

class lbry::BaseApi {
private:
    static size_t request_id;

public:
    /** Makes a POST Request to the given `URL` with the 
	specified method with the given params and the authorization
     *
     * @param url URL to which we make the POST request to
     * @param method Method we wish to call from the API
     * @param params Parameters which we wish to put into our request
     * @param username Username to enter for the LbryCrd API
     * @param password Password corresponding to the given Username
     * @return JSON Object Representing the Response received from Server
     */
    static json make_request(const str &url, const str &method,
                             const map &params = map(),
                             const str &username = "",
			     const str &password = "");

};



class lbry::LbryApi : public lbry::BaseApi {
protected:
    static const str LBRYD_URL;
public:

    static json call(const str& method, const map& params=map());

};

class lbry::LbryCrdApi : public lbry::BaseApi {
protected:
    static const str LBRYCRD_URL;
    const str username, password;
public:

    explicit LbryCrdApi(const str& username = str(),
			const str& password = str());

    json call(const str& method, const map& params= map());
};


#undef str
#undef json

#endif
