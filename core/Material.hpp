//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_MATERIAL_HPP
#define MA3RENDERER_MATERIAL_HPP


#include "Interaction.hpp"

class Material {
public:
    // < Matarial Interface 577 >
    Material (const Vector3f &albedo);
    virtual void computeScatteringFunctions(SurfaceInteraction *isect) const = 0;
    virtual bool computeScatteringFunctions(SurfaceInteraction *isect, const Ray &ray, Ray &scatterRay) const = 0;
    virtual Vector3f getAlbedo() const = 0;


    // TODO
//    virtual void computeScatteringFunctions(SurfaceInteraction *isect, TransportMode Mode, bool allowMultiplelobes) const = 0;
    // Based on shirley
    Vector3f albedo;
};


#endif //MA3RENDERER_MATERIAL_HPP
