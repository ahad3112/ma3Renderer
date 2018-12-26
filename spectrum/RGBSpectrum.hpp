//
// Created by Muhammed Ahad on 2018-11-17.
//

#ifndef MA3RENDERER_RGBSPECTRUM_HPP
#define MA3RENDERER_RGBSPECTRUM_HPP


#include "CoefficientSpectrum.hpp"

class RGBSpectrum : public CoefficientSpectrum<3>{
public:
    // < RGBSpectrum public methods 332 >
    RGBSpectrum(float v = 0.0f) : CoefficientSpectrum<3>(v) {}


    void toRGB(float *rgb) const;
    void toXYZ(float *xyz) const;
    RGBSpectrum fromRGB(const float rgb[3] , SpectrumType type = SpectrumType::REFLECTANCE);
    RGBSpectrum fromXYZ(const float xyz[3], SpectrumType type = SpectrumType::REFLECTANCE);

    // Operator overload
    RGBSpectrum &operator+=(const RGBSpectrum &s) {
        for(int i = 0; i != nSamples; i++) {
            c[i] += s.c[i];
        }
        return *this;
    }

    RGBSpectrum &operator*=(const float v) {
        for(int i = 0; i!= nSamples; i++) {
            c[i] = c[i] * v;
        }
        return *this;
    }

    RGBSpectrum operator*(const float v) const {
        RGBSpectrum sp = *this;
        for(int i = 0; i!= nSamples; i++) {
            sp.c[i] = sp.c[i] * v;
        }
        return sp;
    }

    RGBSpectrum &operator/=(const float v) {
        for(int i = 0; i!= nSamples; i++) {
            c[i] = c[i] / v;
        }
        return *this;
    }

    RGBSpectrum operator/(const float v) const {
        RGBSpectrum sp = *this;
        for(int i = 0; i!= nSamples; i++) {
            sp.c[i] = sp.c[i] / v;
        }
        return sp;
    }

    // Friend declaration
    friend std::ostream &operator<<(std::ostream &os, const RGBSpectrum &sp);
};




#endif //MA3RENDERER_RGBSPECTRUM_HPP
