//
// Created by Muhammed Ahad on 2018-10-29.
//

#include "Film.hpp"

/**
 * Diagonal is given in mm, needs to convert to m
 */
Film::Film(const Point2i &resolution, const Bounds2f &cropWindow, float diagonal, const std::string &filename, float scale) :
          fullResolution(resolution), diagonal(diagonal * .001), fileName(filename), scale(scale){
    // <Compute film image bounds 485>
    croppedPixelBounds = Bounds2i(Point2i(std::ceil(fullResolution.x * cropWindow.pMin.x),
                                          std::ceil(fullResolution.y * cropWindow.pMin.y)),
                                  Point2i(std::ceil(fullResolution.x * cropWindow.pMax.x),
                                          std::ceil(fullResolution.y * cropWindow.pMax.y)));

    // < Allocate film image storage 486>

    // < Pre-compute filter wight table 487>
}