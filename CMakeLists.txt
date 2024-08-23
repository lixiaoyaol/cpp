cmake_minimum_required(VERSION 3.22)

project(matrix)

set(CXX_STANDARD 17)

aux_source_directory(. DIR_SRCS)

add_executable(a ${DIR_SRCS})