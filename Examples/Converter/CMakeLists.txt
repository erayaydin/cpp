cmake_minimum_required(VERSION 3.13)
project(in_converter)

set(CMAKE_CXX_STANDARD 14)

add_executable(in_converter main.cpp Converter.cpp Converter.h)