#pragma once

#include "Vector.h"

struct Bezier2{
private:
    unsigned int m_points;
    Vector2 point1;
    Vector2 point2;
    Vector2 point3;
    Vector2 point4;

public:
    Bezier2(Vector2 point1, Vector2 point2);
    Bezier2(Vector2 point1, Vector2 point2, Vector2 point3);
    Bezier2(Vector2 point1, Vector2 point2, Vector2 point3, Vector2 point4);

    static Vector2 GenerateVertex(const Bezier2& bezier2, const double& t);
};