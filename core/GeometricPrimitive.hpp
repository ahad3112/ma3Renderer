//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_GEOMETRICPRIMITIVE_HPP
#define MA3RENDERER_GEOMETRICPRIMITIVE_HPP

#include <memory>
#include "Primitive.hpp"
#include "shape.hpp"
#include "Material.hpp"

class GeometricPrimitive : public Primitive {
public:
    // < GeometricPrimitive public methods >
    GeometricPrimitive() {}
    GeometricPrimitive(const Shape *shape);
    GeometricPrimitive(const Shape *shape, const Material *material);
    virtual bool intersect(const Ray &ray, SurfaceInteraction *isect) const  override;
    virtual bool intersectP(const Ray &ray) const  override;
    void computeScatteringFunctions(SurfaceInteraction *isect) const override;

private:
    // < GeometricPrimitive private data 256>
    // TODO THINK ABOUT shared_ptr
    const Shape *shape;
    const Material *material;
    //TODO implement the following
//    std::shared_ptr<AreaLight> areaLight;
//    MediumInterface mediumInterface;


};


#endif //MA3RENDERER_GEOMETRICPRIMITIVE_HPP
