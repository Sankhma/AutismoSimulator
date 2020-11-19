#include <iostream>
#include "Matrix.h"

int main() {
	auto n1 = Node<float>();
	auto n2 = Node<float>(420);

	std::cout << n1.value << ", " << n2.value << std::endl;

	Node<float>::swapValues(&n1, &n2);

	std::cout << n1.value << ", " << n2.value << std::endl;

	return 0;
}