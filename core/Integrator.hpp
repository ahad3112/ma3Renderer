//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_INTEGRATOR_HPP
#define MA3RENDERER_INTEGRATOR_HPP


#include "Scene.hpp"

class Integrator {
public:
    // < Integrator Interface 25 >
    Integrator () {}
    virtual ~Integrator() {}
    virtual void Render(const Scene &scene) = 0;
};


#endif //MA3RENDERER_INTEGRATOR_HPP
