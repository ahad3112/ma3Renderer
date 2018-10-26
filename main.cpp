#include <iostream>


#include "core/geometry.hpp"
#include "visualization/ma_window.hpp"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 620



int main(int argc, char *argv[]) {
    std::cout << "This is ## ma3Renderer ##" << std::endl;

    //==========================================================================//
    //Create and check window for visualization
    //==========================================================================//
    Point2f  *pixels = new Point2f[WINDOW_WIDTH * WINDOW_HEIGHT];
    Point3f  *colors = new Point3f[WINDOW_WIDTH * WINDOW_HEIGHT];


    int index = 0;
    for (int y = WINDOW_HEIGHT - 1; y >= 0; y--) {
       for (int x = 0; x < WINDOW_WIDTH; x++) {
         pixels[index] = Point2f(x, y);
         float r = (float)x / (float)WINDOW_WIDTH;
         float g = (float)y / (float)WINDOW_HEIGHT;
         float b = .2f;
         colors[index] = Point3f(r,g,b);
         index++;
        }
     }

     MAWindow ma_window("########## ma3Renderer ##########", WINDOW_WIDTH, WINDOW_HEIGHT);
     ma_window.display(pixels,colors);


    //==========================================================================//
    // Terminate glfw
    //==========================================================================//
    glfwTerminate();

    //==========================================================================//
    // release memory
    //==========================================================================//
    delete[] pixels;
    delete[] colors;

    return 0;
}