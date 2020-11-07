#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns), root(new LinkedList()) {
	LinkedList *cell = root;
	for (int i = 0; i < rows * columns - 1; i++)
	{
		cell->next = new LinkedList();
		cell = cell->next;
	}
}

LinkedList::LinkedList() : value(0), next(nullptr) {}
LinkedList::LinkedList(const double &value) : value(value), next(nullptr) {}
LinkedList::LinkedList(const double &value, LinkedList *next) : value(value), next(next) {}

Pair::Pair(LinkedList *elem, const unsigned int &n) : elem(elem), n(n) {}

Pair Matrix::operator[](const int &index) const {
	// if (index >= rows) throw std::out_of_range("Out of range.");
	LinkedList *cell = root;
	for (int i = 0; i < index; i++) {
		cell = cell->next;
	}
	return Pair(cell, columns);
}

double Pair::operator[](const int &index) {
	std::cout << "Getting cell in column " << index << "..." << std::endl;
	LinkedList *cell = this->elem;
	std::cout << "Assigned this->elem to *cell." << std::endl;
	unsigned int columns = this->n;
	std::cout << "Assigned this->n to columns." << std::endl;
	// if (index >= columns) throw std::out_of_range("Out of range.");
	for (int i = 0; i < index * columns; i++) {
		cell = cell->next;
		std::cout << "Moved to next." << std::endl;
	}
	std::cout << "End of the loop." << std::endl;
	return cell->value;
}
