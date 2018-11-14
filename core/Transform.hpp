//
// Created by Muhammed Ahad on 2018-11-01.
//

#ifndef MA3RENDERER_TRANSFORMATION_HPP
#define MA3RENDERER_TRANSFORMATION_HPP

#include <iostream>
#include <string>
#include "Geometry.hpp"
#include "Ray.hpp"


class Transform {
public:
    // < Transform public methods 84>
    Transform();
    Transform(const Matrix4x4 &mat);
    Transform(const Matrix4x4 &m, const Matrix4x4 &mInv);

    // TODO THE FOLLOWING TWO METHODS MUST HAVE TO COMBINED IN ONE... AS THE USER DOES NOT ANY IDEA WHAT IS Point3 or Vector3

    // PURELY FOR FLOAT VERSION :: todo update later
    template <typename T> inline T operator()(const T &p) const {
        float x = p.x, y = p.y, z = p.z;
        float xp = m[0][0] * x + m[0][1] * y + m[0][2] * z + m[0][3];
        float yp = m[1][0] * x + m[1][1] * y + m[1][2] * z + m[1][3];
        float zp = m[2][0] * x + m[2][1] * y + m[2][2] * z + m[2][3];
        float wp = m[3][0] * x + m[3][1] * y + m[3][2] * z + m[3][3];

        if (wp == 1.0f) {
            return T(xp, yp, zp);
        } else {
            return T(xp, yp, zp) / wp;
        }
    }

    template <typename T> inline T operator()(const T &p, int i) const {
        float x = p.x, y = p.y, z = p.z;
        float xp = m[0][0] * x + m[0][1] * y + m[0][2] * z;
        float yp = m[1][0] * x + m[1][1] * y + m[1][2] * z;
        float zp = m[2][0] * x + m[2][1] * y + m[2][2] * z;

        return T(xp, yp, zp);
    }

    inline Ray operator()(const Ray &ray) const{
        Point3f origin = (*this)(ray.origin);
        Vector3f dir = (*this)(ray.direction,1);
        return Ray(origin, dir);
    }

    Transform operator*(const Transform &t) const;
    bool swapsHandedness() const;

private:
    // < Transform private data 84>
    Matrix4x4 m, mInv;

    friend Transform translate(const Vector3f &delta);
    friend Transform scale(const Vector3f &x);
    friend Transform rotateX(float theta);
    friend Transform rotateY(float theta);
    friend Transform rotateZ(float theta);
    friend Transform rotate(const Vector3f &axis, float theta);
    friend Transform lookAt(const Point3f &position, const Point3f &look, const Vector3f &up);
    friend Transform perspective(float fov, float nearzplane, float farzplane);
    friend Transform inverse(const Transform &t);
    friend Transform transpose(const Transform &t);
    friend std::ostream &operator<<(std::ostream &os, const Transform &t);

};

//====================================================================================================================//
// Non-class methods
//====================================================================================================================//
Transform translate(const Vector3f &delta);
Transform scale(const Vector3f &x);
Transform rotateX(float theta);
Transform rotateY(float theta);
Transform rotateZ(float theta);
Transform rotate(const Vector3f &axis, float theta);
Transform lookAt(const Point3f &position, const Point3f &look, const Vector3f &up);
Transform perspective(float fov, float nearzplane, float farzplane);
Transform inverse(const Transform &t);
Transform transpose(const Transform &t);

std::ostream &operator<<(std::ostream &os, const Transform &t);


#endif //MA3RENDERER_TRANSFORMATION_HPP
