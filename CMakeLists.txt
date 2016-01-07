# Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>

cmake_minimum_required(VERSION 3.0.0)
project(euler)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external_libs/libobi/cmake")
include(obi_fm_util)
obi_setup()

add_subdirectory(external_libs/libobi)
add_subdirectory(external_libs/googletest/googletest/)
find_package(Boost REQUIRED)

set(test_files
    003-largest_prime_factor
    004-largest_palindrome_product
    005-smallest_multiple
    006-sum_square_difference
    007-10001st_prime
    008-largest_product_in_a_series
    008-largest_product_in_a_series_2
    009-special_pythagorean_triplet

    010-summation_of_primes
  011-largest_product_in_a_grid
  012-highly_divisible_triangular_number
    013-large_sum
    014-longest_collatz_sequence
    015-lattice_path
    016-power_digit_sum

    XXXX-template

)

file(COPY
    "008-number"
    "011-number"
    "013-number"
    DESTINATION
    "${CMAKE_CURRENT_BINARY_DIR}"
)

foreach(test_name IN LISTS test_files) # <- DO NOT EXPAND LIST
    list(APPEND test_files_cpp "${test_name}.cpp")
endforeach()

set(test_target "project_euler")
set(test_main  "gtest.cpp")
add_executable("${test_target}" ${test_main} ${test_files_cpp})
target_include_directories("${test_target}" PRIVATE ${gtest_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
target_link_libraries("${test_target}" libobi gtest_main gtest ${BOOST_LIBRARIES})
#add_test("${test_target}_run" "${test_target}")

