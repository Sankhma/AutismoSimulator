#pragma once

#include <cstddef>
#include <iostream>
#include <iomanip>

#include "Vector.h"

template<typename T>
/**
 * Data structure used to store a value and a pointer to the next Node.
 * Meant to be instantiated by LinkedList class only.
 */
struct Node {
	T value; // Value to be stored.
	Node<T> *next;   // Pointer to the next Node.

	/**
	 * Constructor for the Node class.
	 * 
	 * @returns A new Node object.
	 */
	Node() : value(T()), next(nullptr) {};

	/**
	 * Constructor for the Node class.
	 * 
	 * @param value The value to be stored in the node.
	 * @overload
	 */
	Node(const T &value) : value(value), next(nullptr) {};

	/**
	 * Swap values of two given Nodes.
	 * 
	 * @param *n1,*n2 Pointers to the Nodes.
	 */
	static void swapValues(Node *n1, Node *n2) {
		T temp = n1->value;
		n1->value = n2->value;
		n2->value = temp;
	};

	/**
	 * Access the value of the n-th next Node.
	 * 
	 * @param index Index of the desired Node.
	 * @returns Value of the desired Node.
	 */
	T& operator[](const unsigned int &index) {
		Node<T> *cell = this;
		for(unsigned i = 0; i < index; i++) {
			cell = cell->next;
		}
		return cell->value;
	};
};

template<typename T>
/**
 * Data structure used to store Node objects.
 * 
 * @see Node
 */
struct LinkedList {
	Node<T> *head; // Pointer to the first element of the list.
	Node<T> *tail; // Pointer to the last element of the list.

	/**
	 * Constructor for the LinkedList class.
	 * 
	 * @returns A new LinkedList object.
	 */
	LinkedList() : head(nullptr), tail(nullptr) {};

	/**
	 * Add a node to the end of the list.
	 * 
	 * @param value Value to be added to the list.
	 */
	void addNode(const T &value) {
		//Potential memory leak???
		Node<T> *tmp = new Node<T>(value);
		if(head == nullptr) {
			head = tail = tmp;
		} else{
			tail = tail->next = tmp;
		}
	};

	/**
	 * Create a shallow copy of the list.
	 * 
	 * @returns A new LinkedList object with identical values.
	 */
	LinkedList<T> copy() const {
		LinkedList<T> newList = LinkedList<T>();
		Node<T> *node = head;
		while(node != nullptr) {
			newList.addNode(node->value);
			node = node->next;
		}
		return newList;
	};

	/**
	 * Access the n-th element of the list.
	 * 
	 * @param index Index of the desired element.
	 * @returns Value of the desired element.
	 * @throws std::runtime_error Thrown if the list is empty.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 */
	T& operator[](const unsigned int &index) {
		if(head == nullptr) throw std::runtime_error("The LinkedList is empty.");
		Node<T> *node = head;
		for(unsigned i = 0; i < index; i++) {
			node = node->next;
			if(node == nullptr)
				throw std::out_of_range("Element out of range. Expected a non-negative integer index lesser than " + std::to_string(i) + ". Index provided: " + std::to_string(index) + ".\n");
		}
		return node->value;
	};
};

template<typename T>
/**
 * Data structure representing a rectangular array of numbers, arranged in rows and columns.
 * 
 * @see LinkedList
 */
struct Matrix {
    unsigned int rows;    // The amount of rows of the matrix.
    unsigned int columns; // The amount of columns of the matrix.
	LinkedList<T> data;      // Data stored in the matrix.

	/**
	 * Constructor for the Matrix class.
	 * 
	 * @param rows The amount of the rows of the new matrix.
	 * @param columns The amount of the columns of the new matrix.
	 * @param rand Optional, false by default. If true, each cell will be given a random value.
	 * @returns A new Matrix object.
	 * @throws std::runtime_error Thrown if any of the dimensions provided is invalid.
	 */
    Matrix(unsigned rows = 1, unsigned columns = 1, bool rand = false, T value = 0) {
		if(rows < 1 || columns < 1)
			throw std::runtime_error("Invalid size. Each dimension must be a positive integer. Values provided: " + std::to_string(rows) + ", " + std::to_string(columns) + ".\n");
		if(!rand) {
			//TODO: generate random number up to value if value > 0
		} else {
			data.addNode(value);
		}
	};

	/**
	 * 
	 */
	// deprecated
	// static Matrix MatrixRandom(const unsigned &rows = 1, const unsigned &columns = 1);

	/**
	 * Flip the matrix over its diagonal.
	 * (Switch the row and column indices.)
	 */
	void transpose() {
		LinkedList<T> old = data.copy();
		Node<T> *n1 = data.head->next;
		unsigned iters = rows * columns - 1;
		for(unsigned i = 1; i < iters; i++) {
			n1->value = old[(i * columns) % iters];
			n1 = n1->next;
		}
		unsigned temp = rows;
		rows = columns;
		columns = temp;
	};

	/**
	 * Multiply the chosen row by the given value.
	 * 
	 * @param index Row index to multiply (0-based).
	 * @param lambda Scalar by which to multiply.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 * @throws std::runtime_error Thrown if lambda is equal to zero.
	 */
	void multiplyRow(const unsigned &index, const double &lambda) {
		if(index >=rows)
			throw std::out_of_range("Element out of range. Expected non-negative integer index lesser than " + std::to_string(rows) + ". Index provided: " + std::to_string(index) + ".\n");
		if(lambda = 0)
			throw std::runtime_error("Cannot multiply matrix rows by zero.\n");
		Node<T> *node = &(*this)[index];
		for(unsigned i = 0; i < columns; i++) {
			node->value *= lambda;
			node = node->next;
		}
	};

	/**
	 * Shuffle two chosen rows of the matrix.
	 * 
	 * @param index1 Index of the first row to shuffle.
	 * @param index2 Index of the second row to shuffle.
	 * @throws std::out_of_range Thrown if any of the indices provided is invalid.
	 */
	void shuffleRows(unsigned &index1, unsigned &index2) {
		if(index1 == index2) return; // baka
		if(index1 >= rows || index2 >= rows)
			throw std::out_of_range("Element out of range. Expected non-negative integer indices lesser than " + std::to_string(rows) + ". Indices provided: " + std::to_string(index1) + ", " + std::to_string(index2) + ".\n");
		if(index1 > index2) {
			unsigned temp = index1;
			index1 = index2;
			index2 = temp;
		}
		// TODO: Someone check this pls!!!
		Node<T> *a1 = index1 ? &get(index1 * columns - 1) : nullptr, *b1 = &get(index2 * columns),
				*a2 = &get((index1 + 1) * columns - 1),				 *b2 = (index2 == rows - 1) ? nullptr : &get((index2 + 1) * columns),
				*a3 = &get(index2 * columns - 1),					 *b3 = &get(index1 * columns),
				*a4 = &get((index2 + 1) * columns - 1),				 *b4 = &get((index1 + 1) * columns);
		(index1 ? a1->next : data.head) = b1;
		a2->next = (index2 + 1 == rows ? nullptr : b2);
		if(index2 - index1 == 1) {
			a4->next = b3;
		} else {
			a3->next = b3;
			a4->next = b4;
		}
		data.tail = &get(rows * columns - 1);
	};

	/**
	 * Adds one row to another one.
	 * 
	 * @param sourceIndex The index of the row whose values are added.
	 * @param targetIndex The index of the row whose values are added to.
	 * @param lambda Optional, 1 by default. Source row will be multiplied by this value before being added.
	 * @throws std::out_of_range Thrown if any of the indices provided is invalid.
	 */
	void addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, const double &lambda = 1) {
		if(sourceIndex >= rows || targetIndex >= rows)
			throw std::out_of_range("Element out of range. Expected non-negative integer indices lesser than " + std::to_string(rows) + ". Indices provided: " + std::to_string(sourceIndex) + ", " + std::to_string(targetIndex) + ".\n");
		Node<T> *sourceNode = &(*this)[sourceIndex];
		Node<T> *targetNode = &(*this)[targetIndex];
		for(unsigned i = 0; i < columns; i++) {
			targetNode->value += sourceNode->value * lambda;
			sourceNode = sourceNode->next;
			targetNode = targetNode->next;
		}
	};

	/**
	 * Get the n-th cell of the matrix.
	 * 
	 * @param index Index of the desired cell (left to right, top to bottom).
	 * @returns A Node reference to the n-th cell of the matrix.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 */
	Node<T>& get(const unsigned &index) const {
		if(index >= rows * columns)
			throw std::out_of_range("Element out of range. Expected non-negative integer index lesser than " + std::to_string(rows * columns) + ". Index provided: " + std::to_string(index) + ".\n");
		Node<T> *node = data.head;
		for(unsigned i = 0; i < index; i++){
			node = node->next;
		}
		return *node;
	};

	/**
	 * Compares two matrices and return a boolean value.
	 * 
	 * @param matrix1 First matrix to compare.
	 * @param matrix2 Second matrix to compare.
	 * @returns Boolean value, true for equal matrices, false otherwise.
	 */
	static bool compare(const Matrix<T> &matrix1, const Matrix<T> &matrix2) {
		if(matrix1.columns != matrix2.columns || matrix1.rows != matrix2.rows)
			return false;
		for(unsigned i = 0; i < matrix1.rows; i++) {
			for(unsigned j = 0; j < matrix1.columns; j++) {
				if(matrix1[i][j] != matrix2[i][j])
					return false;
			}
		}
		return true;
	};

	Matrix<T> operator+(const Matrix<T> &rhs) const {
		if(this->rows != rhs.rows || this->columns != rhs.columns)
			throw std::runtime_error("The Matrices are not of the same size. Addition is not defined.");
		Matrix<T> result(this->rows, this->columns);
		for(unsigned i = 0; i < result.rows; i++){
			for(unsigned j = 0 ; j < result.columns; j++){
				result[i][j] = (*this)[i][j] + rhs[i][j];
			}
		}
		return result;
	};

	Matrix<T> operator-(const Matrix<T> &rhs) const {
		if(this->rows != rhs.rows || this->columns != rhs.columns)
			throw std::runtime_error("The Matrices are not of the same size. Subtraction is not defined.");
		Matrix<T> result(this->rows, this->columns);
		for(unsigned i = 0; i < result.rows; i++){
			for(unsigned j = 0; j < result.columns; j++){
				result[i][j] = (*this)[i][j] - rhs[i][j];
			}
		}
		return result;
	};

	Matrix<T> operator*(const Matrix<T> &rhs) const {
		if(this->columns != rhs.rows)
			throw std::runtime_error("The numbers of columns of the left Matrix and rows of the right Matrix are not equal.");
		Matrix<T> result(this->rows, rhs.columns);
		for(unsigned i = 0; i < result.rows; i++) {
			for(unsigned j = 0; j < result.columns; j++) {
				for(unsigned k = 0; k < this->columns; k++){
					result[i][j] += (*this)[i][k] * rhs[k][j];
				}
			}
		}
		return result;
	};

	// template<> class Matrix<Vector2> operator*(const Matrix<Vector2> &rhs) const {
	// 	throw std::runtime_error("Multiplying matrices of Vector2 is not defined.");
	// };

	// template<>
	// Matrix<Vector3> operator*(const Matrix<Vector3> &rhs) const {
	// 	throw std::runtime_error("Multiplying matrices of Vector3 is not defined.");
	// }

	bool operator==(const Matrix<T> &rhs) const {
		return Matrix<T>::compare(*this, rhs);
	};

	// double& operator()(const unsigned int&, const unsigned int&) const;

	/**
	 * Access the chosen row of the matrix. To be used with the second operator[].
	 * 
	 * @param index Index of the desired row.
	 * @returns A Node reference to the n-th row of the matrix.
	 */
	Node<T>& operator[](const unsigned &index) const {
		Node<T> *cell = data.head;
		for(unsigned i = 0; i < index * columns; i++) {
			cell = cell->next;
		}
		return *cell;
	};

	// TODO: does that have to be friend???
	friend std::ostream& operator<<(std::ostream &os, const Matrix<T> &matrix) {
		Node<T> *node = matrix.data.head;
		os << '[';
		for (unsigned i = matrix.rows * matrix.columns; i > 0; i--) {
			if (i % matrix.columns == 0 && i != matrix.rows * matrix.columns) os << ' ';
			os << std::setw(12) << node->value;
			node = node->next;
			os << ((i != 1) ? (((i - 1) % matrix.columns == 0) ? "\n" : ", ") : "]");
		}
		return os;
	}
};

template<typename T>
// Note: class with augement of only 1 column wide, might change that later on
struct AugmentedMatrix{
	Matrix<T> main;
	Matrix<T> augment;

	/**
	 * Constructor for the AugmentedMatrix class.
	 * 
	 * @param main The main Matrix of and Augmented Matrix (lhs).
	 * @param augment The augmented Matrix (rhs).
	 * @returns A new AugmentedMatrix object.
	 * @throws std::runtime_error Thrown if main Matrix has more columns than rows, or no. of rows in main and augment doesn't match.
	 */
	AugmentedMatrix(const Matrix<T>& main, const Matrix<T>& augment) {
		if(main.columns > main.rows || main.rows != augment.rows)
			throw std::runtime_error("Main matrix has to represent a set of equation with 0 degrees of freedom. Augment matrix has to have same no. of rows as main.");
		this->main = main;
		this->augment = augment;
	};

	/**
	 * Constructor for the AugmentedMatrix class.
	 * 
	 * @param size The size of main Matrix, i.e. creates nxn main Matrix and nx1 augment Matrix.
	 * @returns A new AugmentedMatrix object.
	 */
	AugmentedMatrix(const unsigned &size) 
		: main(Matrix<T>(size, size)), augment(Matrix<T>(size, 1)) {};


	/**
	 * Constructor for the AugmentedMatrix class.
	 * 
	 * @param rows The amount of the rows in main and augment Matrix.
	 * @param columns The amount of the columns in the main Matrix.
	 * @returns A new AugmentedMatrix object.
	 * @throws std::runtime_error Thrown if no. of columns is bigger than no. of rows.
	 */
	AugmentedMatrix(const unsigned &rows, const unsigned &columns) {
		if(columns > rows)
			throw std::runtime_error("Main matrix has to represent a set of equation with 0 degrees of freedom.");
		// TODO: may have to explicitly define type of Matrix
		this->main = Matrix<T>(rows, columns);
		this->augment = Matrix<T>(rows, 1);
	};

	/**
	 * Multiply the chosen row by the given value.
	 * 
	 * @param index Row index to multiply (0-based).
	 * @param lambda Scalar by which to multiply.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 * @throws std::runtime_error Thrown if lambda is equal to zero.
	 */
	void multiplyRow(const unsigned &index, const double &lambda) {
		main.multiplyRow(index, lambda);
		augment.multiplyRow(index, lambda);
	};

	/**
	 * Shuffle two chosen rows of the matrix.
	 * 
	 * @param index1 Index of the first row to shuffle.
	 * @param index2 Index of the second row to shuffle.
	 * @throws std::out_of_range Thrown if any of the indices provided is invalid.
	 */
	void shuffleRows(unsigned &index1, unsigned &index2) {
		main.shuffleRows(index1, index2);
		augment.shuffleRows(index1, index2);
	};

	/**
	 * Adds one row to another one.
	 * 
	 * @param sourceIndex The index of the row whose values are added.
	 * @param targetIndex The index of the row whose values are added to.
	 * @param lambda Optional, 1 by default. Source row will be multiplied by this value before being added.
	 * @throws std::out_of_range Thrown if any of the indices provided is invalid.
	 */
	void addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, const double &lambda = 1) {
		main.addRowToRow(sourceIndex, targetIndex, lambda);
		augment.addRowToRow(sourceIndex, targetIndex, lambda);
	};

	/**
	 * Perform a series of row operations on the matrix to obtain an identity matrix on the left side.
	 * *Works with square main matrices only.
	 * **May sometimes write a number similar to -2.22045e-016 instead of zero.
	 */
	void solve() {
		unsigned y;
		T pivot;
		for(unsigned x = 0; x < main.columns;  x++) {
			for(unsigned i = x; i < main.rows; i++) {
				pivot = main[i][x];
				if(pivot != 0) {
					y = 1;
					break;
				}
			}
			if(pivot == 0)
				break;
			if(y != x) {
				shuffleRows(x, y);
				y = x;
			}
			if(pivot != 1)
				multiplyRow(y, 1.0 / pivot);
			for(unsigned i = y + 1; i < main.rows; i++) {
				addRowToRow(y, i, -main[i][x]);
			}
		}
		for(unsigned x = main.columns - 1; x > 0; x--) {
			if(main[x][x] != 1)
				continue;
			for(unsigned y = 0; y < x; y++) {
				addRowToRow(x, y, -main[y][x]);
			}
		}
	};

	// TODO: Is friend necessary??
	friend std::ostream& operator<<(std::ostream &os, const AugmentedMatrix<T> &m) {
		os << "[";
		for(unsigned i = 0; i < m.main.rows; i++) {
			if(i != 0)
				os << " ";
			for(unsigned j = 0; j < m.main.columns; j++) {
				os << std::setw(8) << m.main[i][j] << " ";
			}
			os << "|";
			for(unsigned j = 0; j < m.augment.columns; j++) {
				os << " " << std::setw(8) << m.augment[i][j];
			}
			os << (i != m.main.rows - 1 ? "\n" : "]");
		}
		return os;
	};
};
