//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_SHAPE_HPP
#define MA3RENDERER_SHAPE_HPP

#include "Ray.hpp"
#include "Interaction.hpp"

class Shape {
public:
    // < Shape Interface 125>
    Shape() {}
    virtual bool intersect(const Ray &ray, float *tHit, SurfaceInteraction *isect) const = 0;
    /**
     * this method is used to compute the surface area of a shape in object space
     */
    virtual float area() const = 0;

    // < Shape Public Data 124>
};

#endif //MA3RENDERER_SHAPE_HPP
