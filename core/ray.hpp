//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_RAY_HPP
#define MA3RENDERER_RAY_HPP

#include "geometry.hpp"

class Ray {
public:
    // < Ray public methods>
    Ray() {}
    Ray(const Point3f &r_o, const Vector3f &r_d);

    Point3f operator()(float t) const;

    // < Ray public data>
    Point3f o;
    Vector3f d;
};

#endif //MA3RENDERER_RAY_HPP
