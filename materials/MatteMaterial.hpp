//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_MATTEMATERIAL_HPP
#define MA3RENDERER_MATTEMATERIAL_HPP

#include <iostream>
#include <memory>
#include "../core/Material.hpp"
#include "../core/Spectrum.hpp"

class MatteMaterial : public Material{
public:
    // <  MatteMaterial public methods 578>
    // TODO remove the default Material constructor
    MatteMaterial(const std::shared_ptr<Spectrum> &kd) : Material(), kd(kd) {

    }
    // Shirley
    MatteMaterial(const Vector3f &albedo) : Material(albedo) {}

    void computeScatteringFunctions(SurfaceInteraction *isect) const override;
    bool computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const override;
    Vector3f getAlbedo() const override;

private:
    // < MatteMaterial private data 578>
    std::shared_ptr<Spectrum> kd;

};


#endif //MA3RENDERER_MATTEMATERIAL_HPP
