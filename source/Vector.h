#pragma once

#include<iostream>
#include<cmath>
#include<string>

// wtf GitHub

template<typename T>
/**
 * Data structure for storing two values.
 */
struct Vector2{
    T x, y; // Values

	/**
	 * Constructor for the Vector2 class.
	 * 
	 * @param x, y Values to store.
	 * @returns A new Vector2 object.
	 */
    Vector2(const T &x=0, const T &y=0)
		: x(x), y(y) {};

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
    static double dot(const Vector2<T> &vector1, const Vector2<T> &vector2) {
		return vector1.x * vector2.x + vector1.y * vector2.y;
	};

	/**
	 * Calculate the angle between two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The angle between the vectors provided (in radians).
	 */
    static double angle(const Vector2<T> &vector1, const Vector2<T> &vector2) {
		double result = std::acos(Vector2<T>::dot(vector1, vector2) / std::sqrt(Vector2<T>::dot(vector1, vector1) * Vector2<T>::dot(vector2, vector2)));
		return result;
	};

	/**
	 * Return a type name for this class.
	 * @returns string "Vector2".
	 */
	std::string name() {
		return "Vector2";
	}
};

// TODO: can they be inside the function but declared static??
template<typename T, typename U>
Vector2<T> operator*(const Vector2<T> &vector, const U lambda) {
	return {vector.x * lambda, vector.y * lambda};
};

template<typename T, typename U>
Vector2<T> operator*(const U lambda, const Vector2<T> &vector) {
	return vector * lambda;
};

template<typename T>
bool operator==(const Vector2<T> &lhs, const Vector2<T> &rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
};

template<typename T>
bool operator!=(const Vector2<T> &lhs, const Vector2<T> &rhs) {
	return !(lhs == rhs);
};


template<typename T>
/**
 * Data structure for storing three values.
 */
struct Vector3{
    T x, y, z; // Values

	/**
	 * Constructor for the Vector3 class.
	 * 
	 * @param x, y, z Values to store.
	 * @returns A new Vector3 object.
	 */
    Vector3(T x=0., T y=0., T z=0.)
		: x(x), y(y), z(z) {};

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
    static double dot(const Vector3<T> &vector1, const Vector3<T> &vector2) {
		return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	};

	/**
	 * Calculate the cross product of two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The cross product of the vectors provided.
	 */
    static Vector3<T> cross(const Vector3<T> &vector1, const Vector3<T> &vector2) {
		Vector3<T> result;
		result.x = vector1.y * vector2.z - vector2.y * vector1.z;
		result.y = vector1.z * vector2.x - vector2.z * vector1.x;
		result.z = vector1.x * vector2.y - vector2.x * vector1.y;
		return result;
	};

	/**
	 * Calculate the between two Vector2 objects.
	 * 
	 * @param vector1, vector2 Vectors.
	 * @returns The angle between the vectors provided (in radians).
	 */
    static double angle(const Vector3<T> &vector1, const Vector3<T> &vector2) {
	   double result = std::acos(Vector3<T>::dot(vector1, vector2) / std::sqrt(Vector3<T>::dot(vector1, vector1) * Vector3<T>::dot(vector2, vector2)));
	   return result;	
	};

	/**
	 * Return a type name for this class.
	 * @returns string "Vector3".
	 */
	std::string name() {
		return "Vector3";
	}
};

template<typename T, typename U>
Vector3<T> operator*(const Vector3<T> &lhs, const U lambda) {
	Vector3<T> result;
	result.x = lhs.x * lambda;
	result.y = lhs.y * lambda;
	result.z = lhs.z * lambda;
	return result;
};

template<typename T, typename U>
Vector3<T> operator*(const U lambda, const Vector3<T> &rhs) {
	return rhs * lambda;
};

template<typename T>
bool operator==(const Vector3<T> &lhs, const Vector3<T> &rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
};

template<typename T>
bool operator!=(const Vector3<T> &lhs, const Vector3<T> &rhs) {
	return !(lhs == rhs);
};
