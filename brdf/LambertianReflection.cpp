//
// Created by Muhammed Ahad on 2018-11-15.
//

#include "LambertianReflection.hpp"
#include "../utility/MA_utility.hpp"

//====================================================================================================================//
// Class methods
//====================================================================================================================//

LambertianReflection::LambertianReflection(const Spectrum &r) : BxDF(BxDFType(BSDF_REFLECTION | BSDF_DIFFUSE)), r(r) {

}

Spectrum LambertianReflection::f(const Vector3f &wo, const Vector3f &wi) const {
    return r * Inv_MA_PI;
}


Spectrum LambertianReflection::rho(int nSamples, const Point2f *samples1, const Point2f *samples2) const {
    return r;
}


Spectrum LambertianReflection::rho(const Vector3f &wo, const Vector3f &wi, int nSamples,
                                   const Point2f *samples) const {
    return r;
}