//
// Created by Muhammed Ahad on 2018-10-27.
//

#ifndef MA3RENDERER_INTERACTION_HPP
#define MA3RENDERER_INTERACTION_HPP

#include "geometry.hpp"


//====================================================================================================================//
// Interaction
//====================================================================================================================//
struct Interaction {
    // < Interaction's public methods 115>
    Interaction() {}
    Interaction(const Point3f &p, const Normal3f &n);
    bool isSurfaceInteraction() const;

    // < Interaction's public data 115>
    Point3f position;
    Normal3f normal;
    // TODO not used yet.
    float time;

    // TODO MediumInterface and pError and wo
};

//====================================================================================================================//
// SurfaceInteraction
//====================================================================================================================//
class SurfaceInteraction : public Interaction {
public:
    // < SurfaceInteraction public methods >
    SurfaceInteraction(){}
    SurfaceInteraction(const Point3f &p, const Normal3f &n);

    // < SurfaceInteraction public data 116 >
    // TODO public data
};

#endif //MA3RENDERER_INTERACTION_HPP
