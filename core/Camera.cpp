//
// Created by Muhammed Ahad on 2018-10-29.
//

#include "Camera.hpp"

Camera::Camera() {
    lowerLeftCorner = Point3f(-2.0, -1.0, -1.0);
    horizontal      = Point3f(4.0, 0.0, 0.0);
    vertical        = Vector3f(0.0, 2.0, 0.0);
    origin          = Vector3f(0.0, 0.0, 0.0);
}

Ray Camera::generateRay(float u, float v) const {
    return Ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical));
}