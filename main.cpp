#include <iostream>


#include "core/geometry.hpp"
#include "visualization/ma_window.hpp"
#include "core/ray.hpp"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 620

//====================================================================================================================//
// Sample color function for starting the ray tracer
//====================================================================================================================//
Vector3f color(const Ray &ray) {
    Vector3f unitDirection = glm::normalize(ray.d);
    float t = 0.5f * (unitDirection.y + 1.0f);
    return (1.0f - t) * Vector3f(1.0f, 1.0f, 1.0f) + t * Vector3f(0.5f, 0.7f, 1.0f);
}


int main(int argc, char *argv[]) {
    std::cout << "This is ##### ma3Renderer #####" << std::endl;

    //================================================================================================================//
    //Create and check window for visualization
    //================================================================================================================//
    Point2f  *pixels = new Point2f[WINDOW_WIDTH * WINDOW_HEIGHT];
    Vector3f  *colors = new Point3f[WINDOW_WIDTH * WINDOW_HEIGHT];


    Point3f lowerLeftCorner(-2.0, -1.0, -1.0);
    Point3f horizontal(4.0, 0.0, 0.0);
    Point3f vertical(0.0, 2.0, 0.0);
    Point3f origin(0.0, 0.0, 0.0);

    int index = 0;
    for (int y = WINDOW_HEIGHT - 1; y >= 0; y--) {
       for (int x = 0; x < WINDOW_WIDTH; x++) {
         pixels[index] = Point2f(x, y);


         float u = (float)x / (float)WINDOW_WIDTH;
         float v = (float)y / (float)WINDOW_HEIGHT;
         Ray ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
         colors[index] = color(ray);
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