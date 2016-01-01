project(euler_008)

set(files "large_sum")

foreach(tname IN LISTS files)
    add_executable(${tname} ${tname}.cpp)
    target_include_directories(${tname} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${tname} libobi ${BOOST_LIBRARIES})
endforeach()

file(COPY "number" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
