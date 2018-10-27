//
// Created by Muhammed Ahad on 2018-10-26.
//

#ifndef MA3RENDERER_GEOMETRY_H
#define MA3RENDERER_GEOMETRY_H

#include <limits>
#include <glm/glm.hpp>

//====================================================================================================================//
// typedef / type alias for glm Vector class
//====================================================================================================================//

///////////////// infinity for float ////////////////////////
const auto infinity = std::numeric_limits<float>::infinity();

/////////////////////////////// Vector //////////////////////
using Vector2i = glm::ivec2;
using Vector2f = glm::vec2;

using Vector3i = glm::ivec3;
using Vector3f = glm::vec3;


/////////////////////////////// Point ////////////////////////
using Point2i = glm::ivec2;
using Point2f = glm::vec2;

using Point3i = glm::ivec3;
using Point3f = glm::vec3;

///////////////////////////// Normal ////////////////////////
using Normal3i = glm::ivec3;
using Normal3f = glm::vec3;


//////////////////////// Utility function ////////////////////



#endif //MA3RENDERER_GEOMETRY_H
