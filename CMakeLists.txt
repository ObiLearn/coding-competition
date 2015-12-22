# Copyright - 2015 - Jan Christoph Uhde <Jan@UhdeJC.com>

cmake_minimum_required(VERSION 3.0.0)
project(euler)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libobi/CMakeLib")

option(LIBOBI_EXAMPLES ON)

## set os specific flags
include(obi_compiler_warnings)
include(obi_util)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${stone-warnings}")
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    # replace with CMAKE_CXX_STANDARD when a newer cmake becomes
    # available.
    # set(CMAKE_CXX_STANDARD 14) //17 not available in cmake
    # ##set_property(TARGET libobi PROPERTY CXX_STANDARD 14) <-- this would be nice
endif()

find_package(Boost REQUIRED)
add_subdirectory(libobi)

foreach(sdir RANGE 1 15)
    prefix("${sdir}" "3" "0" sdir)
    add_subdirectory_checked("${CMAKE_CURRENT_SOURCE_DIR}/${sdir}" TRUE)
endforeach(sdir)
