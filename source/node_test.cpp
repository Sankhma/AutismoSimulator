#include <iostream>
#include "Matrix.h"

int main() {
	Node n1 = Node(420);
	Node n2 = Node(69);

	std::cout << n1.value << ", " << n2.value << std::endl;

	Node::swapValues(&n1, &n2);

	std::cout << n1.value << ", " << n2.value << std::endl;

	return 0;
}