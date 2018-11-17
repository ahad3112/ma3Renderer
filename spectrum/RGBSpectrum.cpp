//
// Created by Muhammed Ahad on 2018-11-17.
//

#include "RGBSpectrum.hpp"
#include "../core/Spectrum.hpp"

//====================================================================================================================//
// Class methods
//====================================================================================================================//

RGBSpectrum RGBSpectrum::fromRGB(const float rgb[3], SpectrumType type) {
    RGBSpectrum rs;

    rs.c[0] = rgb[0];
    rs.c[1] = rgb[1];
    rs.c[2] = rgb[2];

    return rs;
}

void RGBSpectrum::toRGB(float *rgb) const {
    rgb[0] = c[0];
    rgb[1] = c[1];
    rgb[2] = c[2];
}

void RGBSpectrum::toXYZ(float *xyz) const {
    xyz[0] = xyz[1] = xyz[2] = 0.0f;
    for(int i = 0; i < nSpectralSamples; i++) {
        std::cout << "Not Implemented yet...\n\tFile: " << __FILE__
                  << "\n\tFunction : " << __func__
                  << "\n\tLine: " << __LINE__ << std::endl;
    }
}