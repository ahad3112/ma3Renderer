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

//Vector3f reflect(const Vector3f &v, const Normal3f &n) {
//    return v - 2.0f * glm::dot(v, n) * n;
//}