#pragma once

#include<iostream>

/**
 * Data structure for storing two values.
 */
struct Vector2{
    double x, y; // Values

	/**
	 * Constructor for the Vector2 class.
	 * 
	 * @oaram x,y Values to store.
	 * @returns A new Vector2 object.
	 */
    Vector2(const double &x=0, const double &y=0);

    Vector2 operator+(const Vector2&) const;
    Vector2 operator-(const Vector2&) const;
    Vector2& operator+=(const Vector2&);
    Vector2& operator-=(const Vector2&);
    Vector2& operator*=(const double&);
    friend std::ostream& operator<<(std::ostream&, const Vector2&);

	/**
	 * Calculate the dot product of two Vector2 objects.
	 * 
	 * @param v1,v2 Vectors.
	 * @returns The dot product of the vectors provided.
	 */
    static double dot(const Vector2& v1, const Vector2& v2);

	/**
	 * Calculate the angle between two Vector2 objects.
	 * 
	 * @param v1,v2 Vectors.
	 * @returns The angle between the vectors provided (in radians).
	 */
    static double angle(const Vector2& v1, const Vector2& v2);
};

Vector2 operator*(const Vector2& vec, const double lambda);
Vector2 operator*(const double lambda, const Vector2& vec);

/**
 * Data structure for storing three values.
 */
struct Vector3{
    double x, y, z; // Values

	/**
	 * Constructor for the Vector3 class.
	 * 
	 * @param x,y,z Values to store.
	 * @returns A new Vector3 object.
	 */
    Vector3(double x=0., double y=0., double z=0.);

    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;
    Vector3& operator+=(const Vector3&);
    Vector3& operator-=(const Vector3&);
    Vector3& operator*=(const double&);
    friend std::ostream& operator<<(std::ostream&, const Vector3&);

	/**
	 * Calculate the dot product of two Vector3 objects.
	 * 
	 * @param v1,v2 Vectors.
	 * @returns The dot product of the vectors provided.
	 */
    static double dot(const Vector3& vec1, const Vector3& vec2);

	/**
	 * Calculate the cross product of two Vector2 objects.
	 * 
	 * @param v1,v2 Vectors.
	 * @returns The dot product of the vectors provided.
	 */
    static Vector3 cross(const Vector3& vec1, const Vector3& vec2);

	/**
	 * Calculate the between two Vector2 objects.
	 * 
	 * @param v1,v2 Vectors.
	 * @returns The angle between the vectors provided (in radians).
	 */
    static double angle(const Vector3& vec1, const Vector3& vec2);
};

Vector3 operator*(const Vector3& vec, const double lambda);
Vector3 operator*(const double lambda, const Vector3& vec);