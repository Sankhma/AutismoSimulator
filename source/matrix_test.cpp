#include <iostream>
#include "Matrix.h"

int main() {
	Matrix m = {3, 2};

	std::cout << "Size of Matrix m: " << m.rows << " x " << m.columns << std::endl;
	m.root = new LinkedList();
	m.root->value = 420;
	std::cout << m.root->value << std::endl;

	return 0;
}