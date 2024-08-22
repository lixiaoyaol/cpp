cmake_minimum_required(VERSION 3.22)

project(matrix)

set(CXX_STANDARD 17)

add_executable(a matrix_main.cpp matrix_operate.cpp vector_operate.cpp)