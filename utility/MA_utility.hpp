//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_MAUTILITY_HPP
#define MA3RENDERER_MAUTILITY_HPP

#include <limits>

#include "../core/Geometry.hpp"



//====================================================================================================================//
// const values
//====================================================================================================================//

#define MA_EPSILON 0.00001f
#define MA_PI 3.1415926535f
#define Inv_MA_PI 0.3183098862f


///////////////// infinity for float ////////////////////////
const auto MA_INFINITY_FLOAT = std::numeric_limits<float>::infinity();


//====================================================================================================================//
// Utility functions
//====================================================================================================================//
Vector3f randomUnitSphere();


Vector3f reflect(const Vector3f &v, const Normal3f &n);
bool refract(const Vector3f &v, const Normal3f &n, float eta, Vector3f &refractedD);
float schlick(float cosine, float refractionIndex);

float radians(float degree);
float degrees(float radian);


template <typename T, typename U, typename V> inline T clamp();

float lerp(float t, float start, float end);

#endif //MA3RENDERER_MAUTILITY_HPP
