#pragma once

#include <iostream>
#include <cmath>
#include <stdarg.h>
#include <vector>

#include "Vector.h"
#include "Matrix.h"
#include "Math.h"

template<typename T>
/**
 * Data structure for storing points making up a 2-dimensional or 3-dimensional Bezier curve.
 */
class Bezier{
    unsigned char m_points = 0;  // Amount of points.
	LinkedList<T> points;        // Points.
	

public:
	/**
	 * Constructor for the Bezier class.
	 * 
	 * @param points A vector of points - Vector2 or Vector3 objects.
	 * @returns A new Bezier object.
	 */
    Bezier(const std::vector<T> &points);

	/**
	 * Constructor for the Bezier class.
	 * 
	 * @param points A LinkedList of points - Vector2 or Vector3 objects.
	 * @returns A new Bezier object.
	 * @overlaod
	 */
    Bezier(const LinkedList<T> &points);

	/**
	 * Constructor for the Bezier class.
	 * 
	 * @param points A Matrix of points - Vector2 or Vector3 objects.
	 * @returns A new Bezier object.
	 */
	Bezier(const Matrix<T> &points);

	/**
	 * Constructor for the Bezier2 class.
	 * 
	 * @param size Amount of points being passed to the constructor.
	 * @param ... Comma-separated sequence of `size` 2-dimensional points, provided by reference, i.e. &Vector2.
	 * @returns A new Bezier2 object.
	 * @overlaod
	 */
    Bezier(const unsigned char &size, ...);

	/**
	 * Add a point to the end of the curve.
	 * 
	 * @param Point The point to be added.
	 */
    void addPoint(const T &Point);

	/**
	 * Generate a vertex for the given curve and timestep.
	 * 
	 * @param bezier2 The curve to generate a vertex from.
	 * @param t The timestep in the range [0, 1].
	 * @returns A 2-dimensional point on the curve.
	 */
    static T GenerateVertex(Bezier<T> &bezier, const double &t);

	/**
	 * Generate a vertex for the given curve and timestep, using a less efficient method.
	 * 
	 * @overload
	 * @see GenerateVertex
	 */
    static T GenerateVertex2(const Bezier<T> &bezier, const double &t);

	/**
	 * Get amount of points making up the curve.
	 * 
	 * @returns The amount of points.
	 */
	unsigned char getSize() const;
};
