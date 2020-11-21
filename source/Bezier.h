#pragma once

#define _DEBUG_ADD
#define _DEBUG_VA
#define _DEBUG_VERT
// #define _DEBUG_GV2

#include <iostream>
#include <cmath>
#include <cstdarg>
#include <vector>

#include "Bezier.h"
#include "Vector.h"
#include "Math.h"

template<typename T>
/**
 * Data structure for storing points making up a Bezier curve.
 */
class Bezier {
	unsigned char m_points = 0;
	std::vector<T> points;

public:
	/**
	 * Constructor for the Bezier class.
	 * 
	 * @param points A vector of points - either Vector2 or Vector3 objects.
	 * @returns A new Bezier object.
	 */
    Bezier(const std::vector<T>& points) {
		for(unsigned char i=0; i < points.size(); i++){
			this->addPoint(points[i]);
		}
	}

	/**
	 * Constructor for the Bezier class.
	 * 
	 * @param size Amount of points being passed to the constructor.
	 * @param ... Comma-separated sequence of `size` points, provided by reference, i.e. &Vector2.
	 * @returns A new Bezier object.
	 * @overlaod
	 */
    Bezier(const unsigned char& size, ...) {
		va_list vl;
		va_start(vl, size);
		for(unsigned char i=0; i < size; i++){
			T* ptr = va_arg(vl, T*);
			#ifdef _DEBUG_VA
				std::cout << "T @ " << ptr << " with value " << *ptr << std::endl;
			#endif
			this->addPoint(*ptr);
		}
		va_end(vl);
	}

	/**
	 * Add a point to the end of the curve.
	 * 
	 * @param Point The point to be added.
	 */
    void addPoint(const T& Point) {
		this->points.push_back(Point);
		#ifdef _DEBUG_ADD
			std::cout << "Added point: " << Point << std::endl;
		#endif
		this->m_points++;
	}

	/**
	 * Generate a vertex for the given curve and timestep.
	 * 
	 * @param bezier The curve to generate a vertex from.
	 * @param t The timestep in the range [0, 1].
	 * @returns A point on the curve.
	 */
    static T GenerateVertex(const Bezier& bezier, const double& t) {
		T result = T();

		if(bezier.m_points == 2){
			result = bezier.points[1] * t + bezier.points[0] * (1 - t);
		}

		if(bezier.m_points == 3){
			result = bezier.points[2] * std::pow(t, 2) + bezier.points[1] * 2 * t * (1 - t) + bezier.points[0] * std::pow((1 - t), 2);
		}

		if(bezier.m_points == 4){
			result = bezier.points[3] * std::pow(t, 3) + bezier.points[2] * 3 * (1 - t) * std::pow(t, 2) + bezier.points[1] * 3 * std::pow((1 - t), 2) * t + bezier.points[0] * std::pow((1 - t), 3);
		}

		if(bezier.m_points > 4){
			for(unsigned char i=0; i <= bezier.m_points - 1; i++){
				double bbp = Math::binomial(bezier.m_points - 1, i) * std::pow((1 - t), bezier.m_points - 1 - i) * pow(t, i);
				result += bezier.points[i] * bbp;
			}
		}

		#ifdef _DEBUG_VERT
			std::cout << "Generated Vertex @ " << result << std::endl;
		#endif
		return result;
	}

	/**
	 * Get amount of points making up the curve.
	 * 
	 * @returns The amount of points.
	 */
	unsigned char getSize() const {
		return m_points;
	}
};