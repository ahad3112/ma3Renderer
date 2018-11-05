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

Camera::Camera(Point3f lookFrom, Point3f lookAt, Vector3f vup, float vfov, float aspect, float aperture, Film *film)
              : origin(lookFrom), lookAt(lookAt), vup(vup), vfov(vfov), aspect(aspect), aperture(aperture), shutterOpen(0.0f),
              shutterClose(0.0f), film(film) {
    updateCamera();
}

Camera::Camera(float shutterOpen, float shutterClose, Film *film)
                : shutterOpen(shutterOpen), shutterClose(shutterClose), film(film) {

}


Camera::Camera(const Transform &cameraToWorld, float shutterOpen, float shutterClose, Film *film) : cameraToWorld(cameraToWorld),
                shutterOpen(shutterOpen), shutterClose(shutterClose), film(film){

}

//====================================================================================================================//
// Setter methods
//====================================================================================================================//
void Camera::setOrigin(const Point3f &origin) {
    Camera::origin = origin;
}

void Camera::setLookAt(const Point3f &lookAt) {
    Camera::lookAt = lookAt;
}

void Camera::setVup(const Vector3f &vup) {
    Camera::vup = vup;
}

void Camera::setVfov(float vfov) {
    Camera::vfov = vfov;
}

void Camera::setAspect(float aspect) {
    Camera::aspect = aspect;
}

void Camera::setAperture(float aperture) {
    Camera::aperture = aperture;
}

void Camera::setFocusDist(float focusDist) {
    Camera::focusDist = focusDist;
}

//====================================================================================================================//
// Getter methods
//====================================================================================================================//

const Point3f &Camera::getOrigin() const {
    return origin;
}

const Point3f &Camera::getLookAt() const {
    return lookAt;
}

const Vector3f &Camera::getVup() const {
    return vup;
}

float Camera::getVfov() const {
    return vfov;
}

float Camera::getAspect() const {
    return aspect;
}

float Camera::getAperture() const {
    return aperture;
}

float Camera::getFocusDist() const {
    return focusDist;
}

//====================================================================================================================//
// DESTRUCTOR
//====================================================================================================================//
Camera::~Camera() {

}


//====================================================================================================================//
// CLASS METHODS
//====================================================================================================================//

void Camera::updateCamera() {
    lensRadius = aperture / 2.0f;
    focusDist = glm::length(origin - lookAt);;
    float theta = (vfov * MA_PI) / 180.0f;
    float halfHeight = tan(theta / 2.0f);
    float halfWidth = aspect * halfHeight;
    w = glm::normalize(origin - lookAt);
    u = glm::normalize(glm::cross(vup, w));
    v = glm::cross(w,u);
    lowerLeftCorner = origin - halfWidth * focusDist * u - halfHeight * focusDist * v - focusDist * w;
    horizontal = 2.0f * halfWidth * focusDist * u;
    vertical = 2.0f * halfHeight * focusDist * v;
}

Ray Camera::generateRay(float ux, float vy) const {
    Vector3f rd = lensRadius * randomUnitSphere();
    Vector3f offset = u * rd.x + v * rd.y;
    return Ray(origin + offset, lowerLeftCorner + (ux * horizontal) + (vy * vertical) - origin - offset);
}

float Camera::generateRay(const CameraSample &sample, Ray *ray) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;

    return 1.0f;        // Return value simple camera
}