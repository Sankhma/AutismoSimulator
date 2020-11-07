#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m = {3, 5};

	std::cout << "Rows: " << m.rows << std::endl;
	std::cout << "Columns: " << m.columns << std::endl;

	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.columns; j++)
		{
			// std::cout << "[" << i << "][" << j << "] = ";
			auto row = m[i];
			// std::cout << "Got row (Pair)." << std::endl;
			auto cell = row[j];
			// std::cout << "Got cell (double)." << std::endl;

			// m[i][j] << ", ";
			std::cout << "Value = " << cell << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}