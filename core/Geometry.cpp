//
// Created by Muhammed Ahad on 2018-11-12.
//
#include "Geometry.hpp"

Matrix4x4 mult(const Matrix4x4 &m1, const Matrix4x4 &m2) {
    Matrix4x4 r;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            r[i][j] = m1[i][0] * m2[0][j] +
                      m1[i][1] * m2[1][j] +
                      m1[i][2] * m2[2][j] +
                      m1[i][3] * m2[3][j];
        }
    }
    return r;
}