//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_CAMERA_HPP
#define MA3RENDERER_CAMERA_HPP

#include "geometry.hpp"
#include "ray.hpp"

class Camera {
public:
    // < Camera Interface 356 >
    Camera();
    Ray generateRay(float u, float v) const;
    // TODO the following constructor p356 and methods
    //Camera(const AnimatedTransform &cameraToWorld, float shutterOpen, float shutterClose, Film *film, const Medium *medium);

    //virtual float generateRay(const CameraSample &sample) const = 0;

    // < Camera public data >
//    AnimatedTransform cameraToWorld;
//    const float shutterOpen, shutterClose;
//    Film *film;
//    const Mediumm *medium;

    // Temporary .... according to Shirley
    Point3f origin;
    Point3f lowerLeftCorner;
    Vector3f horizontal;
    Vector3f vertical;
};


#endif //MA3RENDERER_CAMERA_HPP
