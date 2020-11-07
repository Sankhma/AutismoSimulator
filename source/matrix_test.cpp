#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m1 = Matrix(3, 2);
	Matrix m2 = Matrix(4, 4);
	Matrix m3 = Matrix(5, 6);

	for (int i = 0; i < m1.rows; i++) {
		for (int j = 0; j < m1.columns; j++)
		{
			std::cout << "m1[" << i << "][" << j << "] = " << m2[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < m2.rows; i++) {
		for (int j = 0; j < m2.columns; j++)
		{
			std::cout << "m2[" << i << "][" << j << "] = " << m2[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < m3.rows; i++) {
		for (int j = 0; j < m3.columns; j++)
		{
			std::cout << "m3[" << i << "][" << j << "] = " << m3[i][j] << ", ";
		}
		std::cout << std::endl;
	}

	return 0;
}