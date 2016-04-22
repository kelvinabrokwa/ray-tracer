#include "Sphere.hpp"

void Sphere::set(Vector ctr, double radius)
{
    this->ctr = ctr;
    this->radius = radius;
}

bool Sphere::intersect_sphere(RAY_T ray, double &t, Vector &int_pt, Vector &normal)
{
    double A, B, C;
    A = 1;
    B = 2 * ray.dir.dot(ray.origin - ctr);
    return true;
}
