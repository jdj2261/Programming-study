cmake_minimum_required(VERSION 3.10)

project(composition_test)
add_definitions("-Wall -Wextra -std=c++17")
include_directories(include)
file(GLOB SOURCE_FILES
    include/Monster.h
    include/Poisition2D.h
    src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})