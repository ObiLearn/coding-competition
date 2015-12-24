# Copyright - 2015 - Jan Christoph Uhde <Jan@UhdeJC.com>

cmake_minimum_required(VERSION 3.0.0)
project(euler)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libobi/CMakeLib")
include(obi_fm_util)
obi_settings()

find_package(Boost REQUIRED)
add_subdirectory(libobi)

foreach(sdir RANGE 1 15)
    obi_prefix("${sdir}" "3" "0" sdir)
    obi_add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${sdir}" TRUE)
endforeach(sdir)
