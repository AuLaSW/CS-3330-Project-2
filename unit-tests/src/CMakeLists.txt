add_library(src STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../src/CLList.cpp)

add_library(tests OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/CLList.Test.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2)

target_link_libraries(tests PRIVATE src)

