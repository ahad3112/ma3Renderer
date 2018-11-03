//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_CAMERA_HPP
#define MA3RENDERER_CAMERA_HPP

#include "Geometry.hpp"
#include "Ray.hpp"
#include "Film.hpp"
#include "Transform.hpp"

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
    Camera(Point3f lookFrom, Point3f lookAt, Vector3f vup, float vfov, float aspect, float aperture, float focusDist); // vertical fov
    virtual ~Camera();
    // TODO the following constructor p356 and methods
    Camera(float shutterOpen, float shutterClose, Film *film);

    Camera(const Transform &cameraToWorld, float shutterOpen, float shutterClose, Film *film);

    // TODO IMPLEMENT THE MEDIUM CLASS
    //Camera(Transform &cameraToWorld, float shutterOpen, float shutterClose, Film *film, const Medium *medium);


    virtual Ray generateRay(float ux, float vy) const;
    // TODO make it pure virtual later
    virtual float generateRay(const CameraSample &sample, Ray *ray) const;

    // TODO generateRayDifferential()

    // < Camera public data >
    Transform cameraToWorld;
    const float shutterOpen, shutterClose;
    Film *film;
//    const Mediumm *medium;

    // Temporary .... according to Shirley
    Point3f origin;
    Point3f lowerLeftCorner;
    Vector3f horizontal;
    Vector3f vertical;
    Vector3f u, v, w;
    float lensRadius;
};


#endif //MA3RENDERER_CAMERA_HPP
