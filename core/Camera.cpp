//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <iostream>
#include "Camera.hpp"

Camera::Camera() : shutterOpen(0.0f), shutterClose(0.0f) {
    lowerLeftCorner = Point3f(-2.0, -1.0, -1.0);
    horizontal      = Point3f(4.0, 0.0, 0.0);
    vertical        = Vector3f(0.0, 2.0, 0.0);
    origin          = Vector3f(0.0, 0.0, 0.0);
}

Camera::Camera(float shutterOpen, float shutterClose, Film *film)
                : shutterOpen(shutterOpen), shutterClose(shutterClose), film(film) {

}

Camera::~Camera() {

}


Ray Camera::generateRay(float u, float v) const {
    return Ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical));
}

float Camera::generateRay(const Camera::CameraSample &sample) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;

    return 1.0f;        // Return value simple camera
}