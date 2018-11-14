//
// Created by Muhammed Ahad on 2018-11-01.
//

#include <iostream>
#include <gtc/matrix_transform.hpp>
#include "Transform.hpp"
#include "../utility/MA_utility.hpp"

//====================================================================================================================//
// Class methods
//====================================================================================================================//
Transform::Transform() {

    m = Matrix4x4(1.0f);
    mInv = glm::inverse(m);
}

Transform::Transform(const Matrix4x4 &mat) : m(mat), mInv(glm::inverse(mat)) {

}

Transform::Transform(const Matrix4x4 &m, const Matrix4x4 &mInv) : m(m), mInv(mInv) {


}


Transform Transform::operator*(const Transform &t) const {
    return Transform(mult(m, t.m), mult(t.mInv, mInv));
}


bool Transform::swapsHandedness() const {
    float det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

    return det < 0.0f;
}

//====================================================================================================================//
// Non-class methods
//====================================================================================================================//

Transform translate(const Vector3f &delta) {
    Matrix4x4 m(1, 0, 0, delta.x,
                0, 1, 0, delta.y,
                0, 0, 1, delta.z,
                0, 0, 0, 1);
    Matrix4x4 mInv(1, 0, 0, -delta.x,
                   0, 1, 0, -delta.y,
                   0, 0, 1, -delta.z,
                   0, 0, 0, 1);

    return Transform(m, mInv);
}

Transform scale(const Vector3f &v) {
    Matrix4x4 m(v.x, 0, 0, 0,
                0, v.y, 0, 0,
                0, 0, v.z, 0,
                0, 0, 0, 1);

    Matrix4x4 mInv(1.0f / v.x, 0, 0, 0,
                   0, 1.0f / v.y, 0, 0,
                   0, 0, 1.0f / v.z, 0,
                   0, 0, 0, 1);

    return Transform(m, mInv);
}



Transform rotate(const Vector3f &axis, float theta) {
//    Transform tmp;
//    return Transform(glm::rotate(tmp.m, theta, axis), glm::rotate(tmp.mInv, theta, axis));
    std::cout << "function: " << __func__ << " not implemented yet"
              << "\n\tFile: " << __FILE__
              << "\n\tLine: " << __LINE__
              << std::endl;

    return Transform();
}


Transform rotateX(float theta) {
    //return rotate(Vector3f(1.0f, 0.0f, 0.0f), theta);
    std::cout << "function: " << __func__ << " not implemented yet"
              << "\n\tFile: " << __FILE__
              << "\n\tLine: " << __LINE__
              << std::endl;

    return Transform();
}

Transform rotateY(float theta) {
    //return rotate(Vector3f(0.0f, 1.0f, 0.0f), theta);
    std::cout << "function: " << __func__ << " not implemented yet"
              << "\n\tFile: " << __FILE__
              << "\n\tLine: " << __LINE__
              << std::endl;

    return Transform();
}

Transform rotateZ(float theta) {
    //return rotate(Vector3f(0.0f, 0.0f, 1.0f), theta);
    std::cout << "function: " << __func__ << " not implemented yet"
              << "\n\tFile: " << __FILE__
              << "\n\tLine: " << __LINE__
              << std::endl;

    return Transform();
}

Transform lookAt(const Point3f &position, const Point3f &look, const Vector3f &up) {
    // TODO Need to check

    Matrix4x4 cameraToWorld;
    // < Initialize fourth column of viewing matris 92 >
    cameraToWorld[0][3] = position.x;
    cameraToWorld[1][3] = position.y;
    cameraToWorld[2][3] = position.z;
    cameraToWorld[3][3] = 1.0f;
    // < Initialize first three columns of viewing matrix 92 >
    Vector3f dir = glm::normalize(look - position);
    Vector3f left = glm::normalize(glm::cross(glm::normalize(up), dir));
    Vector3f newUp = glm::cross(dir, left);

    cameraToWorld[0][0] = left.x;
    cameraToWorld[1][0] = left.y;
    cameraToWorld[2][0] = left.z;
    cameraToWorld[3][0] = 0.0f;

    cameraToWorld[0][1] = newUp.x;
    cameraToWorld[1][1] = newUp.y;
    cameraToWorld[2][1] = newUp.z;
    cameraToWorld[3][1] = 0.0f;

    cameraToWorld[0][2] = dir.x;
    cameraToWorld[1][2] = dir.y;
    cameraToWorld[2][2] = dir.z;
    cameraToWorld[3][2] = 0.0f;

    return Transform(glm::inverse(cameraToWorld), cameraToWorld);
}

Transform perspective(float fov, float n, float f) {
    // < Perform perspective divide for perspective position 366 >
    Matrix4x4 perspective(1.0f, 0.0f, 0.0f, 0.0f,
                          0.0f, 1.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, f/(f - n), -(f * n) / (f - n),
                          0.0f, 0.0f, 1.0f, 0.0f
            );
    // < Scale canonical perspective view to specified view to specified field of view 367 >
    float invTanAng = 1.0f / std::tan(radians(fov) / 2.0f);

    return scale(Vector3f(invTanAng, invTanAng, 1.0f)) * Transform(perspective);
}


Transform inverse(const Transform &t) {
    return Transform(t.mInv, t.m);
}
Transform transpose(const Transform &t) {
    return Transform(glm::transpose(t.m), glm::transpose(t.mInv));
}

std::ostream &operator<<(std::ostream &os, const Transform &t){

    os << "m:\n[" << t.m[0][0] << " " << t.m[0][1] << " "<< t.m[0][2] << " "<< t.m[0][3] << "\n "
                 << t.m[1][0] << " " << t.m[1][1] << " "<< t.m[1][2] << " "<< t.m[1][3] << "\n "
                 << t.m[2][0] << " " << t.m[2][1] << " "<< t.m[2][2] << " "<< t.m[2][3] << "\n "
                 << t.m[3][0] << " " << t.m[3][1] << " "<< t.m[3][2] << " "<< t.m[3][3] << "] "
                 << std::endl;
    os << "mInv:\n[" << t.mInv[0][0] << " " << t.mInv[0][1] << " "<< t.mInv[0][2] << " "<< t.mInv[0][3] << "\n "
                    << t.mInv[1][0] << " " << t.mInv[1][1] << " "<< t.mInv[1][2] << " "<< t.mInv[1][3] << "\n "
                    << t.mInv[2][0] << " " << t.mInv[2][1] << " "<< t.mInv[2][2] << " "<< t.mInv[2][3] << "\n "
                    << t.mInv[3][0] << " " << t.mInv[3][1] << " "<< t.mInv[3][2] << " "<< t.mInv[3][3] << "]"
                    << std::endl;


    return os;
}