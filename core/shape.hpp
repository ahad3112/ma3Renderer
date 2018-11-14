//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_SHAPE_HPP
#define MA3RENDERER_SHAPE_HPP

#include "Ray.hpp"
#include "Interaction.hpp"
#include "Transform.hpp"

class Shape {
public:
    // < Shape Interface 125>
    Shape() : reverseOrientation(false), transformSwapsHandedness(false) {}
    Shape(const Transform *objectToWorld, const Transform *worldToWorld, bool reverseOrientation);
    virtual bool intersect(const Ray &ray, float *tHit, SurfaceInteraction *isect) const = 0;
    /**
     * this method is used to compute the surface area of a shape in object space
     */
    virtual float area() const = 0;

    // < Shape Public Data 124>
    const Transform *objectToWorld = nullptr, *worldToObject = nullptr;
    const bool reverseOrientation;
    const bool transformSwapsHandedness;
};

#endif //MA3RENDERER_SHAPE_HPP
