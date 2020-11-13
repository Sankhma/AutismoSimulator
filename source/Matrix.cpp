#include "Matrix.h"
#include <iomanip>


Node::Node() : value(0), next(nullptr) {}

Node::Node(const double &value) : value(value), next(nullptr) {}

void Node::swapValues(Node *n1, Node *n2) {
	// change auto
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

double& LinkedList::operator[](const unsigned int &index) {
	if (head == nullptr) throw std::runtime_error("The LinkedList is empty.");
	Node *node = head;
	for (unsigned int i = 0; i < index; i++) {
		node = node->next;
		if (node == nullptr) throw std::runtime_error("Out of range.");
	}
	return node->value;
}


Node& Matrix::operator[](const unsigned int &index) const {
	Node *cell = data.head;
	for (unsigned i = 0; i < index * columns; i++) {
		cell = cell->next;
	}
	return *cell;
}

double& Node::operator[](const unsigned int &index) {
	Node *cell = this;
	for (unsigned int i = 0; i < index; i++) {
		cell = cell->next;
	}
	return cell->value;
}


Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
	data = LinkedList();
	for (unsigned int i = 0; i < rows * columns; i++) {
		data.addNode(0);
	}
}

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

void Matrix::multiplyRow(const unsigned &index, const double &lambda) {
	Node *node = &(*this)[index];
	for (unsigned i = 0; i < columns; i++) {
		node->value *= lambda;
		node = node->next;
	}
}

void Matrix::shuffleRows(unsigned index1, unsigned index2) {
	if (index1 == index2) return; // baka
	if (index1 >= rows || index2 >= rows) {
		throw std::out_of_range("Element out of range. Expected non-negative indices lesser than " + std::to_string(rows) + ". Indices provided: " + std::to_string(index1) + ", " + std::to_string(index2) + ".\n");
	}
	if (index1 > index2) {
		unsigned temp = index1;
		index1 = index2;
		index2 = temp;
	}
	Node *a1 = index1 ? &get(index1 * columns - 1) : nullptr, *b1 = &get(index2 * columns),
	     *a2 = &get((index1 + 1) * columns - 1),              *b2 = (index2 == rows - 1) ? nullptr : &get((index2 + 1) * columns),
	     *a3 = &get(index2 * columns - 1),                    *b3 = &get(index1 * columns),
	     *a4 = &get((index2 + 1) * columns - 1),              *b4 = &get((index1 + 1) * columns);
	
	(index1 ? a1->next : data.head) = b1;
	a2->next = (index2 + 1 == rows ? nullptr : b2);
	if (index2 - index1 == 1) {
		a4->next = b3;
	} else {
		a3->next = b3;
		a4->next = b4;
	}
}

void Matrix::addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, bool addition) {
	Node *sourceNode = &(*this)[sourceIndex];
	Node *targetNode = &(*this)[targetIndex];
	for (unsigned i = 0; i < columns; i++) {
		targetNode->value += sourceNode->value * (addition ? 1 : -1);
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}
}

Node& Matrix::get(const unsigned &index) const {
	Node *node = data.head;
	for (unsigned i = 0; i < index; i++) {
		node = node->next;
	}
	return *node;
}

Matrix Matrix::operator+(const Matrix& other) const{
	if(this->rows != other.rows || this->columns != other.columns) throw std::runtime_error("The Matrices are not of the same size. Addition is not defined.");
	Matrix result = Matrix(this->rows, this->columns);
	for(unsigned int i=0; i < result.rows; i++){
		for(unsigned int j=0; j < result.columns; j++){
			result[i][j] = (*this)[i][j] + other[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& other) const{
	if(this->rows != other.rows || this->columns != other.columns) throw std::runtime_error("The Matrices are not of the same size. Subtraction is not defined.");	
	Matrix result = Matrix(this->rows, this->columns);
	for(unsigned int i=0; i < result.rows; i++){
		for(unsigned int j=0; j < result.columns; j++){
			result[i][j] = (*this)[i][j] - other[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
	if (columns != other.rows) throw std::runtime_error("The numbers of columns of the left Matrix and rows of the right Matrix are not equal.");
	Matrix result = Matrix(rows, other.columns);
	for (unsigned int y = 0; y < result.rows; y++) {
		for (unsigned int x = 0; x < result.columns; x++) {
			for (unsigned int i = 0; i < columns; i++) {
				result[y][x] += (*this)[y][i] * other[i][x];
			}
		}
	}
	return result;
}

// double& Matrix::operator()(const int& row, const int& col) const{
// 	Node* cell = data.head;
// 	for(int i=0; i < row * columns + col; i++){
// 		cell = cell->next;
// 	}
// 	return cell->value;
// }

std::ostream& operator<<(std::ostream &os, const Matrix &matrix) {
	Node *node = matrix.data.head;
	// Commented out because it's completely useless at the moment.
	// short maxLen = 0;
	// for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
	// 	short len = std::to_string(node->value).length();
	// 	if (len > maxLen) maxLen = len;
	// 	node = node->next;
	// }
	// node = matrix.data.head;
	os << '[';
	for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
		if (i % matrix.columns == 0 && i != matrix.rows * matrix.columns) os << ' ';
		os << std::setw(8) << node->value;
		node = node->next;
		os << ((i != 1) ? (((i - 1) % matrix.columns == 0) ? "\n" : ", ") : "]");
	}
	return os;
}
