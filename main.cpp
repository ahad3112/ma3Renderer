#include <iostream>
#include <cmath>
#include <cstdlib>
#include "core/Geometry.hpp"
#include "core/Interaction.hpp"
#include "core/Scene.hpp"
#include "core/Camera.hpp"
#include "shapes/Sphere.hpp"
#include "materials/MatteMaterial.hpp"
#include "materials/Metal.hpp"
#include "core/GeometricPrimitive.hpp"
#include "visualization/MA_window.hpp"
#include "core/Transform.hpp"
#include "integrators/SamplerIntegrator.hpp"
#include "cameras/PerspectiveCamera.hpp"


#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 480


//================================================================================================================//
// Global variables
//================================================================================================================//
// TODO THINK ABOUT smart_pointer
Camera *camera;
MAWindow *ma_window;

int main(int argc, char *argv[]) {

    //================================================================================================================//
    // Checking Bound2 template
    //================================================================================================================//

//    Bounds3i bi(Point3i(100,90,0), Point3i(10,200,1));
//    std::cout << "Bounds2i: " << bi.pMin.x << std::endl;
//    std::cout << "Bounds2i: " << bi.pMin.y << std::endl;
//    std::cout << "Bounds2i: " << bi.pMin.z << std::endl;
//
//    std::cout << "Bounds2i: " << bi.pMax.x << std::endl;
//    std::cout << "Bounds2i: " << bi.pMax.y << std::endl;
//    std::cout << "Bounds2i: " << bi.pMax.z << std::endl;

    //================================================================================================================//
    // Checking Transform START
    //================================================================================================================//
    //Transform t;

    //================================================================================================================//
    // Checking Transform END
    //================================================================================================================//
//    Transform t;
////
////    std::cout << t << std::endl;
////    Vector3i v(1,1,1);
////    Vector3i vt = t(v); // TODO transform not working
//
//      Vector3i v(1,1,1);
//      t(v,1);
//      if(typeid(v).name() ==  typeid(Point3f).name()) {
//          std::cout << "Same type" << std::endl;
//      } else {
//          std::cout << "Not same type" << std::endl;
//      }

    //================================================================================================================//
    // Start ma3Renderer
    //================================================================================================================//
    std::cout << "This is ##### ma3Renderer #####" << std::endl;


    //================================================================================================================//
    // Film
    //================================================================================================================//
    Point2i resolution(WINDOW_WIDTH , WINDOW_HEIGHT);
    Bounds2f cropWindow(Point2f(0.0f, 0.0f), Point2f(1.0f, 1.0f));  // RANGE (0,1)
    float diagonal = 10.0f;         // In mili meter.... TODO ...need to know what is does
    float scale = 1.0f;             // TODO ...need to know what is does
    Film *film  = new Film(resolution, cropWindow, diagonal, std::string("fileName"), 1.0f);
    //================================================================================================================//
    // Camera
    //================================================================================================================//
    Point3f lookFrom(-2,2,1);
    Point3f lookAt(0,0,-1);
    //float focusDist = glm::length(lookFrom - lookAt);
    float aperture = 0.5f;
    float fov = 60.0f;          // [degrees]
    float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
    camera = new Camera(lookFrom, lookAt, Vector3f(0,1,0), fov, aspectRatio, aperture, film);


    //================================================================================================================//
    // PerspectiveCamera PBRT TODO NOT WORKING RIGHT NOW
    //================================================================================================================//
    // PerspectiveCamera Assume that the camera is at the origin of the world space

//    Transform worldToCamera = translate(Vector3f(15.0f, 0.0f, 0.0f));
//    Transform cameraToWorld = inverse(worldToCamera);
//    std::cout << "cameraToWorld: " << cameraToWorld << std::endl;
//    Bounds2f screenWindow(Point2f(-1.0f, -1.0f), Point2f(1.0f, 1.0f));
//    float shutterOpen = 0.0f;
//    float shutterClose = 0.0f;
//    float lensRadius = 0.5f;
//    float focalDist = 4.0f;
//    float fov = 30.0f;
//    Camera *camera = new PerspectiveCamera(cameraToWorld, screenWindow, shutterOpen, shutterClose, lensRadius, focalDist, fov, &film);


    //================================================================================================================//
    // Scene
    //================================================================================================================//
    float R = cos(MA_PI / 4.0f);
    Sphere sphere1(Point3f(-R, 0.0f,-1.0f), R);
    Sphere sphere2(Point3f(R, 0.0f, -1.0f), R);
    Sphere sphere3(Point3f(0.0f, -100.5f, -1.0f), 100.0f);
    Sphere sphere4(Point3f(-2.0f, 1.0f, -1.0f), 0.5f);


    MatteMaterial matte1(Vector3f(0.1, 0.2, .5));
    MatteMaterial matte2(Vector3f(.8, 0.8, 0.0));
    MatteMaterial matte3(Vector3f(.8, .8, 0.0));
    Metal metal1(Vector3f(.8, .6, .2), 0.2);
    Metal metal2(Vector3f(.8, .8, .8), 0.2);


    GeometricPrimitive gprimitive1(&sphere1, &matte1);
    GeometricPrimitive gprimitive2(&sphere2, &metal2);
    GeometricPrimitive gprimitive3(&sphere3, &matte3);
    GeometricPrimitive gprimitive4(&sphere4, &metal2);




    Scene scene;
    scene.addPrimitive(&gprimitive1);
    scene.addPrimitive(&gprimitive2);
    scene.addPrimitive(&gprimitive3);
    //scene.addPrimitive(&gprimitive4);

    //================================================================================================================//
    // Call Integrator for rendering
    //================================================================================================================//
    ma_window = new MAWindow("########## ma3Renderer ##########", WINDOW_WIDTH, WINDOW_HEIGHT);
    //=========================== Setup glfw callback ==========================//
    glfwSetKeyCallback(ma_window->getWindow(), keyCallback);
    glfwSetFramebufferSizeCallback(ma_window->getWindow(), framebufferSizeCallback);


    //================================================================================================================//
    // Call Integrator for rendering
    //================================================================================================================//
    SamplerIntegrator integrator(ma_window,camera);
    integrator.Render(scene);

    //================================================================================================================//
    // Delete resources
    //================================================================================================================//
    // TODO write a method to release memory
    delete ma_window;
    delete film;
    delete camera;


    //================================================================================================================//
    // Terminate glfw
    //================================================================================================================//
    // TODO write a method in MAWindow class to release memory and glfw
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glfwTerminate();

    return 0;
}



//====================================================================================================================//
// GLFW callback mehtods
//====================================================================================================================//

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        // Update the field of view
        camera->setVfov(camera->getVfov() + 10.0f);
        ma_window->cameraSettingChanged = true;
    }

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        // Change the origin of the camera in x direction
        camera->setOrigin(camera->getOrigin() + Point3f(0.5f, 0.0f, 0.0f));
        ma_window->cameraSettingChanged = true;
    }

    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        // Change the origin of the camera in -x direction
        camera->setOrigin(camera->getOrigin() + Point3f(-.5f, 0.0f, 0.0f));
        ma_window->cameraSettingChanged = true;
    }
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {

    // this is for testing
    //camera->setVfov(camera->getVfov() + 10.0f)
    glViewport(0, 0, width, height);
}