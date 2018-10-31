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

#define GAMMA_2_CORRECTION 0
#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 480
#define N_SAMPLE 2
#define MAX_DEPTH 2

// TODO : CLEAN UP OPENGL PART AND DESIGN HOW THE RENDER PROCEDURE WILL LOOK LIKE

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

//====================================================================================================================//
// display
//====================================================================================================================//
void display(GLFWwindow *window, Point2f *pixels, Vector3f *colors) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // sample drawings
        draw(WINDOW_WIDTH, WINDOW_HEIGHT, pixels, colors);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


int main(int argc, char *argv[]) {

    //================================================================================================================//
    // Checking Bound2 template
    //================================================================================================================//
//    Bounds2i bi(Point2i(100,90), Point2i(10,200));
//    std::cout << "Bounds2i: " << bi.pMin.x << std::endl;
//    std::cout << "Bounds2i: " << bi.pMin.y << std::endl;
//    std::cout << "Bounds2i: " << bi.pMax.x << std::endl;
//    std::cout << "Bounds2i: " << bi.pMax.y << std::endl;



    std::cout << "This is ##### ma3Renderer #####" << std::endl;

    //================================================================================================================//
    // Sample rendering
    //================================================================================================================//
    Point2f  *pixels = new Point2f[WINDOW_WIDTH * WINDOW_HEIGHT];
    Vector3f  *colors = new Point3f[WINDOW_WIDTH * WINDOW_HEIGHT];

    //================================================================================================================//
    // Camera
    //================================================================================================================//
    Camera camera;
    //================================================================================================================//
    // Scene
    //================================================================================================================//
    Sphere sphere1(Point3f(0.0f, 0.0f, -1.0f), 0.5f);
    Sphere sphere2(Point3f(0.0f, -100.5f, -1.0f), 100.0f);
    Sphere sphere3(Point3f(1.0f, 0.0f, -1.0f), 0.5f);
    Sphere sphere4(Point3f(-1.0f, 0.0f, -1.0f), 0.5f);


    MatteMaterial matte1(Vector3f(.8, .3, .3));
    MatteMaterial matte2(Vector3f(.8, .8, 0.0));
    Metal metal1(Vector3f(.8, .6, .2), 0.0);
    Metal metal2(Vector3f(.8, .8, .8), 0.0);


    GeometricPrimitive gprimitive1(&sphere1, &matte1);
    GeometricPrimitive gprimitive2(&sphere2, &matte2);
    GeometricPrimitive gprimitive3(&sphere3, &metal1);
    GeometricPrimitive gprimitive4(&sphere4, &metal2);




    Scene scene;
    scene.addPrimitive(&gprimitive1);
    scene.addPrimitive(&gprimitive2);
    scene.addPrimitive(&gprimitive3);
    scene.addPrimitive(&gprimitive4);



    //================================================================================================================//
    // Start Rendering
    //================================================================================================================//
//    int index = 0;
//    for (int y = WINDOW_HEIGHT - 1; y >= 0; y--) {
//       for (int x = 0; x < WINDOW_WIDTH; x++) {
//         pixels[index] = Point2f(x, y);
//         Vector3f tmpColor(0,0,0);
//         for(int ns = 0; ns < N_SAMPLE; ns++) {
//             float u = (float)(x + drand48()) / (float)WINDOW_WIDTH;
//             float v = (float)(y + drand48()) / (float)WINDOW_HEIGHT;
//             Ray ray = camera.generateRay(u, v);
//             tmpColor += color(ray, scene, 0);
//         }
//
//         if(GAMMA_2_CORRECTION) {
//             colors[index] = Vector3f(std::sqrt(tmpColor.x / (float)N_SAMPLE), std::sqrt(tmpColor.x / (float)N_SAMPLE), std::sqrt(tmpColor.x / (float)N_SAMPLE));
//         } else {
//             colors[index] = tmpColor / (float)N_SAMPLE;
//
//         }
//
//           index++;
//        }
//     }

    //================================================================================================================//
    // GLFW window and display
    //================================================================================================================//

    MAWindow ma_window("########## ma3Renderer ##########", WINDOW_WIDTH, WINDOW_HEIGHT);
     //ma_window.display(pixels,colors);
    draw(WINDOW_WIDTH, WINDOW_HEIGHT, pixels, colors);

    while (!glfwWindowShouldClose(ma_window.getWindow())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        int index = 0;
        for (int y = WINDOW_HEIGHT - 1; y >= 0; y--) {
            for (int x = 0; x < WINDOW_WIDTH; x++) {
                pixels[index] = Point2f(x, y);
                Vector3f tmpColor(0,0,0);
                for(int ns = 0; ns < N_SAMPLE; ns++) {
                    float u = (float)(x + drand48()) / (float)WINDOW_WIDTH;
                    float v = (float)(y + drand48()) / (float)WINDOW_HEIGHT;
                    Ray ray = camera.generateRay(u, v);
                    tmpColor += color(ray, scene, 0);
                }

                if(GAMMA_2_CORRECTION) {
                    colors[index] = Vector3f(std::sqrt(tmpColor.x / (float)N_SAMPLE), std::sqrt(tmpColor.x / (float)N_SAMPLE), std::sqrt(tmpColor.x / (float)N_SAMPLE));
                } else {
                    colors[index] = tmpColor / (float)N_SAMPLE;

                }
                index++;
            }
            // sample drawings
            draw(WINDOW_WIDTH, WINDOW_HEIGHT, pixels, colors);
            glDrawArrays(GL_POINTS, 0, WINDOW_WIDTH * WINDOW_HEIGHT);
            glfwSwapBuffers(ma_window.getWindow());
            glfwPollEvents();
        }
    }
    //display(ma_window.getWindow(), pixels, colors);

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