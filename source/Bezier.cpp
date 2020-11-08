#define _DEBUG_ADD
#define _DEBUG_VA
#define _DEBUG_VERT

#include <iostream>
#include <cmath>
#include <stdarg.h>

#include "Bezier.h"
#include "Vector.h"
#include "Math.h"

Bezier2::Bezier2(const std::vector<Vector2>& points){
    for(int i=0; i < points.size(); i++){
        this->addPoint(points[i]);
    }
}

Bezier2::Bezier2(const int& size, ...){
    va_list vl;
    va_start(vl, size);
    for(int i=0; i < size; i++){
        Vector2* ptr = va_arg(vl, Vector2*);
        #ifdef _DEBUG_VA
            std::cout << "Vector2 @ " << ptr << " with value " << *ptr << std::endl;
        #endif
        this->addPoint(*ptr);
    }
    va_end(vl);
}

void Bezier2::addPoint(const Vector2& Point){
    this->points.push_back(Point);
    #ifdef _DEBUG_ADD
        std::cout << "Added point: " << Point << std::endl;
    #endif
    this->m_points++;
}

Vector2 Bezier2::GenerateVertex(const Bezier2& bezier2, const double& t){
    Vector2 result = Vector2();

    if(bezier2.m_points == 2){
        result = bezier2.points[1] * t + bezier2.points[0] * (1 - t);
    }

    if(bezier2.m_points == 3){
        result = bezier2.points[2] * std::pow(t, 2) + bezier2.points[1] * 2 * t * (1 - t) + bezier2.points[0] * std::pow((1 - t), 2);
    }

    if(bezier2.m_points == 4){
        result = bezier2.points[3] * std::pow(t, 3) + bezier2.points[2] * 3 * (1 - t) * std::pow(t, 2) + bezier2.points[1] * 3 * std::pow((1 - t), 2) * t + bezier2.points[0] * std::pow((1 - t), 3);
    }

    if(bezier2.m_points > 4){
        for(int i=0; i <= bezier2.m_points - 1; i++){
            double bbp = Math::binomial(bezier2.m_points - 1, i) * std::pow((1 - t), bezier2.m_points - 1 - i) * pow(t, i);
            result += bezier2.points[i] * bbp;
        }
    }

    #ifdef _DEBUG_VERT
            std::cout << "Generated Vertex @ " << result << std::endl;
    #endif
    return result;
}
