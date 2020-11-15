#pragma once

#include <vector>

#include "Vector.h"

/**
 * Data structure for storing points making up a 2-dimensional Bezier curve.
 */
class Bezier2{
    unsigned char m_points = 0;  // Amount of points.
    std::vector<Vector2> points; // Vector of points.

public:
	/**
	 * Constructor for the Bezier2 class.
	 * 
	 * @param points A vector of points - Vector2 objects.
	 * @returns A new Bezier2 object.
	 */
    Bezier2(const std::vector<Vector2>& points);

	/**
	 * Constructor for the Bezier2 class.
	 * 
	 * @param size Amount of points being passed to the constructor.
	 * @param ... Comma-separated sequence of `size` 2-dimensional points, provided by reference, i.e. &Vector2.
	 * @returns A new Bezier2 object.
	 * @overlaod
	 */
    Bezier2(const unsigned char& size, ...);

	/**
	 * Add a point to the end of the curve.
	 * 
	 * @param Point The point to be added.
	 */
    void addPoint(const Vector2& Point);

	/**
	 * Generate a vertex for the given curve and timestep.
	 * 
	 * @param bezier2 The curve to generate a vertex from.
	 * @param t The timestep in the range [0, 1].
	 * @returns A 2-dimensional point on the curve.
	 */
    static Vector2 GenerateVertex(const Bezier2& bezier2, const double& t);

	/**
	 * Generate a vertex for the given curve and timestep, using a less efficient method.
	 * 
	 * @overload
	 * @see GenerateVertex
	 */
    static Vector2 GenerateVertex2(const Bezier2 &, const double &);

	/**
	 * Get amount of points making up the curve.
	 * 
	 * @returns The amount of points.
	 */
	unsigned char getSize() const;
};

/**
 * Data structure for storing points making up a 3-dimensional Bezier curve.
 */
class Bezier3 {
    unsigned char m_points = 0;  // Amount of points.
    std::vector<Vector3> points; // Vector of points.

public:
	/**
	 * Constructor for the Bezier3 class.
	 * 
	 * @param points A vector of points - Vector3 objects.
	 * @returns A new Bezier3 object.
	 */
    Bezier3(const std::vector<Vector3> &points);

	/**
	 * Constructor for the Bezier3 class.
	 * 
	 * @param size Amount of points being passed to the constructor.
	 * @param ... Comma-separated sequence of `size` 3-dimensional points, provided by reference, i.e. &Vector3.
	 * @returns A new Bezier3 object.
	 * @overlaod
	 */
    Bezier3(const unsigned char &size, ...);
	
	/**
	 * Add a point to the end of the curve.
	 * 
	 * @param Point The point to be added.
	 */
    void addPoint(const Vector3 &point);

	/**
	 * Generate a vertex for the given curve and timestep.
	 * 
	 * @param bezier3 The curve to generate a vertex from.
	 * @param t The timestep in the range [0, 1].
	 * @returns A 3-dimensional point on the curve.
	 */
    static Vector3 GenerateVertex(const Bezier3 &bezier3, const double &t);

	/**
	 * Get amount of points making up the curve.
	 * 
	 * @returns The amount of points.
	 */
	unsigned char getSize() const;
};
