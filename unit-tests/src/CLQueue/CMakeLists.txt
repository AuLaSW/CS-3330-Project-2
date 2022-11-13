add_library(clqueue_src_queue STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/CLQueue.cpp)

add_library(CLQueue_tests OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/CLQueue.Test.cpp)

target_link_libraries(CLQueue_tests PRIVATE Catch2::Catch2)

target_link_libraries(CLQueue_tests PRIVATE clqueue_src_queue)

