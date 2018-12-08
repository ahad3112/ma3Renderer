//
// Created by Muhammed Ahad on 2018-12-08.
//

#ifndef MA3RENDERER_CONSTANTTEXTURE_HPP
#define MA3RENDERER_CONSTANTTEXTURE_HPP

#include "../core/Texture.hpp"

template <typename T> class ConstantTexture : public Texture<T> {
public:
    // <ConstantTexture public methods>
    ConstantTexture(const T &value) : value(value){

    }

    T evaluate(const SurfaceInteraction &si) const override {
        return value;
    }

private:
    T value;
};


#endif //MA3RENDERER_CONSTANTTEXTURE_HPP
