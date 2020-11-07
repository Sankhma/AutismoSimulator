#include "Matrix.h"


Node::Node() : value(0), next(nullptr) {}
Node::Node(const double &value) : value(value), next(nullptr) {}


LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::addNode(const double &value) {
	Node *tmp = new Node(value);

	if (head == nullptr) {
		head = tail = tmp;
	} else {
		tail = tail->next = tmp;
	}
}


Node Matrix::operator[](const int &index) {
	Node *cell = data.head;
	for (int i = 0; i < index * columns; i++) {
		cell = cell->next;
	}
	return *cell;
}

// Coś tu jest nie tak, bo nie mogę zmieniać wartości w pierwszej kolumnie (m[x][0])
double& Node::operator[](const int &index) {
	Node *cell = this;
	for (int i = 0; i < index; i++) {
		cell = cell->next;
	}
	return cell->value;
}


Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
	data = LinkedList();
	for (int i = 0; i < rows * columns; i++) {
		data.addNode(0);
	}
}

double& Matrix::operator()(const int& row, const int& col) const{
	Node* cell = data.head;
	for(int i=0; i < row * columns + col; i++){
		cell = cell->next;
	}
	return cell->value;
}
