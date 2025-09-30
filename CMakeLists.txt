cmake_minimum_required(VERSION 3.15)

project("Queue Examples")

set (CMAKE_CXX_STANDARD 23)

add_executable(1_queue_operations 1_queue_operations.cpp)
add_executable(2_task_management 2_task_management.cpp)
add_executable(3_multithreaded_task_management 3_multithreaded_task_management.cpp)
add_executable(4_my_getline_with_cin 4_my_getline_with_cin.cpp)
add_executable(5_my_getline_with_a_file 5_my_getline_with_a_file.cpp)
