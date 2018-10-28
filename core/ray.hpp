//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_RAY_HPP
#define MA3RENDERER_RAY_HPP

#include "geometry.hpp"
#include "../utility/maUtility.hpp"

class Ray {
public:
    // < Ray public methods>
    Ray() {}
    Ray(const Point3f &origin, const Vector3f &direction, float tMax = MA_INFINITY);

    Point3f operator()(float t) const;

    // < Ray public data>
    Point3f origin;
    Vector3f direction;
    mutable float tMax;
};

#endif //MA3RENDERER_RAY_HPP
