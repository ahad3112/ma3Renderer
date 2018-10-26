cmake_minimum_required(VERSION 3.12)
project(ma3Renderer)

set(CMAKE_CXX_STANDARD 14)

set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
include_directories(${GLEW_H} ${GLFW_H})



set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})


set(SOURCE_FILES main.cpp)
add_executable(ma3Renderer ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(ma3Renderer "-framework OpenGL")
    target_link_libraries(ma3Renderer "-framework GLUT")
endif()
