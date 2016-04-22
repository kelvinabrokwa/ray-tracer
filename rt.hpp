#include "Vector.hpp"

#ifndef RT_HPP
#define RT_HPP

typedef struct {
    double r;
    double g;
    double b;
} COLOR_T;

typedef struct {
    Vector origin;
    Vector dir;
} RAY_T;

#endif
