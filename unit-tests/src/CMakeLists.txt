file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../src/)
add_library(src STATIC SOURCES)

flie(GLOB TESTS ${CMAKE_CURRENT_SOURCE_DIR}/src/)
add_library(tests OBJECT TESTS)

target_link_libraries(tests PRIVATE Catch2::Catch2)

target_link_libraries(tests PRIVATE src)

