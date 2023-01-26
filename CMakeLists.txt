cmake_minimum_required(VERSION 3.18)
project(thread_safe_queue)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(ts_queue)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ts_queue)
