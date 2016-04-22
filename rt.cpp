#include <iostream>
#include "rt.hpp"
#include "obj.hpp"
#include "Light.hpp"

void read_objs(OBJ_T &list) {
    double x, y, z, radius, r, g, b;
    OBJ_T node;
    while (std::cin >> x >> y >> z >> radius >> r >> g >> b) {
        node = *new OBJ_T;
        node.sphere.set(*new Vector(x, y, z), radius);
        node.color.r = r;
        node.color.g = g;
        node.color.b = b;
        node.next = &list;
        list = node;
    }
}
COLOR_T trace(RAY_T ray, OBJ_T *list, Light light) {
    COLOR_T color;
    color.r = 1, color.g = 1, color.b = 1;
    double min_t = INT_MAX, t;
    Vector int_pt, cl_int_pt;
    Vector normal, cl_normal;
    OBJ_T *obj, *cl_obj;
    for (obj = list; obj != NULL; obj = obj->next) {
        if (obj->sphere.intersect_sphere(ray, t, int_pt, normal)) {
            if (t < min_t) {
                cl_int_pt = int_pt;
                cl_normal = normal;
                cl_obj = obj;
                min_t = t;
            }
        }
    }
    if (cl_obj != NULL) {
        return color = light.illuminate(ray, cl_obj->color, cl_int_pt, cl_normal);
    }
    return color;
}
int main() {
    std::cout << "P6\n1000 1000\n255\n";
    OBJ_T list;
    read_objs(list);
    COLOR_T pixel;
    RAY_T ray;
    ray.origin.set(0, 0, 0);
    for (int y = 0; y < 1000; y++) {
        for (int x = 0; x < 1000; x++) {
            ray.dir.set(-0.5 + x / 1000.0, 0.5 - y / 1000.0, 1);
            ray.dir.normalize();
            std::cout
                << (unsigned char)((pixel.r < 1 ? pixel.r : 1)* 255 )
                << (unsigned char)((pixel.g < 1 ? pixel.g : 1)* 255 )
                << (unsigned char)((pixel.b < 1 ? pixel.b : 1)* 255 );
        }
    }
}
