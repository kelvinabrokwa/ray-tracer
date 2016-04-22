#include "Vector.hpp"
#include "rt.hpp"

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
private:
    Vector ctr;
    double radius;
public:
    Sphere(void) {}
    void set(Vector ctr, double radius);
    bool intersect_sphere(RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};

#endif
