//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <iostream>
#include <cmath>
#include "Camera.hpp"


//====================================================================================================================//
// CONSTRUCTOR
//====================================================================================================================//
Camera::Camera() : shutterOpen(0.0f), shutterClose(0.0f) {
    lowerLeftCorner = Point3f(-2.0, -1.0, -1.0);
    horizontal      = Point3f(4.0, 0.0, 0.0);
    vertical        = Vector3f(0.0, 2.0, 0.0);
    origin          = Vector3f(0.0, 0.0, 0.0);
}

Camera::Camera(Point3f lookFrom, Point3f lookAt, Vector3f vup, float vfov, float aspect, float aperture, float focusDist)
              : shutterOpen(0.0f), shutterClose(0.0f) {
    lensRadius = aperture / 2.0f;
    float theta = (vfov * MA_PI) / 180.0f;
    float halfHeight = tan(theta / 2.0f);
    float halfWidth = aspect * halfHeight;
    origin = lookFrom;
    w = glm::normalize(lookFrom - lookAt);
    u = glm::normalize(glm::cross(vup, w));
    v = glm::cross(w,u);
    lowerLeftCorner = origin - halfWidth * focusDist * u - halfHeight * focusDist * v - focusDist * w;
    horizontal = 2.0f * halfWidth * focusDist * u;
    vertical = 2.0f * halfHeight * focusDist * v;

}

Camera::Camera(float shutterOpen, float shutterClose, Film *film)
                : shutterOpen(shutterOpen), shutterClose(shutterClose), film(film) {

}


Camera::Camera(const Transform &cameraToWorld, float shutterOpen, float shutterClose, Film *film) : cameraToWorld(cameraToWorld),
                shutterOpen(shutterOpen), shutterClose(shutterClose), film(film){

}

//====================================================================================================================//
// DESTRUCTOR
//====================================================================================================================//
Camera::~Camera() {

}


//====================================================================================================================//
// CLASS METHODS
//====================================================================================================================//
Ray Camera::generateRay(float ux, float vy) const {
    Vector3f rd = lensRadius * randomUnitSphere();
    Vector3f offset = u * rd.x + v * rd.y;
    return Ray(origin + offset, lowerLeftCorner + (ux * horizontal) + (vy * vertical) - origin - offset);
}

float Camera::generateRay(const Camera::CameraSample &sample, Ray *ray) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;

    return 1.0f;        // Return value simple camera
}