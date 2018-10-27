//
// Created by Muhammed Ahad on 2018-10-27.
//

#include "ray.hpp"

Ray::Ray(const Point3f &origin, const Vector3f &direction) : origin(origin), direction(direction) {

}

Point3f Ray::operator()(float t) const {
    return origin + t * direction;
}