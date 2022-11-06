cmake_minimum_required(VERSION 3.5)

project(source_project)

include_directories(include)

file(GLOB SOURCES "src/*/*.cpp")

add_executable(source ${SOURCES})


