cmake_minimum_required(VERSION 3.5)
project(c_make_test LANGUAGES CXX)

add_subdirectory(lib/Catch2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src exampletests)

add_executable(unit_tests)

target_link_libraries(unit_tests
    Catch2::Catch2WithMain
    example_tests
)

