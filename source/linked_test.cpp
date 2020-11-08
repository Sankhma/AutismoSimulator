#include <iostream>
#include "Matrix.h"

void displayList(const LinkedList &list) {
	Node *current = list.head;
	while (current != nullptr) {
		std::cout << current->value << ", ";
		current = current->next;
	}
	std::cout << std::endl;
}

int main() {
	LinkedList list1 = LinkedList();
	for (int i = 0; i < 10; i++) {
		list1.addNode(i);
	}
	
	std::cout << "list1: ";
	displayList(list1);
	
	LinkedList list2 = list1.copy();

	list1[3] = 69;

	std::cout << "list1: ";
	displayList(list1);
	std::cout << "list2: ";
	displayList(list2);


	return 0;
}