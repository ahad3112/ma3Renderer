//
// Created by Muhammed Ahad on 2018-11-01.
//

#include "ProjectiveCamera.hpp"

//====================================================================================================================//
// CONSTRUCTOR
//====================================================================================================================//
ProjectiveCamera::ProjectiveCamera() {

}
ProjectiveCamera::ProjectiveCamera(const Transform &cameraToWorld, const Transform &cameraToScreen,
                                   const Bounds2f &screenWindow, float shutterOpen, float shutterClose,
                                   float lensRadius, float focalDist, Film *film)
                                   : Camera(cameraToWorld, shutterOpen, shutterClose, film), cameraToScreen(cameraToScreen){
    // TODO < Initialize depth of field parameters 374 >

    // Compute projective camera transformations
    screenToRaster = scale(Vector3f(film->fullResolution.x, film->fullResolution.y, 1.0f)) *
                     scale(Vector3f(1.0f / (screenWindow.pMax.x - screenWindow.pMin.x), 1.0f / (screenWindow.pMin.y - screenWindow.pMax.y), 1.0f)) *
                     translate(Vector3f(-screenWindow.pMin.x, -screenWindow.pMax.y, 0.0f));
    rasterToScreen = inverse(screenToRaster);
    rasterToCamera = inverse(cameraToScreen) * rasterToScreen;

}

//====================================================================================================================//
// DESTRUCTOR
//====================================================================================================================//
ProjectiveCamera::~ProjectiveCamera() {

}

//====================================================================================================================//
// CLASS METHODS
//====================================================================================================================//
Ray ProjectiveCamera::generateRay(float u, float v) const {
    return Camera::generateRay(u, v);
}



float ProjectiveCamera::generateRay(const CameraSample &sample, Ray *ray) const {
    return Camera::generateRay(sample,ray);
}

