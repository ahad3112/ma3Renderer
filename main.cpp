#include <iostream>
#include <cmath>

#include "core/geometry.hpp"
#include "visualization/ma_window.hpp"
#include "core/ray.hpp"
#include "shapes/Sphere.hpp"
#include "core/GeometricPrimitive.hpp"
#include "core/Scene.hpp"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 620


//====================================================================================================================//
// Sample Sphere
//====================================================================================================================//
float hitSphere(const Point3f &center, float radius, const Ray &ray) {
    Point3f oc = ray.origin - center;
    float a = glm::dot(ray.direction , ray.direction);
    float b = 2.0f * glm::dot(oc, ray.direction);
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4.0f * a * c;

    if( discriminant < 0){
        return -1.0f;
    } else {
       return (-b - std::sqrt(discriminant)) / (2.0f * a);
    }
}

//====================================================================================================================//
// Sample color function for starting the ray tracer
//====================================================================================================================//
Vector3f color(const Ray &ray, Scene &scene) {
    SurfaceInteraction isect;
    if (scene.intersect(ray,&isect)) {
        Normal3f n = isect.normal;
        return 0.5f * Vector3f(n.x + 1, n.y + 1, n.z + 1);
    } else {
        Vector3f unitDirection = glm::normalize(ray.direction);
        float t = 0.5f * (unitDirection.y + 1.0f);
        return (1.0f - t) * Vector3f(1.0f, 1.0f, 1.0f) + t * Vector3f(0.5f, 0.7f, 1.0f);
    }

}


int main(int argc, char *argv[]) {
    std::cout << "This is ##### ma3Renderer #####" << std::endl;

    //================================================================================================================//
    // Sample rendering
    //================================================================================================================//
    Point2f  *pixels = new Point2f[WINDOW_WIDTH * WINDOW_HEIGHT];
    Vector3f  *colors = new Point3f[WINDOW_WIDTH * WINDOW_HEIGHT];

    //================================================================================================================//
    // Scene
    //================================================================================================================//
    Sphere sphere1(Point3f(0.0f, 0.0f, -1.0f), 0.5f);
    Sphere sphere2(Point3f(0.0f, -100.5f, -1.0f), 100.0f);
    Sphere sphere3(Point3f(-1.0f, 0.0f, -1.0f), 0.5f);


    GeometricPrimitive gprimitive1(&sphere1);
    GeometricPrimitive gprimitive2(&sphere2);
    GeometricPrimitive gprimitive3(&sphere3);



    Scene scene;
    scene.addPrimitive(&gprimitive1);
    scene.addPrimitive(&gprimitive2);
    //scene.addPrimitive(&gprimitive3);






    //================================================================================================================//
    // Camera setup
    //================================================================================================================//
    Point3f lowerLeftCorner(-2.0, -1.0, -1.0);
    Point3f horizontal(4.0, 0.0, 0.0);
    Point3f vertical(0.0, 2.0, 0.0);
    Point3f origin(0.0, 0.0, 0.0);

    //================================================================================================================//
    // Start Rendering
    //================================================================================================================//
    int index = 0;
    for (int y = WINDOW_HEIGHT - 1; y >= 0; y--) {
       for (int x = 0; x < WINDOW_WIDTH; x++) {
         pixels[index] = Point2f(x, y);
         float u = (float)x / (float)WINDOW_WIDTH;
         float v = (float)y / (float)WINDOW_HEIGHT;

         Ray ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical));

         colors[index] = color(ray, scene);
         index++;
        }
     }

     MAWindow ma_window("########## ma3Renderer ##########", WINDOW_WIDTH, WINDOW_HEIGHT);
     ma_window.display(pixels,colors);


    //================================================================================================================//
    // Terminate glfw
    //================================================================================================================//
    glfwTerminate();

    //================================================================================================================//
    // release memory
    //================================================================================================================//
    delete[] pixels;
    delete[] colors;

    return 0;
}