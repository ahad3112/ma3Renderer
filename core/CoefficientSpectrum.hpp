//
// Created by Muhammed Ahad on 2018-11-16.
//

#ifndef MA3RENDERER_COEFFICIENTSPECTRUM_HPP
#define MA3RENDERER_COEFFICIENTSPECTRUM_HPP


#include <cmath>
#include <iostream>
#include "../utility/MA_utility.hpp"

enum class SpectrumType {
    REFLECTANCE,
    ILLUMINANT,
};

template <int nSpectrumSamples> class CoefficientSpectrum {
public:
    // < CoefficientSpectrum public methods 316 >
    CoefficientSpectrum(float v = 0.0f) {
        for(int i = 0; i != nSpectrumSamples; i++) {
            c[i] = v;
        }
    }

    CoefficientSpectrum &operator+=(const CoefficientSpectrum &s) {
        for(int i = 0; i != nSpectrumSamples; i++) {
            c[i] += s.c[i];
        }
        return *this;
    }

    CoefficientSpectrum operator+(const CoefficientSpectrum &s) {
        CoefficientSpectrum cspectrum = *this;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cspectrum.c[i] += s.c[i];
        }
        return cspectrum;
    }

    CoefficientSpectrum &operator-=(const CoefficientSpectrum &s) {
        for(int i = 0; i != nSpectrumSamples; i++) {
            c[i] -= s.c[i];
        }
        return *this;
    }

    CoefficientSpectrum operator-(const CoefficientSpectrum &s) {
        CoefficientSpectrum cspectrum = *this;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cspectrum.c[i] -= s.c[i];
        }
        return cspectrum;
    }

    CoefficientSpectrum &operator*=(float v) {
        for(int i = 0; i != nSpectrumSamples; i++) {
            c[i] *= v;
        }
        return *this;
    }

    CoefficientSpectrum operator*(float v) {
        CoefficientSpectrum cspectrum = *this;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cspectrum.c[i] *= v;
        }
        return cspectrum;
    }

    CoefficientSpectrum &operator/=(float v) {
        for(int i = 0; i != nSpectrumSamples; i++) {
            c[i] /= v;
        }
        hasNaNs();
        return *this;
    }

    CoefficientSpectrum operator/(float v) {
        CoefficientSpectrum cspectrum = *this;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cspectrum.c[i] /= v;
        }
        cspectrum.hasNaNs();
        return cspectrum;
    }

    CoefficientSpectrum operator-() {
        CoefficientSpectrum cspectrum = *this;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cspectrum.c[i] = -cspectrum.c[i];
        }
        return cspectrum;
    }

    bool isBlack() {
        for(int i = 0; i != nSpectrumSamples; i++) {
            if(c[i] != 0.0f) return false;
        }
        return true;
    }

    friend CoefficientSpectrum sqrt(const CoefficientSpectrum &s) {
        CoefficientSpectrum cs;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cs[i] = std::sqrt(s.c[i]);
        }
    }

    friend CoefficientSpectrum pow(const CoefficientSpectrum &s, int p) {
        CoefficientSpectrum cs;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cs[i] = std::pow(s.c[i], p);
        }
    }

    friend CoefficientSpectrum exp(const CoefficientSpectrum &s) {
        CoefficientSpectrum cs;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cs[i] = std::exp(s.c[i]);
        }
    }

    inline CoefficientSpectrum lerp(float t, const CoefficientSpectrum &s1, const CoefficientSpectrum &s2) {
        return (1.0f - t) * s1 + t * s2;
    }

    CoefficientSpectrum clamp(float low = 0, float high = MA_INFINITY_FLOAT) const{
        CoefficientSpectrum cs;
        for(int i = 0; i != nSpectrumSamples; i++) {
            cs.c[i] = clamp(c[i], low, high);
        }
        return cs;
    }

    bool hasNaNs() const {
        for(int i = 0; i != nSpectrumSamples; i++) {
            if(std::isnan(c[i])) return true;
        }
        return false;
    }

    float operator[](int i) const{
        if(i >= 0 && i < nSpectrumSamples) return c[i];
        else {
            std::cerr << "Index out of bounds in\n\tFile: " << __FILE__
                      << "\n\tFunction : " << __func__
                      << "\n\tLine: " << __LINE__ << std::endl;
            return -1.0f;
        }
    }
    // <  CoeffcientSpectrum public data 316 >
    int nSamples = nSpectrumSamples;
protected:
    // < CoefficientSpectrum protected data 316>
    float c[nSpectrumSamples];
};


#endif //MA3RENDERER_COEFFICIENTSPECTRUM_HPP
