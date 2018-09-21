cmake_minimum_required(VERSION 3.12)
project(CppBry)

set(CMAKE_CXX_STANDARD 11)


set(CURL_LIBRARY "-lcurl")
set(CURLPP_LIBRARY "-Llib -lcurlpp")
set(CXX_FLAGS "-Iinclude")

find_package(CURL REQUIRED)

add_executable(CppBry main.cpp src/lbryapi.cpp src/lbryapi.h src/namespace.h include/json.hpp src/LBRYException.cpp src/LBRYException.h)

target_link_libraries(CppBry ${CXX_FLAGS} ${CURL_LIBRARY} ${CURLPP_LIBRARY})
