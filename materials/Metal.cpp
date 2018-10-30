//
// Created by Muhammed Ahad on 2018-10-30.
//

#include <iostream>
#include "Metal.hpp"


//====================================================================================================================//
// Sample random point in unit sphere TODO delete
//====================================================================================================================//
Vector3f randomUnitSphereMet() {
    Vector3f p;
    do {
        p = 2.0f * Vector3f(drand48(), drand48(), drand48()) - Vector3f(1.0f,1.0f,1.0f);
    } while((glm::length(p) * glm::length(p)) >= 1.0);

    return p;
}

Metal::Metal(const Vector3f &albedo, float f) : albedo(albedo){
    if(f < 1.0) {
        fuzz = f;
    } else {
        fuzz = 1.0f;
    }
}

Vector3f Metal::getAlbedo() const {
    return albedo;
}

void Metal::computeScatteringFunctions(SurfaceInteraction *isect) const {
    std::cout << __func__  << "Not implemented" << std::endl;
}

bool Metal::computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const {
    Vector3f reflected = glm::reflect(glm::normalize(ray.direction), isect->normal);
    scatterRay = Ray(isect->position, reflected + fuzz * randomUnitSphereMet());


    return (glm::dot(scatterRay.direction, isect->normal) > 0);
}