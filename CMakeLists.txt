cmake_minimum_required(VERSION 3.5)
project(Project_2_Austin_Swanlaw)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Project_2_Austin_Swanlaw ${SOURCES})
