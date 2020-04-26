#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <cmath>
#include <vector>
#include "ray.hpp"
#include "group.hpp"
#include "light.hpp"
#include <vecmath.h>

#define EPS 1e-6

class RayTracer
{
public:
    RayTracer(int d, Group* g, std::vector<Light*>& l, Vector3f c = Vector3f::ZERO, float tm = 5e-4) : max_depth(d), group(g), lights(l), bkgcolor(c), tmin(tm) {}
    ~RayTracer() {}

    Vector3f trace(Ray ray, int depth = 1);
    Vector3f calcDiffusion(Ray ray, Hit& hit, int depth);
    Vector3f calcReflection(Ray ray, Hit& hit, int depth);
    Vector3f calcRefraction(Ray ray, Hit& hit, int depth);

private:
    int max_depth;
    float tmin;
    Group* group;
    Vector3f bkgcolor;
    std::vector<Light*>& lights;
};

#endif //RAYTRACER_H
