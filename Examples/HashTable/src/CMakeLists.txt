cmake_minimum_required(VERSION 3.8)
project(moodleodev)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp App.cpp App.h Employee.cpp Employee.h HashMap.cpp HashMap.h)
configure_file(personeller.txt personeller.txt COPYONLY)
add_executable(moodleodev ${SOURCE_FILES})