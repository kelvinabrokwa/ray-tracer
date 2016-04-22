#include "Vector.hpp"
#include "rt.hpp"

#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light {
private:
    Vector loc;
public:
    Light() {}
    Light(double x, double y, double z);
    COLOR_T illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal);
};

#endif
