//
// Created by Muhammed Ahad on 2018-11-06.
//

#include <iostream>
#include "Dielectric.hpp"

// TODO Looks like Dielectric is not working

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
    float reflectProb, cosine;

    if(glm::dot(ray.direction, isect->normal) > 0.0f) {
        outwardNormal = -isect->normal;
        eta = refractionIndex;
        //cosine = refractionIndex * glm::dot(ray.direction, isect->normal) / glm::length(ray.direction);
        cosine = dot(ray.direction, isect->normal) / glm::length(ray.direction);
        cosine = std::sqrt(1.0f - refractionIndex * refractionIndex * (1.0f-cosine * cosine));
    } else {
        outwardNormal = isect->normal;
        eta = 1.0f / refractionIndex;
        cosine = -glm::dot(ray.direction, isect->normal) / glm::length(ray.direction);
    }

    if(refract(ray.direction, outwardNormal, eta, refracted)) {
        reflectProb = schlick(cosine, refractionIndex);
    } else {
        reflectProb = 1.0f;
    }

    if(drand48() > reflectProb) {
        scatteredRay = Ray(isect->position, reflected);
    } else {
        scatteredRay = Ray(isect->position, refracted);
    }

    return true;
}

Vector3f Dielectric::getAlbedo() const {
    return albedo;
}
