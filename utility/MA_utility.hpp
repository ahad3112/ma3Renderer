//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_MAUTILITY_HPP
#define MA3RENDERER_MAUTILITY_HPP

#include <limits>

//#include "../core/Geometry.hpp"


#define MA_EPSILON 0.00001f


///////////////// infinity for float ////////////////////////
const auto MA_INFINITY = std::numeric_limits<float>::infinity();

//Vector3f randomUnitSphere() {
//    Vector3f p;
//    do {
//        p = 2.0f * Vector3f(drand48(), drand48(), drand48()) - Vector3f(1.0f,1.0f,1.0f);
//    } while((glm::length(p) * glm::length(p)) >= 1.0);
//
//    return p;
//}



//Vector3f reflect(const Vector3f &v, const Normal3f &n) {
//    return v - 2.0f * glm::dot(v, n) * n;
//}


#endif //MA3RENDERER_MAUTILITY_HPP
