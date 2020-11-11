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
	for (unsigned int i = 0; i < index * columns; i++) {
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

// double& Matrix::operator()(const int& row, const int& col) const{
// 	Node* cell = data.head;
// 	for(int i=0; i < row * columns + col; i++){
// 		cell = cell->next;
// 	}
// 	return cell->value;
// }

std::ostream& operator<<(std::ostream &os, const Matrix &matrix) {
	Node *node = matrix.data.head;
	short min = 0, max = 0;
	for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
		if (node->value > max) max = node->value;
		if (node->value < min) min = node->value;
		node = node->next;
	}
	short minLen = std::to_string(min).size(), maxLen = std::to_string(max).size();
	short digits = minLen > maxLen ? minLen : maxLen;

	node = matrix.data.head;
	os << '[';
	for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
		if (i % matrix.columns == 0 && i != matrix.rows * matrix.columns) os << ' ';
		os << std::setw(digits) << node->value;
		node = node->next;
		os << ((i != 1) ? (((i - 1) % matrix.columns == 0) ? "\n" : ", ") : "]");
	}
	return os;
}
