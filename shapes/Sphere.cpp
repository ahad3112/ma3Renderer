//
// Created by Muhammed Ahad on 2018-10-27.
//

#include <iostream>
#include <cmath>
#include "Sphere.hpp"


Sphere::Sphere(Point3f center, float radius) : center(center), radius(radius){}


bool Sphere::intersect(const Ray &ray, float *tHit, SurfaceInteraction *isect) const {
    Point3f oc = ray.origin - center;
    float a = glm::dot(ray.direction , ray.direction);
    float b = 2.0f * glm::dot(oc, ray.direction);
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4.0f * a * c;

    if(discriminant > 0.0f) {
        float t = (-b - std::sqrt(discriminant)) / (2.0f * a);
        if(t > MA_EPSILON && t < *tHit) {
            *tHit = t;
            isect->position = ray(*tHit);
            isect->normal = glm::normalize(isect->position - center);
            return true;
        }

        t = (-b + std::sqrt(discriminant)) / (2.0f * a);
        if(t > MA_EPSILON && t < *tHit) {
            *tHit = t;
            isect->position = ray(*tHit);
            isect->normal = glm::normalize(isect->position - center);
            return true;
        }
    }

    return false;
}


float Sphere::area() const {
    std::cerr << "Sphere::area() has not been implemented yet!!!!" << std::endl;
    return 0.0f;
}