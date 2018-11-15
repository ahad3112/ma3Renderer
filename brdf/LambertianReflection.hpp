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
    LambertianReflection(const Vector3f &r);

    Vector3f f(const Vector3f &wi, const Vector3f &wo) const override;

    Vector3f rho(const Vector3f &, int , const Point2f *) const;
    Vector3f rho(int , const Point2f *, const Point2f *) const;


    // < Lambertian Reflection private data 532>
    const Vector3f r;
};


#endif //MA3RENDERER_LAMBERTIANREFLECTION_HPP
