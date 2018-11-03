//
// Created by Muhammed Ahad on 2018-10-29.
//

#include <iostream>
#include "Film.hpp"

/**
 * Diagonal is given in mm, needs to convert to m
 */
Film::Film(const Point2i &resolution, const Bounds2f &cropWindow, float diagonal, const std::string &filename, float scale) :
          fullResolution(resolution), diagonal(diagonal * .001), fileName(filename), scale(scale){
    // < Compute film image bounds 485>
    if(cropWindow.pMin.x < 0.0 || cropWindow.pMax.x > 1.0f || cropWindow.pMin.y < 0.0 || cropWindow.pMax.y > 1.0f) {
        std::cerr << "Error: CropWindow value should be within range [0,1] for both x and y. Try with the right value." << "\n\tFile: " << __FILE__
                                 << "\n\tFunction: " << __func__
                                 << "\n\tLine: " << __LINE__
                                 << "\nProgram is exiting!!!"
                                 << std::endl;
        std::exit(-1);

    }
    croppedPixelBounds = Bounds2i(Point2i(std::ceil(fullResolution.x * cropWindow.pMin.x),
                                          std::ceil(fullResolution.y * cropWindow.pMin.y)),
                                  Point2i(std::ceil(fullResolution.x * cropWindow.pMax.x),
                                          std::ceil(fullResolution.y * cropWindow.pMax.y)));

    // TODO < Allocate film image storage 486>

    // TODO THIS IS NOT RIGHT  AS cropped window should show up in the full window like zoom in !?!?!!?!?
    pixels = new Point2i[resolution.x * resolution.y];
    colors = new Vector3f[resolution.x * resolution.y];

    // TODO < Pre-compute filter wight table 487>
}


Film::~Film() {
    delete[] pixels;
    delete[] colors;
}