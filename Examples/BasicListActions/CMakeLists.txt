cmake_minimum_required(VERSION 3.8)
project(BasicListActions)
set (BasicListActions_VERSION_MAJOR 1)
set (BasicListActions_VERSION_MINOR 0)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/stubs/data.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE_FILES main.c menu.h types.h menu.c list.h list.c)
add_executable(BasicListActions ${SOURCE_FILES})
target_link_libraries(BasicListActions m)