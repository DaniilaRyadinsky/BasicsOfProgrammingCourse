cmake_minimum_required(VERSION 3.23)
project(lab15 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab15 main.c)

add_subdirectory(libs)
target_link_libraries(lab15 data_structures)
target_link_libraries(lab15 algorithms)
