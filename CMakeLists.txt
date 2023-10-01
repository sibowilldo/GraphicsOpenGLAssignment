cmake_minimum_required(VERSION 3.26)
project(OpenGLProjVS2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(Libraries)
include_directories(Libraries/include)
include_directories(Libraries/include/glad)
include_directories(Libraries/include/GLFW)
include_directories(Libraries/include/KHR)
include_directories(packages)
include_directories(packages/freeglut.3.0.0.v140.1.0.2)
include_directories(packages/freeglut.3.0.0.v140.1.0.2/sources)
include_directories(packages/freeglut.3.0.0.v140.1.0.2/sources/GL)

add_executable(OpenGLProjVS2022
        Libraries/include/glad/glad.h
        Libraries/include/GLFW/glfw3.h
        Libraries/include/GLFW/glfw3native.h
        Libraries/include/KHR/khrplatform.h
        packages/freeglut.3.0.0.v140.1.0.2/sources/GL/freeglut.h
        packages/freeglut.3.0.0.v140.1.0.2/sources/GL/freeglut_ext.h
        packages/freeglut.3.0.0.v140.1.0.2/sources/GL/freeglut_std.h
        packages/freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h
        glad.c
        Main.cpp)
