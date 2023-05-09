cmake_minimum_required(VERSION 3.25)
project(coding_task LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)

add_executable(test test.cpp)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(test PRIVATE gtest gtest_main)
target_compile_definitions(test PRIVATE CODING_TEST_DIR="${CMAKE_CURRENT_LIST_DIR}")
