add_library(cllist_src_list STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/CLList.cpp)

add_library(CLList_tests OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/CLList.Test.cpp)

target_link_libraries(CLList_tests PRIVATE Catch2::Catch2)

target_link_libraries(CLList_tests PRIVATE cllist_src_list)

