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

inline void XYZToRGB(float xyz[3], float rgb[3]);
inline void RGBToXYZ(float rgb[3], float xyz[3]);



#endif //MA3RENDERER_SPECTRUM_HPP
