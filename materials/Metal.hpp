//
// Created by Muhammed Ahad on 2018-10-30.
//

#ifndef MA3RENDERER_METAL_HPP
#define MA3RENDERER_METAL_HPP


#include "../core/Material.hpp"

class Metal : public Material {
public:
    Metal(const Vector3f &albedo, float f);

    void computeScatteringFunctions(SurfaceInteraction *isect) const override;

    bool computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const override;

    Vector3f getAlbedo() const override;

private:

    float fuzz;
};


#endif //MA3RENDERER_METAL_HPP
