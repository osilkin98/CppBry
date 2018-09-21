//
// Created by oleg on 9/20/18.
//

#ifndef LBRYEXCEPTION_H
#define LBRYEXCEPTION_H

#include <stdexcept>
#include <nlohmann/json.hpp>
#include "namespace.h"

#define string std::string
#define json nlohmann::json

class lbry::LBRYException : public std::runtime_error {
protected:
    error_t status_code;
    json lbry_resp;

public:

    LBRYException(const string &what, const error_t &code);
    LBRYException(const string &what_arg, const json &error);

    inline error_t lbry_code() { return status_code;}
    inline json lbry_response() { return lbry_resp; }
};

#undef string
#undef json

#endif //CPPBRY_LBRYEXCEPTION_H
