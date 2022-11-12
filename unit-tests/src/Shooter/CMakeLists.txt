add_library(shooter_src_shooter STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/Shooter.cpp)

add_library(Shooter_tests OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/Shooter.Test.cpp)

target_link_libraries(Shooter_tests PRIVATE Catch2::Catch2)

target_link_libraries(Shooter_tests PRIVATE shooter_src_shooter)

