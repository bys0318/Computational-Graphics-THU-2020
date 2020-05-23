#ifndef HIT_H
#define HIT_H

#include <vecmath.h>
#include "ray.hpp"

class Material;

class Hit {
public:

    // constructors
    Hit() {
        material = nullptr;
        t = 1e38;
        type = 'n';
    }

    Hit(float _t, Material *m, const Vector3f &n, char _type) {
        t = _t;
        material = m;
        normal = n;
        type = _type;
    }

    Hit(const Hit &h) {
        t = h.t;
        material = h.material;
        normal = h.normal;
        type = h.type;
    }

    // destructor
    ~Hit() = default;

    float getT() const {
        return t;
    }

    Material *getMaterial() const {
        return material;
    }

    const Vector3f &getNormal() const {
        return normal;
    }

    char getType() const {
        return type;
    }

    void set(float _t, Material *m, const Vector3f &n, char _type) {
        t = _t;
        material = m;
        normal = n;
        type = _type;
    }

private:
    float t;
    Material *material;
    Vector3f normal;
    char type; // n -> None; s -> Sphere; p -> Plane;

};

inline std::ostream &operator<<(std::ostream &os, const Hit &h) {
    os << "Hit <" << h.getT() << ", " << h.getNormal() << ">";
    return os;
}

#endif // HIT_H
