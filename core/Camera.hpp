//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_CAMERA_HPP
#define MA3RENDERER_CAMERA_HPP

#include "Geometry.hpp"
#include "Ray.hpp"
#include "Film.hpp"
#include "Transform.hpp"

struct CameraSample {
    Point2f pFilms;
    Point2f pLens;
    float time;
};

class Camera {
public:
    // < Camera Interface 356 >
    Camera();
    Camera(Point3f lookFrom, Point3f lookAt, Vector3f vup, float vfov, float aspect, float aperture, Film *film); // vertical fov
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

    /**
     * This method is used to update camera parameters
     */
    virtual void updateCamera();
    // Setter methods
    void setOrigin(const Point3f &origin);

    void setLookAt(const Point3f &lookAt);

    void setVup(const Vector3f &vup);

    void setVfov(float vfov);

    void setAspect(float aspect);

    void setAperture(float aperture);

    void setFocusDist(float focusDist);

    const Point3f &getOrigin() const;

    const Point3f &getLookAt() const;

    const Vector3f &getVup() const;

    float getVfov() const;

    float getAspect() const;

    float getAperture() const;

    float getFocusDist() const;

    // < Camera public data >
    Transform cameraToWorld;
    const float shutterOpen, shutterClose;
    Film *film;
//    const Mediumm *medium;

    // Temporary .... according to Shirley
    Point3f origin, lookAt, lowerLeftCorner;
    Vector3f vup, horizontal, vertical;
    Vector3f u, v, w;
    float vfov, aspect, aperture, focusDist, lensRadius;
};


#endif //MA3RENDERER_CAMERA_HPP
