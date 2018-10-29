//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_SAMPLERINTEGRATOR_HPP
#define MA3RENDERER_SAMPLERINTEGRATOR_HPP


#include "../core/Integrator.hpp"
#include "../core/Camera.hpp"

class SamplerIntegrator : public Integrator{
public:
    // < SamplerIntegrator public methods 26>
    SamplerIntegrator(Camera *camera);
    void Render(const Scene &scene) override;

protected:
    // < SamplerIntegrator Protected Data 26>
    Camera *camera;
private:
    // < SamplerIntegrator Protected Data 25>

    // TODO implement later if required
    //Sampler *sampler;


};


#endif //MA3RENDERER_SAMPLERINTEGRATOR_HPP
