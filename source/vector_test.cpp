#include <iostream>

#include "Vector.h"

int main(){
	std::cout << "-============ Vector3 test =============-" << std::endl;
	{
		Vector3<double> a = Vector3<double>(5, 5, 5);
		Vector3<double> b = Vector3<double>(-2, 7, 14);

		Vector3<double> add = a + b;
		Vector3<double> sub = a - b;
		Vector3<double> mul = b * 0.3;
		Vector3<double> mul1 = 0.3 * b;
		double dot = Vector3<double>::dot(a, b);
		Vector3<double> cross = Vector3<double>::cross(a, b);

		std::cout << "Adding: x: " << add.x << " y: " << add.y << " z: " << add.z << std::endl;
		std::cout << "Subtracting: x: " << sub.x << " y: " << sub.y << " z: " << sub.z << std::endl;
		std::cout << "Multiplying by a scalar: x: " << mul.x << " y: " << mul.y << " z: " << mul.z << std::endl;
		std::cout << "Dot Product: " << dot << std::endl;
		std::cout << "Cross Product: x: " << cross.x << " y: " << cross.y << " z: " << cross.z << std::endl;

		std::cout << "Testing commutitivity of multiplication by scalar:" << std::endl;
		std::cout << "Vector3 * lambda: x: " << mul.x << " y: " << mul.y << " z: " << mul.z << std::endl;
		std::cout << "lambda * Vector3: x: " << mul1.x << " y: " << mul1.y << " z: " << mul1.z << std::endl;

		std::cout << "Angle between a and b : " << Vector3<double>::angle(a, b) << std::endl;
	}

	std::cout << "-============ Vector2 test =============-" << std::endl;
	{
		Vector2<double> a = {3, 1};
		Vector2<double> b = {1, 2};

		std::cout << "a.x: " << a.x << " a.y: " << a.y << std::endl;
		std::cout << "b.x: " << b.x << " b.y: " << b.y << std::endl;
		std::cout << std::endl;

		Vector2<double> add = a + b;
		Vector2<double> sub = a - b;
		Vector2<double> mul = a * 2.;
		double dot = Vector2<double>::dot(a, b);

		std::cout << "Adding: x: " << add.x << " y: " << add.y << std::endl;
		std::cout << "Subtracting: x: " << sub.x << " y: " << sub.y << std::endl;
		std::cout << "Multiplying by a scalar: x: " << mul.x << " y: " << mul.y << std::endl;
		std::cout << "Dot: x: " << dot << std::endl;

		std::cout << "Angle between a and b : " << Vector2<double>::angle(a, b) << std::endl;
	}

	std::cout << "-============ Vector2 conversion test =============-" << std::endl;
	{
		Vector2<double> dbl_vector(3.14, 5.8);
		std::cout << dbl_vector << std::endl;
		std::cout << static_cast<Vector2<int>>(dbl_vector) << std::endl;
		Vector2<int> int_vector(1, 4);
		std::cout << int_vector << std::endl;
		std::cout << static_cast<Vector2<double>>(int_vector) + dbl_vector << std::endl;
		std::cout << Vector2<double>::dot(int_vector, dbl_vector) << std::endl;
	}

	std::cout << "-============ Vector3 conversion test =============-" << std::endl;
	{
		Vector3<double> dbl_vector(36.14, 54.8, 12.2);
		std::cout << dbl_vector << std::endl;
		std::cout << static_cast<Vector3<int>>(dbl_vector) << std::endl;
		Vector3<int> int_vector(120, 4, 89);
		std::cout << int_vector << std::endl;
		std::cout << static_cast<Vector3<double>>(int_vector) + dbl_vector << std::endl;
		std::cout << Vector3<double>::dot(int_vector, dbl_vector) << std::endl;
	}
}