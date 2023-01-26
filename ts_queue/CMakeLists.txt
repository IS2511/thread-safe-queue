cmake_minimum_required(VERSION 3.18)
project(ts_queue)

set(CMAKE_CXX_STANDARD 17)


add_library(${PROJECT_NAME} ts_queue.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
