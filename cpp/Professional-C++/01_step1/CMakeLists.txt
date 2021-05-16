cmake_minimum_required(VERSION 3.10)

project(HR_management)

# Require c++11
set(CMake_CXX_COMPILER g++)
set(CMake_CXX_STANDARD 11)
set(CMake_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions("-Wall -Wextra -std=c++11")

include_directories(include)
file(GLOB SOURCE_FILES
    include/*.h
    include/employee/*.h
    include/database/*.h
    src/employee/*.cpp
    src/database/*.cpp
    src/main.cpp
    )
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME})

add_library(Employee SHARED
    src/employee/employee.cpp
    include/employee/employee.h)
target_link_libraries(Employee)

add_library(Database SHARED
    include/database/database.h
    src/database/database.cpp)
target_link_libraries(Database)

# for testEmployeeTest
add_executable(EmployeeTest tests/EmployeeTest.cpp)
target_link_libraries( 
    Employee
    )

add_executable(DatabaseTest tests/DatabaseTest.cpp)
target_link_libraries(DatabaseTest 
    Database
    )
