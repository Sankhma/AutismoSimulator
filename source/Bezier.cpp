#define _DEBUG
#include <iostream>
#include <cmath>

#include "Bezier.h"
#include "Vector.h"
#include "Math.h"

// Bezier2::Bezier2(Vector2 point1, Vector2 point2){
//     this->m_points = 2;
//     this->point1 = point1;
//     this->point2 = point2;
// }

// Bezier2::Bezier2(Vector2 point1, Vector2 point2, Vector2 point3){
//     this->m_points = 3;
//     this->point1 = point1;
//     this->point2 = point2;
//     this->point3 = point3;
// }

// Bezier2::Bezier2(Vector2 point1, Vector2 point2, Vector2 point3, Vector2 point4){
//     this->m_points = 4;
//     this->point1 = point1;
//     this->point2 = point2;
//     this->point3 = point3;
//     this->point4 = point4;
// }

Bezier2::Bezier2(const std::vector<Vector2>& points){
    for(int i=0; i < points.size(); i++){
        this->addPoint(points[i]);
    }
}

void Bezier2::addPoint(const Vector2& Point){
    this->points.push_back(Point);
    #ifdef _DEBUG
        std::cout << "Added point: " << Point << std::endl;
     #endif
    this->m_points++;
}

Vector2 Bezier2::GenerateVertex(const Bezier2& bezier2, const double& t){
    Vector2 result = Vector2();

    if(bezier2.m_points == 2){
        result = t * bezier2.points[1] + bezier2.points[0] * (1 - t);
    }

    if(bezier2.m_points == 3){
        result = bezier2.points[2] * std::pow(t, 2) + bezier2.points[1] * 2 * t * (1 - t) + bezier2.points[0] * std::pow((1 - t), 2);
    }

    if(bezier2.m_points == 4){
        result = bezier2.points[3] * std::pow(t, 3) + bezier2.points[2] * 3 * (1 - t) * std::pow(t, 2) + bezier2.points[1] * 3 * std::pow((1 - t), 2) * t + bezier2.points[0] * std::pow((1 - t), 3);
    }

//dobranoc
    if(bezier2.m_points > 4){
        Vector2 temp = Vector2(0, 0);
        for(int i=0; i < bezier2.m_points; i++){
            if(t ==  0 || t == 1){
                temp = bezier2.points[i];
            } else{
                temp = bezier2.points[i] * std::pow(t, i) * std::pow((1 - t), bezier2.m_points - 1 - i);
            }
            std::cout << temp << "\t" << t << "\t" << Math::binomial(bezier2.m_points, i) << std::endl;
            temp = temp * Math::binomial(bezier2.m_points, i);
            result = result + temp;
        }
    }
    //TODO number of points > 4

    #ifdef _DEBUG
            std::cout << "Generated Vertex @ " << result << std::endl;
    #endif
    return result;
}
