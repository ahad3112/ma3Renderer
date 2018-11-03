//
// Created by Muhammed Ahad on 2018-11-03.
//

#ifndef MA3RENDERER_PERSPECTIVECAMERA_HPP
#define MA3RENDERER_PERSPECTIVECAMERA_HPP


#include "../core/Transform.hpp"
#include "ProjectiveCamera.hpp"

class PerspectiveCamera : public ProjectiveCamera {
public:
    PerspectiveCamera();
    PerspectiveCamera(const Transform &cameraToWorld, const Bounds2f &screenWindow, float shutterOpen, float shutterClose,
                      float lensRadius, float focalDist, float fov, Film *film);
    ~PerspectiveCamera();


};


#endif //MA3RENDERER_PERSPECTIVECAMERA_HPP
