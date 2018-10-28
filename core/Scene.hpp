//
// Created by Muhammed Ahad on 2018-10-28.
//

#ifndef MA3RENDERER_SCENE_HPP
#define MA3RENDERER_SCENE_HPP

#include <vector>
#include "Primitive.hpp"

class Scene {
public:
    // < Scene public methods 23 >
    Scene() {}
    Scene(Primitive *aggregate);
    // TODO implements Light class
    //    Scene(Primitive *aggregate, std::vector<Light *> lights);

    bool intersect(const Ray &ray, SurfaceInteraction *isect);
    bool intersectP(const Ray &ray);
    // < Scene public data 23 >
    Primitive *aggregate;
    // TODO implements Light class
    //std::vector<Light *> lights;

private:
    // < Scene private data 23 >


};


#endif //MA3RENDERER_SCENE_HPP
