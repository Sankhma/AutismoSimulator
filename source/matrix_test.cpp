#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m = {3, 2};

	std::cout << "Size of Matrix m: " << m.rows << " x " << m.columns << std::endl;
	std::cout << "Cell" << std::endl;

	return 0;
}