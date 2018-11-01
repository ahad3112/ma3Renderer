//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_CAMERA_HPP
#define MA3RENDERER_CAMERA_HPP

#include "Geometry.hpp"
#include "Ray.hpp"
#include "Film.hpp"

class Camera {
protected:
    struct CameraSample {
        Point2f pFilms;
        Point2f pLens;
        float time;
    };
public:
    // < Camera Interface 356 >
    Camera();
    virtual ~Camera();
    virtual Ray generateRay(float u, float v) const;
    // TODO the following constructor p356 and methods
    Camera(float shutterOpen, float shutterClose, Film *film);

    //Camera(const AnimatedTransform &cameraToWorld, float shutterOpen, float shutterClose, Film *film, const Medium *medium);


    // TODO make it pure virtual later
    virtual float generateRay(const CameraSample &sample) const;

    // TODO generateRayDifferential()

    // < Camera public data >
//    AnimatedTransform cameraToWorld;
    const float shutterOpen, shutterClose;
    Film *film;
//    const Mediumm *medium;

    // Temporary .... according to Shirley
    Point3f origin;
    Point3f lowerLeftCorner;
    Vector3f horizontal;
    Vector3f vertical;
};


#endif //MA3RENDERER_CAMERA_HPP
