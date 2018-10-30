//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_MATTEMATERIAL_HPP
#define MA3RENDERER_MATTEMATERIAL_HPP


#include "../core/Material.hpp"

class MatteMaterial : public Material{
public:
    // <  MatteMaterial public methods 578>
    MatteMaterial() {}
    MatteMaterial(const Vector3f &albedo) : albedo(albedo) {}

    void computeScatteringFunctions(SurfaceInteraction *isect) const override;
    bool computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const override;
    Vector3f getAlbedo() const override;

private:
    // Based on shirley
    Vector3f albedo;
    // < MatteMaterial private data 578>

};


#endif //MA3RENDERER_MATTEMATERIAL_HPP
