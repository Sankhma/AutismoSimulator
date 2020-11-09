#include "Matrix.h"


Node::Node() : value(0), next(nullptr) {}

Node::Node(const double &value) : value(value), next(nullptr) {}

void Node::swapValues(Node *n1, Node *n2) {
	auto temp = n1->value;
	n1->value = n2->value;
	n2->value = temp;
}


LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::addNode(const double &value) {
	Node *tmp = new Node(value);

	if (head == nullptr) {
		head = tail = tmp;
	} else {
		tail = tail->next = tmp;
	}
}

LinkedList LinkedList::copy() const {
	LinkedList newList = LinkedList();
	Node *node = head;
	while (node != nullptr) {
		newList.addNode(node->value);
		node = node->next;
	}
	return newList;
}

double& LinkedList::operator[](const int &index) {
	if (head == nullptr) throw std::runtime_error("The LinkedList is empty.");
	Node *node = head;
	for (unsigned int i = 0; i < index; i++) {
		node = node->next;
		if (node == nullptr) throw std::runtime_error("Out of range.");
	}
	return node->value;
}


Node& Matrix::operator[](const int &index) const {
	Node *cell = data.head;
	for (int i = 0; i < index * columns; i++) {
		cell = cell->next;
	}
	return *cell;
}

double& Node::operator[](const int &index) {
	Node *cell = this;
	for (int i = 0; i < index; i++) {
		cell = cell->next;
	}
	return cell->value;
}

// no use pls
void Matrix::transpose() {
	LinkedList old = data.copy();
	Node *n1 = data.head->next;
	unsigned int iters = rows * columns - 1;
	for (unsigned int i = 1; i < iters; i++) {
		n1->value = old[(i * columns) % iters];
		n1 = n1->next;
	}
	unsigned int temp = rows;
	rows = columns;
	columns = temp;
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
