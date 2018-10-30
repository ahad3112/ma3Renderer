//
// Created by Muhammed Ahad on 2018-10-27.
//


#include <iostream>
#include "GeometricPrimitive.hpp"

GeometricPrimitive::GeometricPrimitive(const Shape *shape) : shape(shape){
}

GeometricPrimitive::GeometricPrimitive(const Shape *shape, const Material *material) : shape(shape), material(material) {

}

bool GeometricPrimitive::intersect(const Ray &ray, SurfaceInteraction *isect) const {
    float tHit = ray.tMax;
    //std::cout << "'checking: " <<tHit << std::endl;

    if(!shape->intersect(ray, &tHit, isect)){
        return false;
    }
    ray.tMax = tHit;
    isect->primitive = this;

    return true;
}


bool GeometricPrimitive::intersectP(const Ray &ray) const {
    std::cout << "GeometricPrimitive::intersectP(const Ray &ray) const, has not implemented yet..." << std::endl;

    return false;
}

const Material *GeometricPrimitive::getMaterial() const {
    return material;
}

void GeometricPrimitive::computeScatteringFunctions(SurfaceInteraction *isect) const {
    material->computeScatteringFunctions(isect);
}

bool GeometricPrimitive::computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const {
    return material->computeScatteringFunctions(isect, ray, scatterRay);
}