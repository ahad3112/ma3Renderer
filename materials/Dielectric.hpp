//
// Created by Muhammed Ahad on 2018-11-06.
//

#ifndef MA3RENDERER_DIELECTRIC_HPP
#define MA3RENDERER_DIELECTRIC_HPP


#include "../core/Material.hpp"

class Dielectric : public Material {
public:
    Dielectric(const Vector3f &albedo, float refractionIndex);

    void computeScatteringFunctions(SurfaceInteraction *isect) const override;

    bool computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatteredRay) const override;

    Vector3f getAlbedo() const override;

private:
    float refractionIndex;
};


#endif //MA3RENDERER_DIELECTRIC_HPP
