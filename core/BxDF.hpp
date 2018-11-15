//
// Created by Muhammed Ahad on 2018-11-15.
//

#ifndef MA3RENDERER_BXDF_HPP
#define MA3RENDERER_BXDF_HPP

#include "Geometry.hpp"

enum BxDFType {
    BSDF_REFLECTION   = 1 << 0,
    BSDF_TRANSMISSION = 1 << 1,
    BSDF_DIFFUSE      = 1 << 2,
    BSDF_GLOSSY       = 1 << 3,
    BSDF_SPECULAR     = 1 << 4,
    BSDF_ALL          = BSDF_DIFFUSE | BSDF_GLOSSY | BSDF_SPECULAR | BSDF_REFLECTION | BSDF_TRANSMISSION,
};

class BxDF {
public:
    // < BxDF public interface 513 >
    BxDF(BxDFType type) : type(type) {}
    bool matchesFlags(BxDFType t);

    // TODO Vector3f should be replace by Spectrum
    virtual Vector3f f(const Vector3f &wi, const Vector3f &wo) const = 0;
    virtual Vector3f sample_f(const Vector3f &wi, const Vector3f &wo, float pdf, BxDFType *sampledType = nullptr) const = 0;

    // < BxDF public data >
    const BxDFType type;

};


#endif //MA3RENDERER_BXDF_HPP
