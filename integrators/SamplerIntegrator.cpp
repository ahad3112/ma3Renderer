//
// Created by Muhammed Ahad on 2018-10-29.
//

#include "SamplerIntegrator.hpp"
#include "../visualization/MA_window.hpp"


#define GAMMA_2_CORRECTION 0
#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 480
#define N_SAMPLE 1
#define MAX_DEPTH 1

SamplerIntegrator::SamplerIntegrator(Camera *camera) : camera(camera) {

}


void drawM(int width, int height, Point2f *pixels, Vector3f *colors) {

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

void SamplerIntegrator::Render(const Scene &scene) {
    // Preprocess

    // TODO < Render image tiles in parallel 27 >
        // TODO <Compute number of tiles to use for parallel rendering 28 >


    // Simpler version
    // < Loop over pixels in the film >


    // CURRENTLY WINDOW_HEIGHT AND WIDTH IS HARDCODED
//    int SCREEN_WIDTH = camera->film->fullResolution.x;
//    int SCREEN_HEIGHT = camera->film->fullResolution.y;

    //================================================================================================================//
    // Sample rendering
    //================================================================================================================//
    Point2f  *pixels = new Point2f[WINDOW_WIDTH * WINDOW_HEIGHT];
    Vector3f  *colors = new Point3f[WINDOW_WIDTH * WINDOW_HEIGHT];

    MAWindow ma_window("########## ma3Renderer ##########", WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!glfwWindowShouldClose(ma_window.getWindow())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        int index = 0;
        for (int y = WINDOW_HEIGHT - 1; y >= 0; y--) {
            for (int x = 0; x < WINDOW_WIDTH; x++) {
                pixels[index] = Point2f(x, y);
                Vector3f L(0,0,0);
                for(int ns = 0; ns < N_SAMPLE; ns++) {
                    float u = (float)(x + drand48()) / (float)WINDOW_WIDTH;
                    float v = (float)(y + drand48()) / (float)WINDOW_HEIGHT;
                    Ray ray = camera->generateRay(u, v);
                    L += Li(ray, scene, 0);
                }

                if(GAMMA_2_CORRECTION) {
                    colors[index] = Vector3f(std::sqrt(L.x / (float)N_SAMPLE), std::sqrt(L.x / (float)N_SAMPLE), std::sqrt(L.x / (float)N_SAMPLE));
                } else {
                    colors[index] = L / (float)N_SAMPLE;

                }
                index++;
            }
            // Display TODO SHOULD MOVE TO THE MA_WINDOW ::
            drawM(WINDOW_WIDTH, WINDOW_HEIGHT, pixels, colors);
            glDrawArrays(GL_POINTS, 0, WINDOW_WIDTH * WINDOW_HEIGHT);
            glfwSwapBuffers(ma_window.getWindow());
            glfwPollEvents();
        }
    }

    //================================================================================================================//
    // Terminate glfw
    //================================================================================================================//
    glfwTerminate();


    // < Save final image after rendering 32 >
}

Vector3f SamplerIntegrator::Li(const Ray &ray, const Scene &scene, int depth) const {
    SurfaceInteraction isect;
    if (scene.intersect(ray,&isect)) {
        Ray scattered;
        if(depth < MAX_DEPTH && isect.computeScatteringFunctions(ray, scattered)) {
            return (isect.primitive->getMaterial()->getAlbedo()) * Li(scattered, scene, depth++);

        } else {
            return Vector3f(0, 0, 0);
        }
    } else {
        Vector3f unitDirection = glm::normalize(ray.direction);
        float t = 0.5f * (unitDirection.y + 1.0f);
        return (1.0f - t) * Vector3f(1.0f, 1.0f, 1.0f) + t * Vector3f(0.5f, 0.7f, 1.0f);
    }

    // TODO UPDATE THIS FUNCTION BASED ON PBRT P33 (WHITTED INTEGRATOR)
}
