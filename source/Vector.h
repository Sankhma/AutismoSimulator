#pragma once

struct Vector3{
    double x;
    double y;
    double z;

    Vector3(double x=0., double y=0., double z=0.);

    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;
    Vector3 operator*(const double&) const;

    static double dot(const Vector3&, const Vector3&);
    static Vector3 cross(const Vector3&, const Vector3&);
};