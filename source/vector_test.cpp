#include <iostream>
#include <cmath>

#include "Vector.h"

// nice meme GH

int main(){
	std::cout << "-============ Vector3 test =============-" << std::endl;
	{
		Vector3 a = Vector3(5, 5, 5);
		Vector3 b = Vector3(-2, 7, 14);

		Vector3 add = a + b;
		Vector3 sub = a - b;
		Vector3 mul = b * 0.3;
		Vector3 mul1 = 0.3 * b;
		double dot = Vector3::dot(a, b);
		Vector3 cross = Vector3::cross(a, b);

		std::cout << "Adding: x: " << add.x << " y: " << add.y << " z: " << add.z << std::endl;
		std::cout << "Subtracting: x: " << sub.x << " y: " << sub.y << " z: " << sub.z << std::endl;
		std::cout << "Multiplying by a scalar: x: " << mul.x << " y: " << mul.y << " z: " << mul.z << std::endl;
		std::cout << "Dot Product: " << dot << std::endl;
		std::cout << "Cross Product: x: " << cross.x << " y: " << cross.y << " z: " << cross.z << std::endl;

		std::cout << "Testing commutitivity of multiplication by scalar:" << std::endl;
		std::cout << "Vector3 * lambda: x: " << mul.x << " y: " << mul.y << " z: " << mul.z << std::endl;
		std::cout << "lambda * Vector3: x: " << mul1.x << " y: " << mul1.y << " z: " << mul1.z << std::endl;

		std::cout << "Angle between a and b : " << Vector3::angle(a, b) << std::endl;
	}

	std::cout << "-============ Vector2 test =============-" << std::endl;
	{
		Vector2 a = {3, 1};
		Vector2 b = {1, 2};

		std::cout << "a.x: " << a.x << " a.y: " << a.y << std::endl;
		std::cout << "b.x: " << b.x << " b.y: " << b.y << std::endl;
		std::cout << std::endl;

		Vector2 add = a + b;
		Vector2 sub = a - b;
		Vector2 mul = a * 2;
		double dot = Vector2::dot(a, b);

		std::cout << "Adding: x: " << add.x << " y: " << add.y << std::endl;
		std::cout << "Subtracting: x: " << sub.x << " y: " << sub.y << std::endl;
		std::cout << "Multiplying by a scalar: x: " << mul.x << " y: " << mul.y << std::endl;
		std::cout << "Dot: x: " << dot << std::endl;

		std::cout << "Angle between a and b : " << Vector2::angle(a, b) << std::endl;
	}
}