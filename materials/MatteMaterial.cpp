//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <cmath>
#include <cstdlib>

#include "MatteMaterial.hpp"
#include "../core/Ray.hpp"

//====================================================================================================================//
// Sample random point in unit sphere TODO delete
//====================================================================================================================//
Vector3f randomUnitSphere() {
    Vector3f p;
    do {
        p = 2.0f * Vector3f(drand48(), drand48(), drand48()) - Vector3f(1.0f,1.0f,1.0f);
    } while((glm::length(p) * glm::length(p)) >= 1.0);

    return p;
}


Vector3f MatteMaterial::getAlbedo() const {
    return albedo;
}

void MatteMaterial::computeScatteringFunctions(SurfaceInteraction *isect) const {
    Point3f target = isect->position + isect->normal + randomUnitSphere();
    //isect->scatterRay = Ray(isect->position, target - isect->position); // TODO isect should not have scatterRay... need other way of storing it
}

bool MatteMaterial::computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const {
    Point3f target = isect->position + isect->normal + randomUnitSphere();
    scatterRay = Ray(isect->position, target - isect->position);
    return true;
}