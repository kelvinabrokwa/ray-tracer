#include "Sphere.hpp"
#include "rt.hpp"

#ifndef OBJ_HPP
#define OBJ_HPP

typedef struct OBJ {
    Sphere sphere;
    COLOR_T color;
    struct OBJ *next;
} OBJ_T;

#endif
