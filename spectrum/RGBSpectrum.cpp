//
// Created by Muhammed Ahad on 2018-11-17.
//

#include "RGBSpectrum.hpp"

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