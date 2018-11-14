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


#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480
#define MAX_DEPTH 2


//================================================================================================================//
// Forward mehtod deleration
//================================================================================================================//
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);


void testShirley();

void testPBRT();

void testTransform();
Scene *randomScene();

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


    //testShirley();
    testPBRT();

    //testTransform();
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
// Testing Transform
//====================================================================================================================//
void testTransform() {

    // [ Debugging Transform =========================================================================================//
    Matrix4x4 m(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
    Matrix4x4 mn(360, 0, 0, 360, 0, -240, 0, 240, 0, 0, 1, 0, 0, 0, 0, 1);

    std::cout << "Matrix4x4 : " << glm::inverse(mn) << std::endl;



    Point3f lookFrom(0, 0.0, 1);
    Point3f look(0.0, 0.0, 1.5);
    Vector3f up(0, -1, 0);


    Transform worldToCamera = lookAt(lookFrom, look, up);
    Transform cameraToWorld = inverse(worldToCamera);

    std::cout << "worldToCamera : " << worldToCamera << std::endl;
    std::cout << "cameraToWorld : " << cameraToWorld << std::endl;

    Point3f p1 = worldToCamera(Point3f(1,0,-10));
    std::cout << p1.x << " " << p1.y << " " << p1.z << std::endl;

//    Matrix4x4 m(1.0f, 10.0f, 11.0f, 0.0f,
//                0.0f, 1.0f, 2.0f, 7.0f,
//                0.0f, 1.0f, 1.0f, 1.0f,
//                1.0f, 3.0f, 4.0f, 9.0f);
//
//    //std::cout << "Matrix: " << glm::transpose(m) << std::endl;
//
//    Transform tr1(m);
//    Transform tr2(Matrix4x4(1.0f, 3.0f, 2.0f, 0.0f,
//                            0.0f, 1.0f, 1.0f, 0.0f,
//                            0.0f, 0.0f, 1.0f, 0.0f,
//                            0.0f, 0.0f, 1.0f, 1.0f));
//
//    Transform tr = tr1 * tr1;
//
//    //std::cout << "tr1: " << tr << std::endl;
//
//    Point3f p1 = tr(Point3f(-2,2,1));
//    //std::cout << p1.x << " " << p1.y << " " << p1.z << std::endl;
    // =========================================================================================== Debugging Transform ]


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


    Point3f lookFrom(3, 4.0, -1.5);
    Point3f lookAt(0.5, 0.5, 0);
    Vector3f vup(0, 0, 1);


    //Point3f lookFrom(3,3,2);
    //Point3f lookFrom(-2,2,1);
    //Point3f lookFrom(0,0,0.0f);
    //Point3f lookAt(0,0,-1);
    //Vector3f vup(0,1,0);
    float aperture = 0.0f;
    float fov = 30.0f;          // [degrees]
    float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
    camera = new Camera(lookFrom, lookAt, vup, fov, aspectRatio, aperture, film);

    //================================================================================================================//
    // Scene
    //================================================================================================================//
    float R = cos(MA_PI / 4.0f);
//    Sphere sphere1(Point3f(-R, 0.0f,-1.0f), R);
//    Sphere sphere2(Point3f(R, 0.0f, -1.0f), R);
//    Sphere sphere3(Point3f(0.0f, -100.5f, -1.0f), 100.0f);
//    Sphere sphere4(Point3f(-2.0f, 1.0f, -1.0f), 0.5f);
//    Sphere sphere5(Point3f(-2.0f, 1.0f, -1.0f), 0.5f);


    Sphere sphere1(Point3f(0.0f, 0.0f,0.0f), 1.0);
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
//    scene.addPrimitive(&gprimitive2);
//    scene.addPrimitive(&gprimitive3);
//    scene.addPrimitive(&gprimitive4);
//    scene.addPrimitive(&gprimitive5);


//    Scene scene = *randomScene();

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
    float scaling = 1.0f;             // TODO ...need to know what is does
    film  = new Film(resolution, cropWindow, diagonal, std::string("fileName"), 1.0f);

    //================================================================================================================//
    // PerspectiveCamera PBRT TODO NOT WORKING RIGHT NOW
    //================================================================================================================//


    Point3f lookFrom(0, 0.0, -1.0);
    Point3f look(0.0, 0.0, 0);
    Vector3f up(0, 1, 0);


    Transform worldToCamera = lookAt(lookFrom, look, up);
    Transform cameraToWorld = inverse(worldToCamera);



    Bounds2f screenWindow(Point2f(-1.0f, -1.0f), Point2f(1.0f, 1.0f));
    float shutterOpen = 0.0f;
    float shutterClose = 0.0f;
    float lensRadius = 0.0f;
    float focalDist = 50.0f;
    float fov = 60.0f;

    float aperture = 2.0f;
    float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;

    camera = new PerspectiveCamera(cameraToWorld, screenWindow, shutterOpen, shutterClose, lensRadius, focalDist, fov, film);


    //================================================================================================================//
    // Scene
    //================================================================================================================//


    Sphere sphere1(Point3f(0.0f, 0.0f, 1.0f), 0.25);
    Sphere sphere2(Point3f(0, 100.25f, 1.0f), 100.0f);
    Sphere sphere3(Point3f(0.5f, 0.0f, 0.5f), 0.25f);
    Sphere sphere4(Point3f(-.5f, 0.0f, 0.5f), 0.25f);
    Sphere sphere5(Point3f(-1.0f, 0.0f, 1.0f), 0.2f);



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
    GeometricPrimitive gprimitive5(&sphere5, &metal1);





    Scene scene;
    scene.addPrimitive(&gprimitive1);
    scene.addPrimitive(&gprimitive2);
    scene.addPrimitive(&gprimitive3);
    scene.addPrimitive(&gprimitive4);
//    scene.addPrimitive(&gprimitive5);



    //================================================================================================================//
    // Call Integrator for rendering
    //================================================================================================================//
    SamplerIntegrator integrator(MAX_DEPTH,ma_window,camera);
    integrator.Render(scene);
}


Scene *randomScene() {
    Scene *scene = new Scene();

    int max = 5;
    int min = -max;

    Sphere *sp1 = new Sphere(Vector3f(0, -1000, 0), 1000);
    Material *mat1 = new MatteMaterial(Vector3f(.5, .5, .5));
    scene->addPrimitive(new GeometricPrimitive(sp1, mat1));

    int counter = 0;
    for (int a = min; a < max; a++) {
        for(int b = min; b < max; b++) {
            float chooseMat = drand48();
            Point3f center(a + 0.9f * drand48(), 0.2f, b + 0.9f * drand48());

            if(glm::length(center - Point3f(4.0, 0.2, 0.0)) > 0.9f){

                if (chooseMat < 0.8f) {
                    // diffuse
                    Sphere *sphere = new Sphere(center, 0.2);
                    Material *material = new MatteMaterial(Vector3f(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()));
                    scene->addPrimitive(new GeometricPrimitive(sphere, material));
                } else if (chooseMat < 0.95f) {
                    // metal
                    Sphere *sphere = new Sphere(center, 0.2);
                    Material *material = new Metal(Vector3f(.5 * (1 + drand48()), .5 * (1 + drand48()), .5 * (1 + drand48())), .5 * drand48());
                    scene->addPrimitive(new GeometricPrimitive(sphere, material));
                } else {
                    // glass
                    Sphere *sphere = new Sphere(center, 0.2);
                    Material *material = new Dielectric(Vector3f(1.0f, 1.0f, 1.0f),1.5);
                    //scene->addPrimitive(new GeometricPrimitive(sphere, material));
                }

            }

            counter++;
        }
    }

    std::cout << "Total Spheres: " << counter << std::endl;
    Sphere *sp2 = new Sphere(Vector3f(-4, 1, 0), 1);
    Material *mat2 = new MatteMaterial(Vector3f(.4, .2, .1));
    scene->addPrimitive(new GeometricPrimitive(sp2, mat2));

    Sphere *sp3 = new Sphere(Vector3f(4, 1, 0), 1);
    Material *mat3 = new Metal(Vector3f(.7, .6, .5), 0.0);
    scene->addPrimitive(new GeometricPrimitive(sp3, mat3));

    // Add another dielectric

    return scene;
}


//====================================================================================================================//
// GLFW callback mehtods
//====================================================================================================================//

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        // Update the field of view
        camera->setVfov(camera->getVfov() + 10.0f);
        ma_window->cameraSettingChanged = true;
    }

    if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        // Update the field of view
        camera->setVfov(camera->getVfov() - 10.0f);
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