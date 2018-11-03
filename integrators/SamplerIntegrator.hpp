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

    // TODO IMPLEMENT SAMPLER CLASS
//    SamplerIntegrator(Camera *camera, Sampler *sampler);

    void Render(const Scene &scene) override;
    virtual Vector3f Li(const Ray &ray, const Scene &scene, int depth = 0) const;

protected:
    // < SamplerIntegrator Protected Data 26>
    Camera *camera;
private:
    // < SamplerIntegrator Protected Data 25>
    // TODO implement later if required
    //Sampler *sampler;


};


#endif //MA3RENDERER_SAMPLERINTEGRATOR_HPP
