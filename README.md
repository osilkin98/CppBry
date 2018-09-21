#CppBRY
## API Wrapper for LBRYd & LBRYcrd written in C++11

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build: Passing](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

CppBRY is a wrapper for the [lbry daemon](https://github.com/lbryio/lbry) and 
[lbrycrd daemon](https://github.com/lbryio/lbrycrd) API for C++11. It allows users to 
interface with the LBRY daemons in order to write programs that run on the LBRY 
network. 

### Installation

Simply clone the repository into your desired installation directory
```bash
$ git clone https://github.com/osilkin98/CppBRY /path/to/dir/
```
Then you Change Directories into where you installed it
```bash
$ cd /path/to/dir
```
Now, all you have to do is change the file permissions of `install.sh` to 
enable execution, and run it as a superuser. 
```bash
# Change the permissions so you can run the file
$ sudo chmod +x install.sh

# Now just execute the file and watch it build and install.
$ sudo ./install.sh
```



This builds and installs the 
C++ [Modern JSON Library](https://github.com/nlohmann/json) to `<nlohmann/json.hpp>`
, as well as the 
[CurlPP Library](https://github.com/jpbarrette/curlpp) to `<curlpp>`, and acts 
as a wrapper for the traditional *(and very outdated)* `libcurl` library. 


**NOTE**: `CurlPP` depends on you having the `libcurl` library installed. 
At the moment there is no way to handle this dependancy issue automatically,
so you will have to install it manually. 

#### Installing libcurl

##### Installing on Linux


*Most package managers will generally have the following three:
- libcurl4-openssl-dev (OpenSSL Flavor)
- libcurl4-gnutls-dev (GnuTLS Flavor)
- libcurl4-nss-dev (NSS Flavor)

(*More Obscure Distros will only provide one, or other strange variants, so 
check with your package manager if you are unsure)

###### Debian / Ubuntu (apt-based):
```bash
# apt install libcurl4-<your-pick>-dev
```

###### RedHat / CentOS (rpm-based):
```bash
# yum install libcurl4-<your-pick>-dev
```

###### Fedora (dnf-based):

```bash
# dnf install libcurl-devel
```

###### OpenSUSE (zypper-based):
```bash
# zypper install libcurl4-32bit
```

##### Other Non-Linux Systems:

Clone the libcurl [github repository](https://github.com/curl/curl), and follow 
the steps as outlined on [their website](https://curl.haxx.se/docs/install.html).

## Usage

The wrapper uses the Modern JSON library as it allows ease-of-use on the user's end 
to be able to send and receive methods to the LBRY API.

To start, you need to have the LBRY Daemon running on your machine, which can be 
easily obtained [here](https://lbry.io/quickstart/install). Launch the daemon by running

`$ lbrynet-daemon` from the commandline, and having it just run in the background.
From here you can interact with the actual LBRY network
and start building your application.



### For Normal LbrydAPI:

```cpp
#include "lbry/lbryapi.h"       // for the actual API interaction
#include <nlohmann/json.hpp>    // to be able to access the data

// simplicity
using json = nlohmann::json; 
using namespace lbry;

int main(void) {
    
    
    json response = LbrydAPI::call(
                      "claim_list",             // method
                      {{"name", "bellflower"}}  // param list as a std::map
                    );
                    
    /* This returns a JSON-RPC formatted object in the form
        { 
            "id": "X",          // body values we sent to the API
            "jsonrpc": "2.0",   
            "result": {
                ...
                // this is the actual information  we received from the 
                // API. If something went wrong, instead of getting
                // "result" as the parent member, 
                // we'd instead get "error".
                ... 
            }
         } 
         */
    
    cout << setw(4) << response << endl;
    /* this prints out the request as a json-formatted object.
       in order to have it print correctly, use std::setw(4)
       to have it be formatted. The parameter to `std::setw()` 
       is the actual indentation value. Change it as you please.
    */
    
    // Simply call by the member name to get the body.
    json response_data = response["result"];
    
    /* do whatever here */
    return 0;
}

```

### For LbryCrdAPI:
```cpp
#include "lbry/lbryapi.h"       // for the actual API interaction
#include <nlohmann/json.hpp>    // to be able to access the data

// simplicity
using json = nlohmann::json; 
using namespace lbry;

int main(void) {
    // Create the LbryCrdAPI object by providing username & password
    LbryCrdAPI my_api("username", "password");
    
    // Use a member function instead to make requests
    json response = my_api.call("wallet_send", {{"amount": "420.0"},
                                                {"address": "SomeAddress"},
                                                {"claim_id": "12345"}}
                                                
     
    // this just prints the body of what the API sent back 
    // in pretty JSON format.
    cout << setw(2) << response["result"] << endl;
    
    // the types get resolved thanks to the elegance of Modern JSON
    bool succ = response["result"]["payment_scheduled"];
    
    return 0;
};
```

At the moment, the API isn't being installed directly into the compiler's include
directories (this will be implemented shortly), so you have to either write 
your project in the same directory, or define an absolute path to `lbryapi.h` in your
include directive. 

## Todo:
- Make the functions tangible and generative
- Make the library install in the actual `include` directory for `C++` compilers to have access
