//
// Created by Muhammed Ahad on 2018-11-15.
//

#ifndef MA3RENDERER_LAMBERTIANREFLECTION_HPP
#define MA3RENDERER_LAMBERTIANREFLECTION_HPP


#include "../core/BxDF.hpp"

class LambertianReflection : public BxDF{
public:
    // < LambertianReflection public methods 532 >
    // TODO Vectpr3f should be replaced by Spectrum
    LambertianReflection(const Spectrum &r);

    Spectrum f(const Vector3f &wi, const Vector3f &wo) const override;

    Spectrum rho(const Vector3f &wo, const Vector3f &wi, int nSamples, const Point2f *samples) const override;
    Spectrum rho(int nSamples, const Point2f *samples1, const Point2f *samples2) const override;

    // < Lambertian Reflection private data 532>
    const Spectrum r;
};


#endif //MA3RENDERER_LAMBERTIANREFLECTION_HPP
