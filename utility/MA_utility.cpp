//
// Created by Muhammed Ahad on 2018-10-30.
//

#include "MA_utility.hpp"

Vector3f randomUnitSphere() {
    Vector3f p;
    do {
        p = 2.0f * Vector3f(drand48(), drand48(), drand48()) - Vector3f(1.0f,1.0f,1.0f);
    } while((glm::length(p) * glm::length(p)) >= 1.0);

    return p;
}


float radians(float degree) {
    return (MA_PI / 180.f) * degree;
}

float degrees(float radian) {
    return (180.0f / MA_PI) * radian;
}

Vector3f reflect(const Vector3f &v, const Normal3f &n) {
    return v - 2.0f * glm::dot(v, n) * n;
}

bool refract(const Vector3f &v, const Normal3f &n, float eta, Vector3f &refractedD) {
    Vector3f uv = glm::normalize(v);
    float dotVal = glm::dot(uv, n);
    float discriminant = 1.0f - eta * eta * (1.0f - dotVal * dotVal);

    if(discriminant > 0.0f) {
        refractedD = eta * (uv - n * dotVal) - n * std::sqrt(discriminant);
        return true;
    } else {
        return false;
    }
}

float schlick(float cosine, float refractionIndex) {
    float r0 = (1.0f - refractionIndex) / (1.0f + refractionIndex);
    r0 = r0 *   r0;
    return r0 + (1.0f - r0) * std::pow((1.0f - cosine), 5);

}


template <typename T, typename U, typename V> inline T clamp(T val, U low, V high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}