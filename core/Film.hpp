//
// Created by Muhammed Ahad on 2018-10-29.
//

#ifndef MA3RENDERER_FILM_HPP
#define MA3RENDERER_FILM_HPP

#include <string>
#include "Geometry.hpp"

class Film {
public:
    // < Film public methods >
    Film(const Point2i &resolution, const Bounds2f &cropWindow, float diagonal, const std::string &filename, float scale);

    // TODO Implement later
//    Film(const Point2i &resolution, const Bounds2f &cropWindow, Filter* filter, float diagonal, const std::string &filename, float scale);

    // < Film public data 485 >
    const Point2i fullResolution;
    Bounds2i croppedPixelBounds;
    const float diagonal;
//    Filter filter;    // TODO implement
    const std::string fileName;
    const float scale;

private:
    // < Film private methods 486>
    // < Film private data 493>
};


#endif //MA3RENDERER_FILM_HPP
