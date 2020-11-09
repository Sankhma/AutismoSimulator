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
    static Vector2 GenerateVertex2(const Bezier2 &, const double &);
	unsigned int getSize() const;
};

class Bezier3 {
    unsigned int m_points = 0;
    std::vector<Vector3> points;

public:
    void addPoint(const Vector3 &);
	
    Bezier3(const std::vector<Vector3> &);
    Bezier3(const int &, ...);

    static Vector3 GenerateVertex(const Bezier3 &, const double &);
	unsigned int getSize() const;
};
