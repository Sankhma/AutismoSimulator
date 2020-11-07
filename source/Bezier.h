#pragma once

#include "Vector.h"
#include "Matrix.h"

struct Bezier2{
private:
    unsigned int m_points;
    Vector2 point1;
    Vector2 point2;
    Vector2 point3;
    Vector2 point4;
    //TODO - dynamic number of points
     

public:
    Bezier2(Vector2 point1, Vector2 point2);
    Bezier2(Vector2 point1, Vector2 point2, Vector2 point3);
    Bezier2(Vector2 point1, Vector2 point2, Vector2 point3, Vector2 point4);

    // template<typename First, typename ... Vectors>
    // Bezier2(First arg, const Vectors& ... rest);

    static Vector2 GenerateVertex(const Bezier2& bezier2, const double& t);
};