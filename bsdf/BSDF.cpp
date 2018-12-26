//
// Created by Muhammed Ahad on 2018-11-29.
//
#include <cassert>
#include "BSDF.hpp"
//====================================================================================================================//
// Class methods
//====================================================================================================================//

void BSDF::add(BxDF *b) {
    assert(nBxDFs < maxBxDFs);
    bxdfs->push_back(b);
    nBxDFs++;
    //bxdfs[nBxDFs++] = b;
}

Spectrum BSDF::f(const Vector3f &wo, const Vector3f &wi, BxDFType flags) {
    bool reflect = glm::dot(wo,ng) < 0.0f; // TODO NEED TO DOUBLE CHECK
    Spectrum sp(0.0f);

    for (auto bxdf : (*bxdfs)) {
        if(bxdf->matchesFlags(flags) &&
                ((reflect && (bxdf->type & BSDF_REFLECTION))||
                        (!reflect && (bxdf->type & BSDF_TRANSMISSION)))) {
            sp += bxdf->f(wo,wi);
        }
    }

//    for (int i = 0; i != nBxDFs; ++i) {
//        if(bxdfs[i]->matchesFlags(flags) &&
//                ((reflect && (bxdfs[i]->type & BSDF_REFLECTION))||
//                        (!reflect && (bxdfs[i]->type & BSDF_TRANSMISSION)))) {
//            sp += bxdfs[i]->f(wo,wi);
//        }
//    }

    return sp;
}