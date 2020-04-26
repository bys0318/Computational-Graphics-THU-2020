#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "ray.hpp"
#include "hit.hpp"
#include <iostream>

// TODO: Implement Shade function that computes Phong introduced in class.
class Material {
public:
    Vector3f absorbColor;
    float diff_factor;
    float spec_factor;
    float refr_factor;
    float n;

    explicit Material(const Vector3f &d_color, const Vector3f &s_color = Vector3f::ZERO, const Vector3f &a_color = Vector3f::ZERO,
                      float s = 0, float diff = 1.0f, float spec = 0.0f, float refr = 0.0f, float nn = 1.5f) :
            diffuseColor(d_color), specularColor(s_color), absorbColor(a_color), shininess(s), diff_factor(diff), spec_factor(spec), refr_factor(refr), n(nn) {

    }

    virtual ~Material() = default;

    virtual Vector3f getDiffuseColor() const {
        return diffuseColor;
    }


    Vector3f Shade(const Ray &ray, const Hit &hit,
                   const Vector3f &dirToLight, const Vector3f &lightColor) {
        Vector3f shaded = Vector3f::ZERO;
        // 
        
        Vector3f Rx = 2 * Vector3f::dot(dirToLight, hit.getNormal()) * hit.getNormal() - dirToLight;
        shaded = lightColor * (diffuseColor * std::max(0.0f, Vector3f::dot(dirToLight, hit.getNormal())) + 
                               specularColor * pow(std::max(0.0f, - Vector3f::dot(ray.getDirection(), Rx)), shininess) );
       // std::cout<<"("<<lightColor.x()<<", "<<lightColor.y()<<", "<<lightColor.z()<<")\n";
        return shaded;
    }

protected:
    Vector3f diffuseColor;
    Vector3f specularColor;
    float shininess;
};


#endif // MATERIAL_H
