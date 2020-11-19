#include "Matrix.h"
#include "Vector.h"
#include <iomanip>


//-============ Node =============-

template<typename T>
Node<T>::Node() : value(T()), next(nullptr) {}

template<typename T>
Node<T>::Node(const T &value) : value(value), next(nullptr) {}

template<typename T>
void Node<T>::swapValues(Node *n1, Node *n2) {
	T temp = n1->value;
	n1->value = n2->value;
	n2->value = temp;
}


//-============ LinkedList =============-

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
void LinkedList<T>::addNode(const T &value) {
	Node<T> *tmp = new Node<T>(value);

	if (head == nullptr) {
		head = tail = tmp;
	} else {
		tail = tail->next = tmp;
	}
}

template<typename T>
LinkedList<T> LinkedList<T>::copy() const {
	LinkedList<T> newList = LinkedList<T>();
	Node<T> *node = head;
	while (node != nullptr) {
		newList.addNode(node->value);
		node = node->next;
	}
	return newList;
}

template<typename T>
T& LinkedList<T>::operator[](const unsigned &index) {
	if (head == nullptr) throw std::runtime_error("The LinkedList is empty.");
	Node<T> *node = head;
	for (unsigned int i = 0; i < index; i++) {
		node = node->next;
		if (node == nullptr) {
			throw std::out_of_range("Element out of range. Expected a non-negative integer index lesser than " + std::to_string(i) + ". Index provided: " + std::to_string(index) + ".\n");
		}
	}
	return node->value;
}


//-============ Matrix =============-

template<typename T>
Node<T>& Matrix<T>::operator[](const unsigned &index) const {
	Node<T> *cell = data.head;
	for (unsigned i = 0; i < index * columns; i++) {
		cell = cell->next;
	}
	return *cell;
}


//-============ Node =============-

template<typename T>
T& Node<T>::operator[](const unsigned &index) {
	Node<T> *cell = this;
	for (int i = 0; i < index; i++) {
		cell = cell->next;
	}
	return cell->value;
}


//-============ Matrix =============-

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns), data(LinkedList<T>()) {
	if (rows < 1 || columns < 1) {
		throw std::runtime_error("Invalid size. Each dimension must be a positive integer. Values provided: " + std::to_string(rows) + ", " + std::to_string(columns) + ".\n");
	}
	for (int i = 0; i < rows * columns; i++) {
		data.addNode(T());
	}
}

template<typename T>
void Matrix<T>::transpose() {
	LinkedList<T> old = data.copy();
	Node<T> *n1 = data.head->next;
	unsigned int iters = rows * columns - 1;
	for (unsigned int i = 1; i < iters; i++) {
		n1->value = old[(i * columns) % iters];
		n1 = n1->next;
	}
	unsigned int temp = rows;
	rows = columns;
	columns = temp;
}

template<typename T>
void Matrix<T>::multiplyRow(const unsigned &index, const double &lambda) {
	if (index >= rows) {
		throw std::out_of_range("Element out of range. Expected non-negative integer index lesser than " + std::to_string(rows) + ". Index provided: " + std::to_string(index) + ".\n");
	}
	if (lambda == 0) {
		throw std::runtime_error("Cannot multiply matrix rows by zero.\n");
	}
	Node<T> *node = &(*this)[index];
	for (unsigned i = 0; i < columns; i++) {
		node->value *= lambda;
		node = node->next;
	}
}

template<typename T>
void Matrix<T>::shuffleRows(unsigned index1, unsigned index2) {
	if (index1 == index2) return; // baka
	if (index1 >= rows || index2 >= rows) {
		throw std::out_of_range("Element out of range. Expected non-negative integer indices lesser than " + std::to_string(rows) + ". Indices provided: " + std::to_string(index1) + ", " + std::to_string(index2) + ".\n");
	}
	if (index1 > index2) {
		unsigned temp = index1;
		index1 = index2;
		index2 = temp;
	}
	Node<T> *a1 = index1 ? &get(index1 * columns - 1) : nullptr, *b1 = &get(index2 * columns),
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
	data.tail = &get(rows * columns - 1);
}

template<typename T>
void Matrix<T>::addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, const double &lambda) {
	if (sourceIndex >= rows || targetIndex >= rows) {
		throw std::out_of_range("Element out of range. Expected non-negative integer indices lesser than " + std::to_string(rows) + ". Indices provided: " + std::to_string(sourceIndex) + ", " + std::to_string(targetIndex) + ".\n");
	}
	Node<T> *sourceNode = &(*this)[sourceIndex];
	Node<T> *targetNode = &(*this)[targetIndex];
	for (unsigned i = 0; i < columns; i++) {
		targetNode->value += sourceNode->value * lambda;
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}
}

template<typename T>
Node<T>& Matrix<T>::get(const unsigned &index) const {
	if (index >= rows * columns) {
		throw std::out_of_range("Element out of range. Expected non-negative integer index lesser than " + std::to_string(rows * columns) + ". Index provided: " + std::to_string(index) + ".\n");
	}
	Node<T> *node = data.head;
	for (unsigned i = 0; i < index; i++) {
		node = node->next;
	}
	return *node;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const{
	if(this->rows != other.rows || this->columns != other.columns) throw std::runtime_error("The Matrices are not of the same size. Addition is not defined.");
	Matrix<T> result = Matrix<T>(this->rows, this->columns);
	for(unsigned int i=0; i < result.rows; i++){
		for(unsigned int j=0; j < result.columns; j++){
			result[i][j] = (*this)[i][j] + other[i][j];
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) const{
	if(this->rows != other.rows || this->columns != other.columns) throw std::runtime_error("The Matrices are not of the same size. Subtraction is not defined.");	
	Matrix<T> result = Matrix<T>(this->rows, this->columns);
	for(unsigned int i=0; i < result.rows; i++){
		for(unsigned int j=0; j < result.columns; j++){
			result[i][j] = (*this)[i][j] - other[i][j];
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &other) const {
	if (columns != other.rows) throw std::runtime_error("The numbers of columns of the left Matrix and rows of the right Matrix are not equal.");
	Matrix<T> result = Matrix<T>(rows, other.columns);
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

// template<typename T>
// struct Matrix;
// template<typename T>
// std::ostream& operator<<(std::ostream &os, const Matrix<T> &matrix) {
// 	Node<T> *node = matrix.data.head;
// 	// Commented out because it's completely useless at the moment.
// 	// short maxLen = 0;
// 	// for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
// 	// 	short len = std::to_string(node->value).length();
// 	// 	if (len > maxLen) maxLen = len;
// 	// 	node = node->next;
// 	// }
// 	// node = matrix.data.head;
// 	os << '[';
// 	for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
// 		if (i % matrix.columns == 0 && i != matrix.rows * matrix.columns) os << ' ';
// 		os << std::setw(8) << node->value;
// 		node = node->next;
// 		os << ((i != 1) ? (((i - 1) % matrix.columns == 0) ? "\n" : ", ") : "]");
// 	}
// 	return os;
// }

template class Matrix<char>;
template class Matrix<unsigned char>;
template class Matrix<short>;
template class Matrix<unsigned short>;
template class Matrix<int>;
template class Matrix<unsigned>;
template class Matrix<long>;
template class Matrix<unsigned long>;
template class Matrix<long long>;
template class Matrix<unsigned long long>;
template class Matrix<float>;
template class Matrix<double>;

//-============ AugmentedMatrix =============-

AugmentedMatrix::AugmentedMatrix(const Matrix<double>& main, const Matrix<double>& augment){
	if(main.columns > main.rows || main.rows != augment.rows) throw std::runtime_error("Main matrix has to represent a set of equation with 0 degrees of freedom. Augment matrix has to have same no. of rows as main.");
	this->main = main;
	this->augment = augment;
}

AugmentedMatrix::AugmentedMatrix(const unsigned int& size){
	this->main = Matrix<double>(size, size);
	this->augment = Matrix<double>(size, 1);
}

AugmentedMatrix::AugmentedMatrix(const unsigned int& rows, const unsigned int& columns){
	if(columns > rows) throw std::runtime_error("Main matrix has to represent a set of equation with 0 degrees of freedom.");
	this->main = Matrix<double>(rows, columns);
	this->augment = Matrix<double>(rows, 1);
}

void AugmentedMatrix::multiplyRow(const unsigned &index, const double &lambda) {
	main.multiplyRow(index, lambda);
	augment.multiplyRow(index, lambda);
}

void AugmentedMatrix::shuffleRows(unsigned index1, unsigned index2) {
	main.shuffleRows(index1, index2);
	augment.shuffleRows(index1, index2);
}

void AugmentedMatrix::addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, const double &lambda) {
	main.addRowToRow(sourceIndex, targetIndex, lambda);
	augment.addRowToRow(sourceIndex, targetIndex, lambda);
}

void AugmentedMatrix::solve() {
	unsigned y;
	double pivot;
	for (unsigned x = 0; x < main.columns; x++) {
		for (unsigned i = x; i < main.rows; i++) {
			pivot = main[i][x];
			if (pivot != 0) {
				y = i;
				break;
			}
		}
		if (pivot == 0) {
			break;
		}
		if (y != x) {
			shuffleRows(x, y);
			y = x;
		}
		if (pivot != 1) {
			multiplyRow(y, 1.0 / pivot);
		}
		for (unsigned i = y + 1; i < main.rows; i++) {
			addRowToRow(y, i, -main[i][x]);
		}
	}
	for (unsigned x = main.columns - 1; x > 0; x--) {
		if (main[x][x] != 1) {
			continue;
		}
		for (unsigned y = 0; y < x; y++) {
			addRowToRow(x, y, -main[y][x]);
		}
	}
}

std::ostream& operator<<(std::ostream &os, const AugmentedMatrix &m) {
	os << '[';
	for (unsigned i = 0; i < m.main.rows; i++) {
		if (i != 0) os << ' ';
		for (unsigned j = 0; j < m.main.columns; j++) {
			os << std::setw(8) << m.main[i][j] << ' ';
		}
		os << '|';
		for (unsigned j = 0; j < m.augment.columns; j++) {
			os << ' ' << std::setw(8) << m.augment[i][j];
		}
		os << (i != m.main.rows - 1 ? '\n' : ']');
	}
	return os;
}
