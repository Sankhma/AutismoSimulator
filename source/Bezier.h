#pragma once

#include <vector>

#include "Vector.h"

class Bezier2{
    unsigned int m_points = 0;
    std::vector<Vector2> points;

public:
    Bezier2(const std::vector<Vector2>&);
    Bezier2(const int& size, ...);

    void addPoint(const Vector2& Point);

    static Vector2 GenerateVertex(const Bezier2& bezier2, const double& t);
    static Vector2 GenerateVertex2(const Bezier2 &, const double &);
	unsigned int getSize() const;
};

class Bezier3 {
    unsigned int m_points = 0;
    std::vector<Vector3> points;

public:
    Bezier3(const std::vector<Vector3> &points);
    Bezier3(const int &size, ...);
	
    void addPoint(const Vector3 &point);

    static Vector3 GenerateVertex(const Bezier3 &bezier3, const double &t);
	unsigned int getSize() const;
};
