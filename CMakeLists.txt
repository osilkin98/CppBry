cmake_minimum_required(VERSION 3.10)
project(CppBry)

set(CMAKE_CXX_STANDARD 11)


set(CURL_LIBRARY "-lcurl")
set(CURLPP_LIBRARY "-Llib -lcurlpp")
set(CXX_FLAGS "-Iinclude")

find_package(CURL REQUIRED)

add_executable(CppBry main.cpp lbry/lbryapi.cpp lbry/lbryapi.h lbry/namespace.h lbry/LBRYException.cpp lbry/LBRYException.h)

target_link_libraries(CppBry ${CXX_FLAGS} ${CURL_LIBRARY} ${CURLPP_LIBRARY})
