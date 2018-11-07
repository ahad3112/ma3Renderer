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
    MAWindow(const char * ma_title, int ma_width = 720, int ma_height = 480);
    void display();
    GLFWwindow *getWindow() const;
    void registerBuffer(Point2i *pixels, Vector3f *colors)const;


    bool cameraSettingChanged = true;
private:
    void initGLFW();
    void initGL();

    GLFWwindow *window;
    int height, width;
    const char* title;
};

//====================================================================================================================//
// Opengl Info
//====================================================================================================================//
//====================================================================================================================//
// Call-back functions
//====================================================================================================================//
void errorCallback (int error, const char *description);


void displayOpenGLInfo ();



#endif //MA3RENDERER_MA_WINDOW_HPP
