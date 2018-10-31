//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <cmath>
#include <cstdlib>

#include "MatteMaterial.hpp"
#include "../core/Ray.hpp"


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