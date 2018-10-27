//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_GEOMETRICPRIMITIVE_HPP
#define MA3RENDERER_GEOMETRICPRIMITIVE_HPP

#include <memory>
#include "Primitive.hpp"
#include "shape.hpp"

class GeometricPrimitive : public Primitive {
public:
    // < GeometricPrimitive public methods >
    GeometricPrimitive() {}
    GeometricPrimitive(const Shape *shape);
    virtual bool intersect(const Ray &ray, SurfaceInteraction *isect) const  override;
    virtual bool intersect(const Ray &ray, float *t, SurfaceInteraction *isect) const override; // THIS IS FOR CHECKING ONLY TODO :: DELETE
    virtual bool intersectP(const Ray &ray) const  override;

private:
    // < GeometricPrimitive private data 256>
    // TODO THINK ABOUT shared_ptr
    const Shape *shape;
    //TODO implement the following
//    std::shared_ptr<Material> material;
//    std::shared_ptr<AreaLight> areaLight;
//    MediumInterface mediumInterface;


};


#endif //MA3RENDERER_GEOMETRICPRIMITIVE_HPP
