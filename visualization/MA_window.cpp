//
// Created by Muhammed Ahad on 2018-10-26.
//

#include <cstdlib>
#include <cstdio>
#include "MA_window.hpp"

//====================================================================================================================//
// Reference:
// https://stackoverflow.com/questions/24040982/c-opengl-glfw-drawing-a-simple-cube
//====================================================================================================================//



//====================================================================================================================//
// Constructor
//====================================================================================================================//
MAWindow::MAWindow(const char *ma_title, int ma_width, int ma_height) :
        title(ma_title), height(ma_height), width(ma_width) {
    initGLFW();
    initGL();
}


//====================================================================================================================//
// init GLFW
//====================================================================================================================//
void MAWindow::initGLFW() {
    //=========================== Setup error callback =========================//
    glfwSetErrorCallback(errorCallback);

    //=============================== Initializing GLFW ========================//
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not initialize GLFW\n");
        exit(EXIT_FAILURE);
    }
    //======================= creating window and context ======================//
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    //glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //============================= make context ===============================//
    glfwMakeContextCurrent(window);


    //==================== Start GLFW extesnion handler ========================//
    glewExperimental = GL_TRUE;

    //======================= Load opengl function pointer =====================//
    GLenum GLEW_RESULT = glewInit();

    if (GLEW_RESULT != GLEW_OK) {
        fprintf(stderr, "GLEW INITIALIZATION ERROR: %s\n", glewGetErrorString(GLEW_RESULT));
        exit(EXIT_FAILURE);
    }

    //=========================== Setup glfw callback ==========================//
    glfwSetKeyCallback(window, keyCallback);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

}

//====================================================================================================================//
// init GL
//====================================================================================================================//
void MAWindow::initGL() {
    //glEnable(GL_VERTEX_PROGRAM_POINT_SIZE); // This method enable vertex size in vertex shader
    // Draw stuff
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


//====================================================================================================================//
// Sample draw
//====================================================================================================================//

void drawScreen(int width, int height, Point2f *pixels, Vector3f *colors) {

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, pixels);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glDrawArrays(GL_POINTS, 0, width * height);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

//====================================================================================================================//
// display
//====================================================================================================================//
void MAWindow::display(Point2f *pixels, Vector3f *colors) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // sample drawings
        drawScreen(width, height, pixels, colors);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

//====================================================================================================================//
// Opengl Info
//====================================================================================================================//
void displayOpenGLInfo() {
    // Get info of GPU and supported OpenGL version
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL version supported %s\n", glGetString(GL_VERSION));
}

//====================================================================================================================//
// GLFW callback mehtods
//====================================================================================================================//
void errorCallback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
