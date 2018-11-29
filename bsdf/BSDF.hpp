//
// Created by Muhammed Ahad on 2018-11-29.
//

#ifndef MA3RENDERER_BSDF_HPP
#define MA3RENDERER_BSDF_HPP


#include "../core/Interaction.hpp"
#include "../core/BxDF.hpp"

class BSDF {
public:
    // < BSDF public methods 573>
    BSDF(SurfaceInteraction &si, float eta = 1) : eta(eta), ng(si.normal) {

    }
    ~BSDF() {
        // TODO NEED TO DELETE THE DYNAMICALLY ALLOCATED BSDF
        // USE MemoryArena from pbrt
    }
    void add(BxDF *b);
    Spectrum f(const Vector3f &wo, const Vector3f &wi, BxDFType flags);
    // < BSDF public data 573>
    float eta;
private:
    // < BSDF private methods 576>
    // < BSDF private data 573>
    int nBxDFs = 0;
    static constexpr int maxBxDFs = 8;
    BxDF *bxdfs[maxBxDFs];
    const Normal3f ng;
};


#endif //MA3RENDERER_BSDF_HPP
