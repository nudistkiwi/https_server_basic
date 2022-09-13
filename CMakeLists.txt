#
# Copyright (c) 2016-2017 Vinnie Falco (vinnie dot falco at gmail dot com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# Official repository: https://github.com/boostorg/beast
#

cmake_minimum_required(VERSION 3.1...3.16)
project(https_server_basic VERSION 1.0)

find_package(OpenSSL)
find_package(Boost COMPONENTS thread system REQUIRED)

if (UNIX)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-lboost_system -lboost_thread -lpthread -pthread")
endif (UNIX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()




if (WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif (WIN32)



  add_library(https_server_basic STATIC src/https_server_basic.cpp)
    target_include_directories(https_server_basic PUBLIC include)

    include_directories(include)


    target_link_libraries (https_server_basic
        OpenSSL::SSL OpenSSL::Crypto
   #     BOOST
      #  lib-asio
       # lib-asio-ssl
       # lib-beast
        )

