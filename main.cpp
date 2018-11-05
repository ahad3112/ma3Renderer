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


// TODO : USE THE CAMERA FROM PBRT

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
    float focusDist = glm::length(lookFrom - lookAt);
    float aperture = 0.5f;
    float fov = 60.0f;          // [degrees]
    float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
    Camera *camera = new Camera(lookFrom, lookAt, Vector3f(0,1,0), fov, aspectRatio, aperture, focusDist, film);


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
    SamplerIntegrator integrator(camera);
    integrator.Render(scene);

    //================================================================================================================//
    // Delete resources
    //================================================================================================================//
    delete film;
    delete camera;

    return 0;
}