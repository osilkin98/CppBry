#include <iostream>
#include <string>   // includes std::string
#include <map>
#include <iomanip>
#include <nlohmann/json.hpp>
#include "lbry/lbryapi.h"



// #include "include/json.hpp"


using namespace std;


int main() {

    // This is an example of using the API in a non-
    auto response = lbry::LbrydAPI::call("claim_list", {{"name", "bellflower"}});

    cout << setw(4) << response << endl;
    cout << "response size: " << response.size() << endl;
    return 0;
}