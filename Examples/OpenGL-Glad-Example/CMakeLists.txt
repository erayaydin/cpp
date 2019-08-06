cmake_minimum_required(VERSION 2.8)

cmake_policy(SET CMP0072 NEW)

project(ProjectName)
add_executable(ProjectName main.cpp glad/glad.c)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIR} glad/include)

target_link_libraries(ProjectName ${OPENGL_LIBRARIES} ${OPENGL_gl_LIBRARY} glfw dl)
