#define _DEBUG_ADD
#define _DEBUG_VA
#define _DEBUG_VERT
// #define _DEBUG_GV2

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

Vector2 Bezier2::GenerateVertex2(const Bezier2 &bezier2, const double &t) {
	std::vector<Vector2> points = bezier2.points;
	#ifdef _DEBUG_GV2
		std::cout << "Generating a vertex with:\n\tvertices: ";
		for (const Vector2 &v : points) std::cout << v << ", ";
		std::cout << "\n\tt = " << t << "\nEntering the outer loop...\n\n";
	#endif
	for (int i = 0; i < bezier2.m_points - 1; i++) {
		#ifdef _DEBUG_GV2
			std::cout << "Iteration " << i << "...\nEntering the inner loop...\n\n";
		#endif
		for (int j = 0; j < points.size() - 1; j++) {
			#ifdef _DEBUG_GV2
				std::cout << "(" << points[j + 1] << " - " << points[j] << ") * " << t;
			#endif
			points[j] += (points[j + 1] - points[j]) * t;
			#ifdef _DEBUG_GV2
				std::cout << " = " << points[j] << '\n';
			#endif
		}
		#ifdef _DEBUG_GV2
			std::cout << "\nFinished the inner loop.\n";
			std::cout << "Removing the last vertex in points...\n\n";
		#endif
		points.pop_back();
	}
	#ifdef _DEBUG_GV2
		std::cout << "Finished the outer loop.\n";
	#endif
	std::cout << "Generated vertex @ " << points[0] << '\n';
	return points[0];
}

unsigned int Bezier2::getSize() const {
	return m_points;
}

// -=============== Bezier3 ==================-

Bezier3::Bezier3(const std::vector<Vector3> &points) {
	for (int i = 0; i < points.size(); i++) {
		addPoint(points[i]);
	}
}

Bezier3::Bezier3(const int &size, ...) {
	va_list vl;
	va_start(vl, size);
	for (int i = 0; i < size; i++) {
		Vector3 *ptr = va_arg(vl, Vector3*);
		#ifdef _DEBUG_VA
			std::cout << "Vector3 @ " << ptr << " with value " << *ptr << '\n';
		#endif
		addPoint(*ptr);
	}
	va_end(vl);
}

void Bezier3::addPoint(const Vector3 &point) {
	points.push_back(point);
	#ifdef _DEBUG_ADD
		std::cout << "Added point: " << point << '\n';
	#endif
	m_points++;
}

Vector3 Bezier3::GenerateVertex(const Bezier3 &bezier3, const double &t){
    Vector3 result = Vector3();

	switch (bezier3.m_points) {
		case 2:
        	result = bezier3.points[1] * t + bezier3.points[0] * (1 - t);
			break;
		case 3:
        	result = bezier3.points[2] * std::pow(t, 2) + bezier3.points[1] * 2 * t * (1 - t) + bezier3.points[0] * std::pow((1 - t), 2);
			break;
		case 4:
        	result = bezier3.points[3] * std::pow(t, 3) + bezier3.points[2] * 3 * (1 - t) * std::pow(t, 2) + bezier3.points[1] * 3 * std::pow((1 - t), 2) * t + bezier3.points[0] * std::pow((1 - t), 3);
			break;
		default:
			for (int i = 0; i <= bezier3.m_points - 1; i++) {
				double bbp = Math::binomial(bezier3.m_points - 1, i) * std::pow((1 - t), bezier3.m_points - 1 - i) * pow(t, i);
				result += bezier3.points[i] * bbp;
			}
			break;
	}

    #ifdef _DEBUG_VERT
		std::cout << "Generated Vertex @ " << result << '\n';
    #endif
    return result;
}

unsigned int Bezier3::getSize() const {
	return m_points;
}
