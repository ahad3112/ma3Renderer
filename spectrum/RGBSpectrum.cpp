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
//    float rgb[3];
//    toRGB(rgb);
    RGBToXYZ(c,xyz);
}

RGBSpectrum RGBSpectrum::fromXYZ(const float xyz[], SpectrumType type) {
    float rgb[3];
    XYZToRGB(xyz,rgb);

    return fromRGB(rgb); // Second argument is not required
}

std::ostream &operator<<(std::ostream &os, const RGBSpectrum &sp) {

    os << "RGBSpectrum: (" << sp.c[0] << ", "
       << sp.c[1] << ", "
       << sp.c[2] << ")";

    return os;
}


