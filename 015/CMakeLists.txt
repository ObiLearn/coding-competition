project(euler_015)
add_executable(lattice_path lattice_path.cpp)
target_include_directories(lattice_path PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(lattice_path libobi ${BOOST_LIBRARIES})
