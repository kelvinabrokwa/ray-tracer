#include "Light.hpp"

Light::Light(double x, double y, double z)
{
    loc.set(x, y, z);
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal)
{
    COLOR_T color;

    // ambient color
    color.r = surface_col.r * 0.1;
    color.g = surface_col.g * 0.1;
    color.b = surface_col.b * 0.1;

    return color;
}
