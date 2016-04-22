#include <math.h>
#include "Vector.hpp"

Vector::Vector(double x, double y, double z)
{
    set(x, y, z);
}

void Vector::set(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector::normalize()
{
    double m = length();
    x /= m;
    y /= m;
    z /= m;
}

double Vector::dot(Vector v)
{
    return x*v.x + y*v.y + z*v.z;
}

Vector Vector::add(Vector v)
{
    return *new Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator+(Vector v)
{
    return this->add(v);
}

Vector Vector::subtract(Vector v)
{
    return *new Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator-(Vector v)
{
    return this->subtract(v);
}

Vector Vector::mult(Vector v)
{
    return *new Vector(x*v.x, y*v.y, z*v.z);
}

Vector Vector::operator*(Vector v)
{
    return this->mult(v);
}

Vector Vector::scalar_mult(double c)
{
    return *new Vector(x*c, y*c, z*c);
}

Vector Vector::operator*(double c)
{
    return this->scalar_mult(c);
}

Vector Vector::scalar_divide(double c)
{
    return *new Vector(x/c, y/c, z/c);
}

Vector Vector::operator/(double c)
{
    return this->scalar_divide(c);
}

double Vector::sum_components()
{
    return x + y + z;
}

double Vector::length()
{
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}
