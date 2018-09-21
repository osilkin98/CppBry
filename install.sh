#!/usr/bin/env bash

######################################################################
# To compile and install the CurlPP library.
# If this can't install then we don't have libcurl installed
#
# This library is located in <curlpp/[your filename].hpp>
#
#
# To run the CMakeLists file in order to build the necessary targets
cmake curlpp/CMakeLists.txt

# This runs the command in a sub-shell so that way
# The parent script stays in the same directory
# And then it builds all the object files we need
# And then it installs all the file by writing them to their
# Necessary locations within the install target in the makefile
(cd curlp/ && make && make install)


######################################################################
# To compile and install the json library, which can then be located
# In <nlohmann/json>
#

# Again to build the necessary targets in order for the makefile
# To correctly execute
# cmake json/CMakeLists.txt


# Then do the same thing as before, simply cd into it and 
# Then run make and make install

