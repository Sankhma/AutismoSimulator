#include <iostream>

#include "Bezier.h"
#include "Vector.h"

int main(){
    Vector2 vec0 = Vector2(1, 2);
    Vector2 vec1 = Vector2(2, 3);
    Vector2 vec2 = Vector2(7, 4);
    Vector2 vec3 = Vector2(133, 1123);

    std::vector<Vector2> points;
    points.push_back(vec0);
    points.push_back(vec1);
    points.push_back(vec2);
    points.push_back(vec3);

    Bezier2 bez0 = Bezier2(points);

    int steps = 5;

    std::cout << "Bezier2 has 4 points in total" << std::endl;

    for(int i=0; i <= steps; i++){
        double t = double(i) / steps;
        Bezier2::GenerateVertex(bez0, t);
    }

    bez0.addPoint(Vector2(1, 2));
    bez0.addPoint(Vector2(420, 69));

    std::cout << "Added 2 more points, Bezier2 has 6 points in total" << std::endl;
    for(int i=0; i <= steps; i++){
        double t = double(i) / steps;
        Bezier2::GenerateVertex(bez0, t);
    }

    Bezier2 bez1 = Bezier2(3, &vec0, &vec1, &vec2);
    std::cout << "Bezier2 (initialized using variadic arguments) has 3 points in total" << std::endl;

    for(int i=0; i <= steps; i++){
        double t = double(i) / steps;
        Bezier2::GenerateVertex(bez1, t);
    }

    bez1.addPoint(Vector2(1, 2));
    bez1.addPoint(Vector2(1, 10));

    std::cout << "Added 2 more point, Bezier2 has 5 points in total" << std::endl;

    for(int i=0; i <= steps; i++){
        double t = double(i) / steps;
        Bezier2::GenerateVertex(bez1, t);
    }
}