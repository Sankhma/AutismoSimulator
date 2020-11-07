#include "Matrix.h"


Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
	data = new LinkedList();
	for (int i = 0; i < rows * columns; i++)
	{
		data->addNode(i);
		std::cout << "Added " << i << std::endl;
	}
}


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


Pair::Pair(Node *elem, const unsigned int &n) : elem(elem), n(n) {}

Pair Matrix::operator[](const int &index) const {
	// if (index >= rows) throw std::out_of_range("Out of range.");
	Node *cell = data->head;
	for (int i = 0; i < index; i++) {
		cell = cell->next;
	}
	return Pair(cell, rows);
}

double Pair::operator[](const int &index) {
	Node *cell = this->elem;
	unsigned int rows = this->n;
	// if (index >= columns) throw std::out_of_range("Out of range.");
	for (int i = 0; i < (index * rows); i++) {
		cell = cell->next;
	}
	return cell->value;
}
