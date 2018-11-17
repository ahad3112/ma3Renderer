//
// Created by Muhammed Ahad on 2018-11-17.
//

#ifndef MA3RENDERER_RGBSPECTRUM_HPP
#define MA3RENDERER_RGBSPECTRUM_HPP


#include "../core/CoefficientSpectrum.hpp"

class RGBSpectrum : public CoefficientSpectrum<3>{
public:
    // < RGBSpectrum public methods 332 >
    RGBSpectrum( float v = 0.0f) : CoefficientSpectrum<3>(v) {}

    void toRGB(float *rgb) const;
    static RGBSpectrum fromRGB(const float rgb[3] , SpectrumType type = SpectrumType::REFLECTANCE);
};


#endif //MA3RENDERER_RGBSPECTRUM_HPP
