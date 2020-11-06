#include "Bezier.h"
#include "Vector.h"

Bezier2::Bezier2(Vector2 point1, Vector2 point2){
    this->m_points = 2;
    this->point1 = point1;
    this->point2 = point2;
}

Bezier2::Bezier2(Vector2 point1, Vector2 point2, Vector2 point3){
    this->m_points = 3;
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}

Bezier2::Bezier2(Vector2 point1, Vector2 point2, Vector2 point3, Vector2 point4){
    this->m_points = 4;
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->point4 = point4;
}

Vector2 Bezier2::GenerateVertex(const Bezier2& bezier2, const double& t){
    if(bezier2.m_points == 2){
        Vector2 result;
        result = t * bezier2.point2 + bezier2.point1 * (1 - t);
        return result;
    }

    if(bezier2.m_points == 3){
        Vector2 result;
        result = bezier2.point3 * t * t + bezier2.point2 * 2 * t * (1 - t) + bezier2.point1 * (1 - t) * (1 - t);
        return result;
    }

    if(bezier2.m_points == 4){
        Vector2 result;
        result = bezier2.point4 * t * t * t + bezier2.point3 * 3 * (1 - t) * t * t + 3 * (1 - t) * (1 - t) * t + bezier2.point1 * (1 - t) * (1 - t) * (1 - t);
        return result;
    }
    //TODO number of points > 4
    return Vector2(0, 0);
}