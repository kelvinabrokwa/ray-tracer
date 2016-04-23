#include <math.h>
#include "Light.hpp"

Light::Light(double x, double y, double z)
{
    loc.set(x, y, z);
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal)
{
    COLOR_T color;

    // ambient
    color.r = surface_col.r * 0.1;
    color.g = surface_col.g * 0.1;
    color.b = surface_col.b * 0.1;

    // diffuse
    Vector L = loc - int_pt;
    L.normalize();
    double dot = L.dot(normal);
    if (dot > 0) {
        color.r = dot * surface_col.r;
        color.g = dot * surface_col.g;
        color.b = dot * surface_col.b;

        // specular
        Vector R = L - normal * (2. * normal.dot(L));
        R.normalize();
        double dot2 = R.dot(ray.dir);
        if (dot2 > 0) {
            color.r += pow(dot2, 200);
            color.g += pow(dot2, 200);
            color.b += pow(dot2, 200);
        }
    }

    return color;
}
