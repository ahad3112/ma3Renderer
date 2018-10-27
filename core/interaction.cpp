//
// Created by Muhammed Ahad on 2018-10-27.
//

#include "interaction.hpp"

//====================================================================================================================//
// Interaction
//====================================================================================================================//
Interaction::Interaction(const Point3f &p, const Normal3f &n) : position(p), normal(n) {

}

bool Interaction::isSurfaceInteraction() const {
    return normal!= Normal3f(); // TODO need to double check this
}

//====================================================================================================================//
// SurfaceInteraction
//====================================================================================================================//
SurfaceInteraction::SurfaceInteraction(const Point3f &p, const Normal3f &n) : Interaction(p, n) {

}