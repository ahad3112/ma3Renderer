//
// Created by Muhammed Ahad on 2018-11-03.
//

#include "PerspectiveCamera.hpp"


//====================================================================================================================//
// CONSTRUCTOR
//====================================================================================================================//
PerspectiveCamera::PerspectiveCamera() {

}

PerspectiveCamera::PerspectiveCamera(const Transform &cameraToWorld, const Bounds2f &screenWindow, float shutterOpen,
                                     float shutterClose, float lensRadius, float focalDist, float fov, Film *film)
                                     : ProjectiveCamera(cameraToWorld, perspective(fov, -.01f, -1000.0f),
                                                        screenWindow, shutterOpen, shutterClose, lensRadius, focalDist, film){
    // < Compute differential changes in origin for perspective camera rays 367 >
    // TODO
    dxCamera = rasterToCamera(Point3f(1.0f, 0.0f, 0.0f)) - rasterToCamera(Point3f(0.0f, 0.0f, 0.0f));
    dyCamera = rasterToCamera(Point3f(0.0f, 1.0f, 0.0f)) - rasterToCamera(Point3f(0.0f, 0.0f, 0.0f));

    // < Compute image plane bounds at z = 1 for PerspectiveCamera 951>
    // TODO DON'T NEED TO THINK ABOUT IT
    Point2i resolution = film->fullResolution;
    Point3f pMin = rasterToCamera(Point3f(0.0f, 0.0f, 0.0f));
    Point3f pMax = rasterToCamera(Point3f(resolution.x, resolution.y, 0.0f));
    pMin /= pMin.z;
    pMax /= pMax.z;
    A = std::abs((pMax.x - pMin.x) * (pMax.y - pMin.y));

}
//====================================================================================================================//
// DESTRUCTOR
//====================================================================================================================//

PerspectiveCamera::~PerspectiveCamera() {

}
//====================================================================================================================//
// CLASS METHODS
//====================================================================================================================//

Ray PerspectiveCamera::generateRay(float u, float v) const {
    return ProjectiveCamera::generateRay(u, v);
}

float PerspectiveCamera::generateRay(const CameraSample &sample, Ray *ray) const {
    // < compute raster and camera sample positions 364 >
    Point3f pFilm = Point3f(sample.pFilms.x, sample.pFilms.y, 0.0f);
    Point3f pCamera = rasterToCamera(pFilm);

//    *ray = Ray(Point3f(0.0f, 0.0f, 0.0f), glm::normalize(Vector3f(pCamera.x, pCamera.y, pCamera.z)));

    *ray = Ray(cameraToWorld(Point3f(0.0f, 0.0f, 0.0f)), cameraToWorld(glm::normalize(Vector3f(pCamera.x, pCamera.y, pCamera.z))));

//    std::cout << ray->direction.x << " " << ray->direction.y << " " << ray->direction.z << std::endl;



    // < Modify ray for depth of field >
    return 1.0f;
}
