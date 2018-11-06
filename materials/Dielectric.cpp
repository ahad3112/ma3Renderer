//
// Created by Muhammed Ahad on 2018-11-06.
//

#include <iostream>
#include "Dielectric.hpp"

Dielectric::Dielectric(const Vector3f &albedo, float refractionIndex) : Material(albedo), refractionIndex(refractionIndex){

}

void Dielectric::computeScatteringFunctions(SurfaceInteraction *isect) const {
    std::cout << __func__  << "Not implemented" << std::endl;
}

bool Dielectric::computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatteredRay) const {
    Vector3f outwardNormal;
    Vector3f reflected = reflect(ray.direction, isect->normal);
    float eta;
    Vector3f refracted;

    if(glm::dot(ray.direction, isect->normal) > 0.0f) {
        outwardNormal = -isect->normal;
        eta = refractionIndex;
    } else {
        outwardNormal = isect->normal;
        eta = 1.0f / refractionIndex;
    }

    if(refract(ray.direction, outwardNormal, eta, refracted)) {
        scatteredRay = Ray(isect->position, refracted);
    } else {
        scatteredRay = Ray(isect->position, reflected);
        return false;
    }

    return true;
}

Vector3f Dielectric::getAlbedo() const {
    return Vector3f();
}
