//
// Created by Muhammed Ahad on 2018-10-26.
//

#ifndef MA3RENDERER_MA_WINDOW_HPP
#define MA3RENDERER_MA_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "../core/Geometry.hpp"
#include "../core/Camera.hpp"


class MAWindow final {
public:
    MAWindow(Camera *camera, const char * ma_title, int ma_width = 720, int ma_height = 480);
    void display();
    GLFWwindow *getWindow() const;
    void registerBuffer(Point2i *pixels, Vector3f *colors)const;

private:
    //====================================================================================================================//
    // Call-back functions
    //====================================================================================================================//
    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    static void errorCallback (int error, const char *description);
    void initGLFW();
    void initGL();

    GLFWwindow *window;
    int height, width;
    const char* title;

    Camera *camera;
};

//====================================================================================================================//
// Opengl Info
//====================================================================================================================//

void displayOpenGLInfo ();



#endif //MA3RENDERER_MA_WINDOW_HPP
