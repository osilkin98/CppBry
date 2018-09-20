//
// Created by oleg on 9/20/18.
//

#include "LBRYException.h"
#include <string>
#include <nlohmann/json.hpp>

lbry::LBRYException::LBRYException(const std::string &__arg,
        const nlohmann::json& error) : runtime_error(__arg),
        status_code(error["error"]["code"]), lbry_resp(error) {

}

lbry::LBRYException::LBRYException(const std::string &what,
        const error_t &code) : runtime_error(what), status_code(code),
        lbry_resp(nlohmann::json::parse(what)) {

}

