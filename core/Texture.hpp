//
// Created by Muhammed Ahad on 2018-12-08.
//

#ifndef MA3RENDERER_TEXTURE_HPP
#define MA3RENDERER_TEXTURE_HPP


#include "Interaction.hpp"
template <typename T> class Texture {
public:
    // <Texture Interface 615>
    virtual T evaluate(const SurfaceInteraction &si) const = 0;
};


#endif //MA3RENDERER_TEXTURE_HPP
