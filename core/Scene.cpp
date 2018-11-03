//
// Created by Muhammed Ahad on 2018-10-28.
//

#include <iostream>
#include "Scene.hpp"


Scene::Scene(std::vector<const Primitive *> aggregate) : aggregate(aggregate) {
    // TODO Preprocess for lights
}

bool Scene::intersect(const Ray &ray, SurfaceInteraction *isect) const {
    bool hit = false;
    for (const auto prim : aggregate) {
        if(prim->intersect(ray, isect)) {
            hit = true;
        }
    }

    return hit;
}

bool Scene::intersectP(const Ray &ray) {
    bool hit = false;
    SurfaceInteraction isect;
    for (const auto prim : aggregate) {
        if(prim->intersect(ray, &isect)) {
            hit = true;
        }
    }

    return hit;
}

void Scene::addPrimitive(const Primitive *primitive) {
    aggregate.push_back(primitive);
}