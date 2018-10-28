//
// Created by Muhammed Ahad on 2018-10-28.
//

#ifndef MA3RENDERER_AGGREGRATE_HPP
#define MA3RENDERER_AGGREGRATE_HPP


#include "../core/Primitive.hpp"

class Aggregrate : public Primitive{
public:
    // < Aggregrate public Methods >
    Aggregrate() {}
    bool intersect(const Ray &ray, SurfaceInteraction *isect) const override;

    bool intersect(const Ray &ray, float *t, SurfaceInteraction *isect) const override;

    bool intersectP(const Ray &ray) const override ;


};


#endif //MA3RENDERER_AGGREGRATE_HPP
