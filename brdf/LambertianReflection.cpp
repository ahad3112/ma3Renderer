//
// Created by Muhammed Ahad on 2018-11-15.
//

#include "LambertianReflection.hpp"
#include "../utility/MA_utility.hpp"

//====================================================================================================================//
// Class methods
//====================================================================================================================//

LambertianReflection::LambertianReflection(const Vector3f &r) : BxDF(BxDFType(BSDF_REFLECTION | BSDF_DIFFUSE)), r(r) {

}

Vector3f LambertianReflection::f(const Vector3f &wi, const Vector3f &wo) const {
    return r * Inv_MA_PI;
}


Vector3f LambertianReflection::rho(int, const Point2f *, const Point2f *) const {
    return r;
}

Vector3f LambertianReflection::rho(const Vector3f &, int, const Point2f *) const {
    return r;
}