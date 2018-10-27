//
// Created by Muhammed Ahad on 2018-10-27.
//

#include "ray.hpp"

Ray::Ray(const Point3f &origin, const Vector3f &direction, float tMax) : origin(origin), direction(direction), tMax(tMax) {

}

Point3f Ray::operator()(float t) const {
    return origin + t * direction;
}