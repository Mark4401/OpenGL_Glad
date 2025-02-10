cmake_minimum_required(VERSION 3.16...3.29)

project(OpenGL_Setup VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)


# to access Header Files from Glad, and GLFW
include_directories(Dependencies)

# Mostly for KHB/khrplatform.h Error : KHB/khrplatform.h Could not be found or read at build time
include_directories(Dependencies/glad) 

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE GLFW3
	Dependencies/GLFW/lib/*.lib
)

file(GLOB_RECURSE GL_C_FILE
	Dependencies/glad/gl.c
)

file(GLOB_RECURSE HEADERS
	Headers/*.h
)

file(GLOB_RECURSE CPP_FILES
	Src/*.cpp
)

add_subdirectory(Src)