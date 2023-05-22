cmake_minimum_required(VERSION 3.20)
project(List CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} List/SinglyList.cpp)
