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


///////////////// infinity for float ////////////////////////
const auto MA_INFINITY = std::numeric_limits<float>::infinity();


//====================================================================================================================//
// Utility functions
//====================================================================================================================//
Vector3f randomUnitSphere();
Vector3f reflect(const Vector3f &v, const Normal3f &n);

float radians(float degree);
float degrees(float radian);

#endif //MA3RENDERER_MAUTILITY_HPP
