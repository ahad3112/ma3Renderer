//
// Created by Muhammed Ahad on 2018-10-28.
//

#ifndef MA3RENDERER_PRIMITIVE_HPP
#define MA3RENDERER_PRIMITIVE_HPP


#include "ray.hpp"
#include "interaction.hpp"


class Primitive {
public:
    Primitive() {}
    virtual bool intersect(const Ray &ray, SurfaceInteraction *isect) const = 0;
    virtual bool intersectP(const Ray &ray) const = 0;
//
//    virtual const AreaLight *getAreaLight() const = 0;
//    virtual const Material *getMaterial() const = 0;

    // TODO computeScatteringFunctions p250

};


#endif //MA3RENDERER_PRIMITIVE_HPP
