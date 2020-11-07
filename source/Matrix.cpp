#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
	std::cout << "Constructing " << rows << " x " << columns << " matrix." << std::endl;
	LinkedList *cell = root;
	std::cout << "cell = root" << std::endl;
	for (int i = 0; i < rows * columns - 1; i++)
	{
		std::cout << "rows * columns = " << rows * columns << std::endl;
		cell->next = new LinkedList();
		std::cout << "New LinkedList pointer." << std::endl;
		cell = cell->next;
		std::cout << "cell = cell->next. End of iteration." << std::endl;
	}
	std::cout << "End of loop." << std::endl;
	
}

// LinkedList Matrix::operator()(const std::size_t &rowIndex, const std::size_t &colIndex) {
// 	LinkedList *cell = root;
// 	for (std::size_t index = 0, end = colIndex + rowIndex * columns; index < end; index++) {
// 		cell = cell->next;
// 	}
// 	return *cell;
// }

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
	LinkedList *cell = this->elem;
	unsigned int columns = this->n;
	// if (index >= columns) throw std::out_of_range("Out of range.");
	for (int i = 0; i < index * columns; i++) {
		cell = cell->next;
	}
	return cell->value;
}

LinkedList::LinkedList() {
	value = 0;
	next = nullptr;
}

LinkedList::LinkedList(const double &value) : value(value), next(nullptr) {}
