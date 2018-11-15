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

Vector3f BxDF::f(const Vector3f &wi, const Vector3f &wo) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;
    return Vector3f();
}

Vector3f BxDF::sample_f(const Vector3f &wi, const Vector3f &wo, float pdf, BxDFType *sampledType) const {
    std::cerr << "Warning: \n\tFile:" << __FILE__
              << "\n\tLine: " << __LINE__
              << "Function: " << __func__
              << "Should be override by the derived class" << std::endl;
    return Vector3f();
}