cmake_minimum_required(VERSION 3.12)
project(ma3Renderer)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)

# GLEW, GLFW and glm header file
set(GLEW_H /usr/local/Cellar/glew/2.1.0/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.2.1/include/GLFW)
set(GLM_H /usr/local/Cellar/glm/0.9.9.2/include/glm)
include_directories(${GLEW_H} ${GLFW_H} ${GLM_H})


# GLEW AND GLFW library
set(GLEW_LINK /usr/local/Cellar/glew/2.1.0/lib/libGLEW.2.1.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.2.1/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})


set(SOURCE_FILES main.cpp core/Geometry.hpp visualization/MA_window.hpp visualization/MA_window.cpp core/Ray.hpp core/Ray.cpp core/Interaction.hpp core/Interaction.cpp core/shape.hpp core/shape.cpp shapes/Sphere.cpp shapes/Sphere.hpp utility/MA_utility.hpp core/GeometricPrimitive.cpp core/GeometricPrimitive.hpp core/Primitive.cpp core/Primitive.hpp accelerators/Aggregrate.cpp accelerators/Aggregrate.hpp core/Scene.cpp core/Scene.hpp core/Camera.cpp core/Camera.hpp core/Material.cpp core/Material.hpp materials/MatteMaterial.cpp materials/MatteMaterial.hpp core/Film.cpp core/Film.hpp core/Integrator.cpp core/Integrator.hpp integrators/SamplerIntegrator.cpp integrators/SamplerIntegrator.hpp)
add_executable(ma3Renderer ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(ma3Renderer "-framework OpenGL")
    target_link_libraries(ma3Renderer "-framework GLUT")
endif()
