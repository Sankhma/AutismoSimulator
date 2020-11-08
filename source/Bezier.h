#pragma once

#include <vector>

#include "Vector.h"

struct Bezier2{
private:
    unsigned int m_points = 0;
    std::vector<Vector2> points;
public:
    void addPoint(const Vector2& Point);

public:

    Bezier2(const std::vector<Vector2>&);
    Bezier2(const int& size, ...);

    static Vector2 GenerateVertex(const Bezier2& bezier2, const double& t);
};