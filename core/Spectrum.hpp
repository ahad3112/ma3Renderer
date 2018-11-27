//
// Created by Muhammed Ahad on 2018-11-17.
//

#ifndef MA3RENDERER_SPECTRUM_HPP
#define MA3RENDERER_SPECTRUM_HPP

#include "../spectrum/RGBSpectrum.hpp"

using Spectrum = RGBSpectrum;

// Spectrum Utility Declerations
static const int sampledLamdaStart = 400;
static const int sampledLamdaEnd   = 700;
static const int nSpectralSamples  = 60;

// Spectral Data Declerations
static const float CIE_Y_integral = 106.856895f;
static const int nCIESamples = 471;
extern const float CIE_X[nCIESamples];
extern const float CIE_Y[nCIESamples];
extern const float CIE_Z[nCIESamples];
extern const float CIE_lambda[nCIESamples];

float averageSpectrumSamples(const float *lamda, const float *vals, int n, float lamdaStart, float lamdaEnd);

inline void XYZToRGB(const float xyz[3], float rgb[3]) {
    rgb[0] =  3.240479f*xyz[0] - 1.537150f*xyz[1] - 0.498535f*xyz[2];
    rgb[1] = -0.969256f*xyz[0] + 1.875991f*xyz[1] + 0.041556f*xyz[2];
    rgb[2] =  0.055648f*xyz[0] - 0.204043f*xyz[1] + 1.057311f*xyz[2];
}
inline void RGBToXYZ(const float rgb[3], float xyz[3]) {
    xyz[0] = 0.412453f*rgb[0] + 0.357580f*rgb[1] + 0.180423f*rgb[2];
    xyz[1] = 0.212671f*rgb[0] + 0.715160f*rgb[1] + 0.072169f*rgb[2];
    xyz[2] = 0.019334f*rgb[0] + 0.119193f*rgb[1] + 0.950227f*rgb[2];
}



#endif //MA3RENDERER_SPECTRUM_HPP
