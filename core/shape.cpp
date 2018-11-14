//
// Created by Muhammed Ahad on 2018-10-27.
//

#include "shape.hpp"

//====================================================================================================================//
// Class methods
//====================================================================================================================//

Shape::Shape(const Transform *objectToWorld, const Transform *worldToWorld, bool reverseOrientation) :
objectToWorld(objectToWorld), worldToObject(worldToWorld), reverseOrientation(reverseOrientation), transformSwapsHandedness(objectToWorld->swapsHandedness()){

}