//
// Created by Muhammed Ahad on 2018-10-29.
//

#include "SamplerIntegrator.hpp"
#include "../visualization/MA_window.hpp"


#define GAMMA_2_CORRECTION 0
#define A 1.0f
#define GAMMA 0.5f
#define N_SAMPLE 50

SamplerIntegrator::SamplerIntegrator(int maxDepth, MAWindow *ma_window, Camera *camera) :
ma_window(ma_window), camera(camera), maxDepth(maxDepth) {

}

void SamplerIntegrator::Render(const Scene &scene) {
    // Preprocess

    // TODO < Render image tiles in parallel 27 >
        // TODO <Compute number of tiles to use for parallel rendering 28 >


    // Simpler version
    // < Loop over pixels in the film >


    // CURRENTLY WINDOW_HEIGHT AND WIDTH IS HARDCODED
    int SCREEN_WIDTH = camera->film->fullResolution.x;
    int SCREEN_HEIGHT = camera->film->fullResolution.y;

    //================================================================================================================//
    // Sample rendering
    //================================================================================================================//
    Point2i  *pixels  = (camera->film)->pixels;
    Vector3f  *colors = (camera->film)->colors;

    //================================================================================================================//
    // Register the buffer to window for display
    //================================================================================================================//
    ma_window->registerBuffer(pixels, colors);

    // TODO SHOULD GET THIS SAMPLE FROM Sampler class
    CameraSample cameraSample;

    while (!glfwWindowShouldClose(ma_window->getWindow())) {
        if (ma_window->cameraSettingChanged) {
            camera->updateCamera();
            ma_window->cameraSettingChanged = false;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        int index = 0;
        for (int y = (camera->film)->croppedPixelBounds.pMax.y - 1; y >= (camera->film)->croppedPixelBounds.pMin.y; y--) {
            for (int x = (camera->film)->croppedPixelBounds.pMin.x; x < (camera->film)->croppedPixelBounds.pMax.x; x++) {
                pixels[index] = Point2i(x, y);
                Vector3f L(0,0,0);
                for(int ns = 0; ns < N_SAMPLE; ns++) {
                    float u = (float)(x + drand48()) / (float)SCREEN_WIDTH;
                    float v = (float)(y + drand48()) / (float)SCREEN_HEIGHT;
                    Ray ray;
                    //ray = camera->generateRay(u, v);

                    // Create camera sample

                    cameraSample.pFilms = Point2f((float)(x + drand48()), (float)(y + drand48()));

                    // Create Ray using the Perspective Camera
                    float weight = camera->generateRay(cameraSample,&ray);

                    L += Li(ray, scene);
                }

                if(GAMMA_2_CORRECTION) {
                    colors[index] = Vector3f(A * std::pow(L.x / (float)N_SAMPLE, GAMMA), std::pow(L.x / (float)N_SAMPLE, GAMMA), std::pow(L.x / (float)N_SAMPLE, GAMMA));
                    //colors[index] = Vector3f(std::sqrt(L.x / (float)N_SAMPLE), std::sqrt(L.x / (float)N_SAMPLE), std::sqrt(L.x / (float)N_SAMPLE));
                } else {
                    colors[index] = L / (float)N_SAMPLE;

                }
                index++;
            }

            ma_window->display();
        }
    }

    // < Save final image after rendering 32 >
}

Vector3f SamplerIntegrator::Li(const Ray &ray, const Scene &scene, int depth) const {
    SurfaceInteraction isect;
//    if (scene.intersect(ray,&isect)) {
//        Ray scattered;
//        if(depth < maxDepth && isect.computeScatteringFunctions(ray, scattered)) {
//            return (isect.primitive->getMaterial()->getAlbedo()) * Li(scattered, scene, depth++);
//
//        } else {
//            return Vector3f(0, 0, 0);
//        }
//    } else {
//        Vector3f unitDirection = glm::normalize(ray.direction);
//        float t = 0.5f * (unitDirection.y + 1.0f);
//        return (1.0f - t) * Vector3f(1.0f, 1.0f, 1.0f) + t * Vector3f(0.5f, 0.7f, 1.0f);
//    }

    // TODO UPDATE THIS FUNCTION BASED ON PBRT P33 (WHITTED INTEGRATOR)
    //Spectrum L(0.0f);
    // < Find the closest intersection or return the background color >
    if(!scene.intersect(ray, &isect)) {
        Vector3f unitDirection = glm::normalize(ray.direction);
        float t = 0.5f * (unitDirection.y + 1.0f);
        return (1.0f - t) * Vector3f(1.0f, 1.0f, 1.0f) + t * Vector3f(0.5f, 0.7f, 1.0f);
    }

    // compute emitted and reflected light ar ray intersection point
    Ray scattered;
    if (depth < maxDepth && isect.computeScatteringFunctions(ray, scattered)) {
        return (isect.primitive->getMaterial()->getAlbedo()) * Li(scattered, scene, depth++);
    } else {
        return Vector3f(0, 0, 0);
    }

}
