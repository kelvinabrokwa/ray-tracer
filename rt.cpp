#include <iostream>
#include "rt.hpp"
#include "obj.hpp"
#include "Light.hpp"

void read_objs(OBJ_T **list) {
    double x, y, z, radius, r, g, b;
    OBJ_T *node;
    while (std::cin >> x >> y >> z >> radius >> r >> g >> b) {
        node = new OBJ_T;
        node->sphere.set(*new Vector(x, y, z), radius);
        node->color.r = r;
        node->color.g = g;
        node->color.b = b;
        node->next = *list;
        *list = node;
    }
}
COLOR_T trace(RAY_T ray, OBJ_T *list, Light light) {
    COLOR_T color;
    color.r = 0, color.g = 0, color.b = 0;
    double min_t = INT_MAX, t;
    Vector int_pt, cl_int_pt;
    Vector normal, cl_normal;
    OBJ_T *obj, *cl_obj = NULL;
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
        color = light.illuminate(ray, cl_obj->color, cl_int_pt, cl_normal);
    }
    return color;
}
int main() {
    OBJ_T *list = NULL;
    COLOR_T pixel;
    RAY_T ray;
    Light light = *new Light(5., 10., 0.);
    ray.origin.set(0, 0, 0);
    read_objs(&list);
    std::cout << "P6\n1000 1000\n255\n";
    for (int y = 0; y < 1000; y++) {
        for (int x = 0; x < 1000; x++) {
            ray.dir.set(-0.5 + x/1000.0, 0.5 - y/1000.0, 1);
            ray.dir.normalize();
            pixel = trace(ray, list, light);
            std::cout
                << (unsigned char)((pixel.r < 1 ? pixel.r : 1) * 255)
                << (unsigned char)((pixel.g < 1 ? pixel.g : 1) * 255)
                << (unsigned char)((pixel.b < 1 ? pixel.b : 1) * 255);
        }
    }
    // gc
    OBJ_T *curr;
    while (list != NULL) {
        curr = list;
        list = list->next;
        delete curr;
    }
}

