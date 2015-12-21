project(euler_003)
add_executable(largest_prime_factor largest_prime_factor.cpp)
target_include_directories(largest_prime_factor PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(largest_prime_factor libobi ${BOOST_LIBRARIES})
