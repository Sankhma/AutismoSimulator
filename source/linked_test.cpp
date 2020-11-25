#include <iostream>
#include "Matrix.h"

int main() {
	auto list = LinkedList<int>();

	for (int i = 0; i < 5; i++) {
		list.add(i);
	}

	return 0;
}