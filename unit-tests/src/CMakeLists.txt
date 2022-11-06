file(GLOB SOURCES "../src/*.cpp")
add_library(src STATIC SOURCES)

file(GLOB TESTS "./*.cpp")
add_library(tests OBJECT TESTS)

target_link_libraries(tests PRIVATE Catch2::Catch2)

target_link_libraries(tests PRIVATE src)

