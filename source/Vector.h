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
	 * @param x, y Values to store.
	 * @returns A new Vector2 object.
	 */
    Vector2(const double &x=0, const double &y=0);

	template<typename X>
	operator Vector2<X>() const {
		return {static_cast<X>(this->x), static_cast<X>(this->y)};
	}

    Vector2<T> operator+(const Vector2<T> &rhs) const {
		return {this->x + rhs.x, this->y + rhs.y};
	};

    Vector2<T> operator-(const Vector2<T> &rhs) const {
		return {this->x - rhs.x, this->y - rhs.y};
	};

    Vector2<T>& operator+=(const Vector2<T> &rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	};

    Vector2<T>& operator-=(const Vector2<T> &rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	};

    Vector2<T>& operator*=(const T &lambda) {
		this->x *= lambda;
		this->y *= lambda;
		return *this;
	};

    friend std::ostream& operator<<(std::ostream &os, const Vector2<T> &vector) {
		os << "[" << vector.x << ", " << vector.y << "]";
		return os;
	};

	/**
	 * Calculate the dot product of two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The dot product of the vectors provided.
	 */
    static double dot(const Vector2& v1, const Vector2& v2);

	/**
	 * Calculate the angle between two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The angle between the vectors provided (in radians).
	 */
    static double angle(const Vector2& v1, const Vector2& v2);
};

Vector2 operator*(const Vector2& vec, const double lambda);
Vector2 operator*(const double lambda, const Vector2& vec);
bool operator==(const Vector2 &vec1, const Vector2 &vec2);
bool operator!=(const Vector2 &vec1, const Vector2 &vec2);

/**
 * Data structure for storing three values.
 */
struct Vector3{
    double x, y, z; // Values

	/**
	 * Constructor for the Vector3 class.
	 * 
	 * @param x, y, z Values to store.
	 * @returns A new Vector3 object.
	 */
    Vector3(double x=0., double y=0., double z=0.);

	template<typename X>
	operator Vector3<X>() const {
		return {static_cast<X>(this->x), static_cast<X>(this->y), static_cast<X>(this->z)};
	}

    Vector3<T> operator+(const Vector3<T> &rhs) const {
		return {this->x + rhs.x, this->y + rhs.y, this->z + rhs.z};
	};

    Vector3<T> operator-(const Vector3<T> &rhs) const {
		return {this->x - rhs.x, this->y - rhs.y, this->z - rhs.z};
	};

    Vector3<T>& operator+=(const Vector3<T> &rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	};

    Vector3<T>& operator-=(const Vector3<T> &rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	};

    Vector3<T>& operator*=(const T &lambda) {
		this->x *= lambda;
		this->y *= lambda;
		this->z *= lambda;
		return *this;
	};

    friend std::ostream& operator<<(std::ostream &os, const Vector3<T> &vector) {
		os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
		return os;
	};

	/**
	 * Calculate the dot product of two Vector3 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The dot product of the vectors provided.
	 */
    static double dot(const Vector3& vec1, const Vector3& vec2);

	/**
	 * Calculate the cross product of two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The cross product of the vectors provided.
	 */
    static Vector3 cross(const Vector3& vec1, const Vector3& vec2);

	/**
	 * Calculate the between two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The angle between the vectors provided (in radians).
	 */
    static double angle(const Vector3& vec1, const Vector3& vec2);
};

Vector3 operator*(const Vector3& vec, const double lambda);
Vector3 operator*(const double lambda, const Vector3& vec);
bool operator==(const Vector3 &vec1, const Vector3 &vec2);
bool operator!=(const Vector3 &vec1, const Vector3 &vec2);