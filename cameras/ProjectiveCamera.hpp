//
// Created by Muhammed Ahad on 2018-11-01.
//

#ifndef MA3RENDERER_PROJECTIVECAMERA_HPP
#define MA3RENDERER_PROJECTIVECAMERA_HPP


#include "../core/Camera.hpp"

class ProjectiveCamera : public Camera{
public:
    // < ProjectiveCamera Public methods >
    ProjectiveCamera();
    ~ProjectiveCamera();
    ProjectiveCamera(const Transform &cameraToWorld, const Transform &cameraToScreen, const Bounds2f &screenWindow,
            float shutterOpen, float shutterClose, float lensRadius, float focalDist,  Film *film);
    // TODO IMPLEMENT Medium Class later
//    ProjectiveCamera(const Transform &cameraToWorld, const Transform &cameraToScreen, const Bounds2f &screenWindow,
//                     float shutterOpen, float shutterClose, float lensRadius, float focalDist,  Film *film, const Medium *medium);
    ProjectiveCamera(Point3f lookFrom, Point3f lookAt, Vector3f vup, float vfov, float aspect, float aperture,
                     float focusDist);

    Ray generateRay(float u, float v) const override;

    float generateRay(const CameraSample &sample, Ray *ray) const override;

protected:
    // < ProjectiveCamera Protected Data >
    Transform cameraToScreen, rasterToCamera;
    Transform screenToRaster, rasterToScreen;
};


#endif //MA3RENDERER_PROJECTIVECAMERA_HPP
