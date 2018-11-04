//
// Created by Muhammed Ahad on 2018-10-30.
//

#include <iostream>
#include "Metal.hpp"


Metal::Metal(const Vector3f &albedo, float f) : Material(albedo){
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
    scatterRay = Ray(isect->position, reflected + fuzz * randomUnitSphere());


    return (glm::dot(scatterRay.direction, isect->normal) > 0);
}