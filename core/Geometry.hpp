//
// Created by Muhammed Ahad on 2018-10-26.
//

#ifndef MA3RENDERER_GEOMETRY_H
#define MA3RENDERER_GEOMETRY_H

#include <cstdlib>
#include <limits>
#include <glm/glm.hpp>
#include <algorithm>

//====================================================================================================================//
// typedef / type alias for glm Vector class
//====================================================================================================================//

/////////////////////////////// Vector //////////////////////
using Vector2i = glm::ivec2;
using Vector2f = glm::vec2;

using Vector3i = glm::ivec3;
using Vector3f = glm::vec3;


//====================================================================================================================//
// Point
//====================================================================================================================//
using Point2i = glm::ivec2;
using Point2f = glm::vec2;

using Point3i = glm::ivec3;
using Point3f = glm::vec3;

//====================================================================================================================//
// Normal
//====================================================================================================================//
using Normal3i = glm::ivec3;
using Normal3f = glm::vec3;


//====================================================================================================================//
// Bounds2
//====================================================================================================================//
template <typename T, typename U> class Bounds2 {
public:
    // < Bounds2 public methods >
    Bounds2() {
        U minNum = std::numeric_limits<U>::lowest();
        U maxNum = std::numeric_limits<U>::max();
        pMin = T(maxNum, maxNum);
        pMax = T(minNum, minNum);
    }

    Bounds2(const T &p1, const T &p2): pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y)),
                                       pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y)){

    }
    // < Bounds2 public data >
    T pMin, pMax;
};

//====================================================================================================================//
// type alias
//====================================================================================================================//
using Bounds2i = Bounds2<Point2i, int>;
using Bounds2f = Bounds2<Point2f, float>;


//////////////////////// Utility function ////////////////////



#endif //MA3RENDERER_GEOMETRY_H
