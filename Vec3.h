#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <cstdio>

double EPS = 1e-9;

class Vec3 {
public:
Vec3();
Vec3(double x, double y, double z);
Vec3(const Vec3 &v);

friend bool operator == (const Vec3 &a, const Vec3 &b);
friend bool operator != (const Vec3 &a, const Vec3 &b);
friend Vec3 operator + (const Vec3 &a, const Vec3 &b);
friend Vec3 operator - (const Vec3 &a, const Vec3 &b);
friend Vec3 operator - (const Vec3 &v);

friend Vec3 operator * (const double f, const Vec3 &v);
friend Vec3 operator * (const Vec3 &v, const double f);
friend Vec3 operator / (const double f, const Vec3 &v);
friend Vec3 operator / (const Vec3 &v, const double f);

friend double dot(const Vec3 &v);

friend std::ostream &operator << (std::ostream &os, const Vec3 &v);

private:
double x, y, z;
};

#endif
