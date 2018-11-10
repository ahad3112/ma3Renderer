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
#include "materials/Dielectric.hpp"


#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 480
#define MAX_DEPTH 40


//================================================================================================================//
// Forward mehtod deleration
//================================================================================================================//
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);


void testShirley();

void testPBRT();

//================================================================================================================//
// Global variables
//================================================================================================================//
// TODO THINK ABOUT smart_pointer
Film *film;
Camera *camera;
MAWindow *ma_window;

int main(int argc, char *argv[]) {
    //================================================================================================================//
    // Start ma3Renderer
    //================================================================================================================//
    std::cout << "This is ##### ma3Renderer #####" << std::endl;


    //================================================================================================================//
    // Call Integrator for rendering
    //================================================================================================================//
    ma_window = new MAWindow("########## ma3Renderer ##########", WINDOW_WIDTH, WINDOW_HEIGHT);

    //================================================================================================================//
    // Setup glfw callback
    //================================================================================================================//
    glfwSetKeyCallback(ma_window->getWindow(), keyCallback);
    glfwSetFramebufferSizeCallback(ma_window->getWindow(), framebufferSizeCallback);


    testShirley();
    //testPBRT();


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
// Trying two different way Pbrt and shirley
//====================================================================================================================//

void testShirley() {
    //================================================================================================================//
    // Film
    //================================================================================================================//
    Point2i resolution(WINDOW_WIDTH , WINDOW_HEIGHT);
    Bounds2f cropWindow(Point2f(0.0f, 0.0f), Point2f(1.0f, 1.0f));  // RANGE (0,1)
    float diagonal = 10.0f;         // In mili meter.... TODO ...need to know what is does
    float scale = 1.0f;             // TODO ...need to know what is does
    film  = new Film(resolution, cropWindow, diagonal, std::string("fileName"), 1.0f);
    //================================================================================================================//
    // Camera
    //================================================================================================================//
    Point3f lookFrom(3,3,2);
    //Point3f lookFrom(-2,2,1);
    //Point3f lookFrom(0,0,0.0f);
    Point3f lookAt(0,0,-1);
    //float focusDist = glm::length(lookFrom - lookAt);
    float aperture = 2.0f;
    float fov = 20.0f;          // [degrees]
    float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
    camera = new Camera(lookFrom, lookAt, Vector3f(0,1,0), fov, aspectRatio, aperture, film);

    //================================================================================================================//
    // Scene
    //================================================================================================================//
    float R = cos(MA_PI / 4.0f);
//    Sphere sphere1(Point3f(-R, 0.0f,-1.0f), R);
//    Sphere sphere2(Point3f(R, 0.0f, -1.0f), R);
//    Sphere sphere3(Point3f(0.0f, -100.5f, -1.0f), 100.0f);
//    Sphere sphere4(Point3f(-2.0f, 1.0f, -1.0f), 0.5f);
//    Sphere sphere5(Point3f(-2.0f, 1.0f, -1.0f), 0.5f);


    Sphere sphere1(Point3f(0.0f, 0.0f,-1.0f), 0.5);
    Sphere sphere2(Point3f(0, -100.5f, -1.0f), -100.0f);
    Sphere sphere3(Point3f(1.0f, 0.0f, -1.0f), 0.5f);
    Sphere sphere4(Point3f(-1.0f, 0.0f, -1.0f), 0.5f);
    Sphere sphere5(Point3f(-1.0f, 0.0f, -1.0f), 0.2f);



    MatteMaterial matte1(Vector3f(0.1, 0.2, .5));
    MatteMaterial matte2(Vector3f(.8, 0.8, 0.0));
    Metal metal1(Vector3f(.8, .6, .2), 0.0);
    Metal metal2(Vector3f(1.0, 0.0, 0.0), 0.0);
    Dielectric dielect1(Vector3f(1.0f, 1.0f, 1.0f), 1.5f);
    Dielectric dielect2(Vector3f(1.0f, 1.0f, 1.0f), 1.5f);



    GeometricPrimitive gprimitive1(&sphere1, &matte1);
    GeometricPrimitive gprimitive2(&sphere2, &matte2);
    GeometricPrimitive gprimitive3(&sphere3, &metal1);
    GeometricPrimitive gprimitive4(&sphere4, &dielect1);
    GeometricPrimitive gprimitive5(&sphere5, &dielect2);





    Scene scene;
    scene.addPrimitive(&gprimitive1);
    scene.addPrimitive(&gprimitive2);
    scene.addPrimitive(&gprimitive3);
    scene.addPrimitive(&gprimitive4);
    scene.addPrimitive(&gprimitive5);

    //================================================================================================================//
    // Call Integrator for rendering
    //================================================================================================================//
    SamplerIntegrator integrator(MAX_DEPTH,ma_window,camera);
    integrator.Render(scene);

}

void testPBRT() {


    //================================================================================================================//
    // Film
    //================================================================================================================//
    Point2i resolution(WINDOW_WIDTH , WINDOW_HEIGHT);
    Bounds2f cropWindow(Point2f(0.0f, 0.0f), Point2f(1.0f, 1.0f));  // RANGE (0,1)
    float diagonal = 10.0f;         // In mili meter.... TODO ...need to know what is does
    float scale = 1.0f;             // TODO ...need to know what is does
    film  = new Film(resolution, cropWindow, diagonal, std::string("fileName"), 1.0f);

    //================================================================================================================//
    // PerspectiveCamera PBRT TODO NOT WORKING RIGHT NOW
    //================================================================================================================//
    // PerspectiveCamera Assume that the camera is at the origin of the world space

//    Transform worldToCamera(Matrix4x4(1.0f,-0.0f,1.50996e-007f,-1.13687e-013f,
//                                        -0.0f,1.0f,-0.0f,-1.0f,
//                                        1.50996e-007f,-0.0f,-1.0f,7.0f,
//                                        -0.0f,-0.0f,-0.0f,1.0f));
//    Transform cameraToWorld = inverse(worldToCamera);


    Point3f lookFrom(3,4,1.5);
    Point3f look(.5,0.5,0);
    Vector3f up(0,0,1);

    Transform worldToCamera = lookAt(lookFrom, look, up);
    Transform cameraToWorld = inverse(worldToCamera);
    Point3f p = cameraToWorld(Point3f(0,0,0));
    std::cout << p.x << " " << p.y << " " << p.z << std::endl;

    std::cout << "worldToCamera: " << worldToCamera << std::endl;

    Bounds2f screenWindow(Point2f(-1.0f, -1.0f), Point2f(1.0f, 1.0f));
    float shutterOpen = 0.0f;
    float shutterClose = 0.0f;
    float lensRadius = 0.0f;
    float focalDist = 50.0f;
    float fov = 45.0f;

    float aperture = 2.0f;
    float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;

    camera = new PerspectiveCamera(cameraToWorld, screenWindow, shutterOpen, shutterClose, lensRadius, focalDist, fov, film);

    //camera = new Camera(lookFrom, look,up, fov, aspectRatio, aperture, film);


    //================================================================================================================//
    // Scene
    //================================================================================================================//

    // < Sphere 1 >
//    Transform  objectToWorld1(Matrix4x4(1.0f,0.0f,0.0f,-0.22827f,
//                                  0.0f,1.0f,0.0f,1.2f,
//                                  0.0f,0.0f,1.0f,0.152505f,
//                                  0.0f,0.0f,0.0f,1.0f));
//
//    Sphere sphere1(objectToWorld1(Point3f(0.0f, 0.0f,0.0f)), 0.3);


    Sphere sphere1(Point3f(0.0f, 0.0f, 0.0f), 1.0);


    Sphere sphere2(Point3f(0, -100.5f, 1.0f), 100.0f);
    Sphere sphere3(Point3f(1.0f, 0.0f, 1.0f), 0.5f);
    Sphere sphere4(Point3f(-1.0f, 0.0f, 1.0f), 0.5f);
    Sphere sphere5(Point3f(-1.0f, 0.0f, 1.0f), 0.2f);



    MatteMaterial matte1(Vector3f(0.4, 0.45, 0.5));
    MatteMaterial matte2(Vector3f(.8, 0.8, 0.0));
    Metal metal1(Vector3f(.8, .6, .2), 0.0);
    Metal metal2(Vector3f(1.0, 0.0, 0.0), 0.0);
    Dielectric dielect1(Vector3f(1.0f, 1.0f, 1.0f), 1.5f);
    Dielectric dielect2(Vector3f(1.0f, 1.0f, 1.0f), 1.5f);



    GeometricPrimitive gprimitive1(&sphere1, &matte1);
    GeometricPrimitive gprimitive2(&sphere2, &matte2);
    GeometricPrimitive gprimitive3(&sphere3, &metal1);
    GeometricPrimitive gprimitive4(&sphere4, &dielect1);
    GeometricPrimitive gprimitive5(&sphere5, &dielect2);





    Scene scene;
    scene.addPrimitive(&gprimitive1);
//    scene.addPrimitive(&gprimitive2);
//    scene.addPrimitive(&gprimitive3);
//    scene.addPrimitive(&gprimitive4);
//    scene.addPrimitive(&gprimitive5);

    //================================================================================================================//
    // Call Integrator for rendering
    //================================================================================================================//
    SamplerIntegrator integrator(MAX_DEPTH,ma_window,camera);
    integrator.Render(scene);
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
    glViewport(0, 0, width, height);
}