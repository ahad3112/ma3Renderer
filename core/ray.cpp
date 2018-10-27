//
// Created by Muhammed Ahad on 2018-10-27.
//

#include "ray.hpp"

Ray::Ray(const Point3f &r_o, const Vector3f &r_d) : o(r_o), d(r_d) {

}

Point3f Ray::operator()(float t) const {
    return o + t * d;
}