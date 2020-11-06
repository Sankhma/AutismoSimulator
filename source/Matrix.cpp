#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
	
}

void Matrix::transpose() {

}

// Matrix Matrix::transpose(const Matrix &m) {

// }

LinkedList Matrix::operator()(const std::size_t &rowIndex, const std::size_t &colIndex) {
	LinkedList *cell = root;
	for (std::size_t index = 0, end = colIndex + rowIndex * columns; index < end; index++) {
		cell = cell->next;
	}
	return *cell;
}

// LinkedList LinkedList::operator[](const size_t &index) {

// }
