//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_SPHERE_HPP
#define MA3RENDERER_SPHERE_HPP

#include "../core/shape.hpp"
#include "../core/geometry.hpp"
#include "../utility/maUtility.hpp"

class Sphere : public Shape{
public:
    // <Sphere public methods >
    Sphere(Point3f center, float radius);
    virtual bool intersect(const Ray &ray, float *tHit, SurfaceInteraction *isect) const override;
    /**
     * this method is used to compute the surface area of a shape in object space
     */
    virtual float area() const override;

private:
    // < Sphere private data >
    const float radius;
    const Point3f center;
};


#endif //MA3RENDERER_SPHERE_HPP
