#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m = {3, 2};

	std::cout << "Rows: " << m.rows << std::endl;
	std::cout << "Columns: " << m.columns << std::endl;

	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.columns; j++)
		{
			std::cout << m[i][j] << ", ";
		}
		std::cout << std::endl;
	}

	return 0;
}