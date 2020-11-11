#pragma once

#include <vector>

#include "Vector.h"

class Bezier2{
    unsigned char m_points = 0;
    std::vector<Vector2> points;

public:
    Bezier2(const std::vector<Vector2>&);
    Bezier2(const unsigned char& size, ...);

    void addPoint(const Vector2& Point);

    static Vector2 GenerateVertex(const Bezier2& bezier2, const double& t);
    static Vector2 GenerateVertex2(const Bezier2 &, const double &);
	unsigned char getSize() const;
};

class Bezier3 {
    unsigned char m_points = 0;
    std::vector<Vector3> points;

public:
    Bezier3(const std::vector<Vector3> &points);
    Bezier3(const unsigned char &size, ...);
	
    void addPoint(const Vector3 &point);

    static Vector3 GenerateVertex(const Bezier3 &bezier3, const double &t);
	unsigned char getSize() const;
};
