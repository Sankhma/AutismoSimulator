#pragma once


struct Vector2{
    double x, y;

    Vector2(const double &x=0, const double &y=0);

    Vector2 operator+(const Vector2&) const;
    Vector2 operator-(const Vector2&) const;

    static double dot(const Vector2&, const Vector2&);
};

Vector2 operator*(const Vector2& vec, const double lambda);
Vector2 operator*(const double lambda, const Vector2& vec);

struct Vector3{
    double x;
    double y;
    double z;

    Vector3(double x=0., double y=0., double z=0.);

    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;

    static double dot(const Vector3&, const Vector3&);
    static Vector3 cross(const Vector3&, const Vector3&);
};

Vector3 operator*(const Vector3& vec, const double lambda);
Vector3 operator*(const double lambda, const Vector3& vec);