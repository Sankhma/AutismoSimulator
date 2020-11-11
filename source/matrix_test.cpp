#include <iostream>
#include "Matrix.h"

int main() {
	// Matrix m1 = Matrix(3, 2);
	// Matrix m2 = Matrix(4, 4);
	// Matrix m3 = Matrix(5, 6);

	// std::cout << "m1:\n";

	// std::cout << "m2:\n";

	// std::cout << "m3:\n";

	Matrix m4 = {3, 3};
	m4[0][0] = 1, m4[0][1] = 2, m4[0][2] = 3;
	m4[1][0] = 420, m4[1][1] = 5, m4[1][2] = 6;
	m4[2][0] = 7, m4[2][1] = 8, m4[2][2] = 9;

	std::cout << "m4:\n" << m4 << '\n';

	Matrix m5 = {5, 3};
	m5[0][0] = 1, m5[0][1] = 2, m5[0][2] = 3;
	m5[1][0] = 4, m5[1][1] = 5, m5[1][2] = 6;
	m5[2][0] = 7, m5[2][1] = 8, m5[2][2] = -69;
	m5[3][0] = 10, m5[3][1] = 11, m5[3][2] = 12;
	m5[4][0] = 13, m5[4][1] = 14, m5[4][2] = 15;

	std::cout << "m5:\n" << m5 << '\n';

	// m5.transpose();
	// std::cout << "m5 transposed:\n";
	// displayMatrix(m5);

	// m5.transpose();
	// std::cout << "m5 transposed again:\n";

	// std::cout << "m5 * m4:\n";

	std::cout << "m4 + m4" << std::endl;
	std::cout << m4 + m4 << std::endl;

	std::cout << "m4 - m4" << std::endl;
	std::cout << m4 - m4 << std::endl;

	return 0;
}