//
// Created by Muhammed Ahad on 2018-11-15.
//

#include <iostream>
#include "BxDF.hpp"


//====================================================================================================================//
// Class methods
//====================================================================================================================//

bool BxDF::matchesFlags(BxDFType t) {
    return (type & t) == type;
}

Spectrum BxDF::f(const Vector3f &wi, const Vector3f &wo) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;
    return Spectrum();
}

Spectrum BxDF::sample_f(const Vector3f &wi, const Vector3f &wo, float pdf, BxDFType *sampledType) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;
    return Spectrum();
}

Spectrum BxDF::rho(const Vector3f &wo, const Vector3f &wi, int nSamples, const Point2f *samples) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;

    return Spectrum();
}

Spectrum BxDF::rho(int nSamples, const Point2f *samples1, const Point2f *samples2) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;

    return Spectrum();
}