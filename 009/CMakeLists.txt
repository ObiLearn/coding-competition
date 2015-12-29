project(euler_009)

set(files
    "special_pythagorean_triplet"
)

foreach(tname IN LISTS files)
    add_executable(${tname} ${tname}.cpp)
    target_include_directories(${tname} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${tname} libobi ${BOOST_LIBRARIES})
endforeach()
