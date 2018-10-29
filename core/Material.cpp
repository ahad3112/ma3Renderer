//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <iostream>
#include "Material.hpp"

void Material::computeScatteringFunctions(SurfaceInteraction *isect) const {
    std::cout << "Derived class of Material must override Material::computeScatteringFunctions(SurfaceInteraction *isect) const = 0; "
              << std::endl;
}