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


#define GAMMA_2_CORRECTION 0
#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 480
#define N_SAMPLE 20
#define MAX_DEPTH 20

// TODO : USE THE CAMERA FROM PBRT

//====================================================================================================================//
// Sample color function for starting the ray tracer
//====================================================================================================================//
Vector3f color(const Ray &ray, Scene &scene, int depth) {
    SurfaceInteraction isect;
    if (scene.intersect(ray,&isect)) {
        Ray scattered;
        if(depth < MAX_DEPTH && isect.computeScatteringFunctions(ray, scattered)) {
            return (isect.primitive->getMaterial()->getAlbedo()) * color(scattered, scene, depth++);

        } else {
            return Vector3f(0, 0, 0);
        }
    } else {
        Vector3f unitDirection = glm::normalize(ray.direction);
        float t = 0.5f * (unitDirection.y + 1.0f);
        return (1.0f - t) * Vector3f(1.0f, 1.0f, 1.0f) + t * Vector3f(0.5f, 0.7f, 1.0f);
    }


}


//====================================================================================================================//
// display
//====================================================================================================================//
void draw(int width, int height, Point2f *pixels, Vector3f *colors) {

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, pixels);
    glColorPointer(3, GL_FLOAT, 0, colors);

    //glDrawArrays(GL_POINTS, 0, width * height);

    // Cleanup states: TODO CLEAN STATE AT THE END OF RENDERING...
    // THIS WAY WE WILL NOT HAVE TO CALL FOR CREATE POINTER FOR VERTEX AND COLOR MULTIPLE TIMES

    //glDisableClientState(GL_COLOR_ARRAY);
    //glDisableClientState(GL_VERTEX_ARRAY);
}


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
//
//    std::cout << t << std::endl;
//    Vector3i v(1,1,1);
//    Vector3i vt = t(v); // TODO transform not working

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
    Film film(resolution, cropWindow, diagonal, std::string("fileName"), 1.0f);
    //================================================================================================================//
    // Camera
    //================================================================================================================//
    Point3f lookFrom(-2,2,1);
    Point3f lookAt(0,0,-1);
    float focusDist = glm::length(lookFrom - lookAt);
    float aperture = 0.5f;
    Camera camera(lookFrom, lookAt, Vector3f(0,1,0), 60.0f,(float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, aperture, focusDist, &film); // fov: in degrees
    //================================================================================================================//
    // Scene
    //================================================================================================================//
    float R = cos(MA_PI / 4.0f);
    Sphere sphere1(Point3f(-R, 0.0f, -1.0f), R);
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
    SamplerIntegrator integrator(&camera);
    integrator.Render(scene);

    return 0;
}