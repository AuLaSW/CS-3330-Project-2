add_library(src_list STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/CLList.cpp)
add_library(src_node STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/CLNode.cpp)
add_library(src_shooter STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Shooter.cpp)

add_library(tests OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/CLList.Test.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2)

target_link_libraries(tests PRIVATE src_list)
target_link_libraries(tests PRIVATE src_node)
target_link_libraries(tests PRIVATE src_shooter)

