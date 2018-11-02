//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <iostream>
#include <cmath>
#include "Camera.hpp"

Camera::Camera() : shutterOpen(0.0f), shutterClose(0.0f) {
    lowerLeftCorner = Point3f(-2.0, -1.0, -1.0);
    horizontal      = Point3f(4.0, 0.0, 0.0);
    vertical        = Vector3f(0.0, 2.0, 0.0);
    origin          = Vector3f(0.0, 0.0, 0.0);
}

Camera::Camera(Point3f lookFrom, Point3f lookAt, Vector3f vup, float vfov, float aspect) : shutterOpen(0.0f), shutterClose(0.0f) {
    Vector3f u, v, w;
    float theta = (vfov * MA_PI) / 180.0f;
    float halfHeight = tan(theta / 2.0f);
    float halfWidth = aspect * halfHeight;
    origin = lookFrom;
    w = glm::normalize(lookFrom - lookAt);
    u = glm::normalize(glm::cross(vup, w));
    v = glm::cross(w,u);
//    lowerLeftCorner = Point3f(-halfWidth, -halfHeight, -1.0f);
    lowerLeftCorner = origin - halfWidth * u - halfHeight * v - w;
//    horizontal = Vector3f(2.0f * halfWidth , 0.0f, 0.0f);
//    vertical = Vector3f(0.0f, 2.0f * halfHeight, 0.0f);

    horizontal = 2.0f * halfWidth * u;
    vertical = 2.0f * halfHeight * v;

}

Camera::Camera(float shutterOpen, float shutterClose, Film *film)
                : shutterOpen(shutterOpen), shutterClose(shutterClose), film(film) {

}

Camera::~Camera() {

}


Ray Camera::generateRay(float u, float v) const {
    return Ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical) - origin);
}

float Camera::generateRay(const Camera::CameraSample &sample) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;

    return 1.0f;        // Return value simple camera
}