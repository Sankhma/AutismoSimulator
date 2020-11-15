#pragma once
#include <cstddef>
#include <iostream>

/**
 * Data structure used to store a value and a pointer to the next Node.
 * Meant to be instantiated by LinkedList class only.
 */
struct Node {
	double value; // Value to be stored.
	Node *next;   // Pointer to the next Node.

	/**
	 * Constructor for the Node class.
	 * 
	 * @returns A new Node object.
	 */
	Node();

	/**
	 * Constructor for the Node class.
	 * 
	 * @param value The value to be stored in the node.
	 * @overload
	 */
	Node(const double &value);

	/**
	 * Swap values of two given Nodes.
	 * 
	 * @param *n1,*n2 Pointers to the Nodes.
	 */
	static void swapValues(Node *n1, Node *n2);

	/**
	 * Access the value of the n-th next Node.
	 * 
	 * @param index Index of the desired Node.
	 * @returns Value of the desired Node.
	 */
	double& operator[](const unsigned int &index);
};

/**
 * Data structure used to store Node objects.
 * 
 * @see Node
 */
struct LinkedList {
	Node *head; // Pointer to the first element of the list.
	Node *tail; // Pointer to the last element of the list.

	/**
	 * Constructor for the LinkedList class.
	 * 
	 * @returns A new LinkedList object.
	 */
	LinkedList();

	/**
	 * Add a node to the end of the list.
	 * 
	 * @param value Value to be added to the list.
	 */
	void addNode(const double &value);

	/**
	 * Create a shallow copy of the list.
	 * 
	 * @returns A new LinkedList object with identical values.
	 */
	LinkedList copy() const;

	/**
	 * Access the n-th element of the list.
	 * 
	 * @param index Index of the desired element.
	 * @returns Value of the desired element.
	 * @throws std::runtime_error Thrown if the list is empty.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 */
	double& operator[](const unsigned int &index);
};

/**
 * Data structure representing a rectangular array of numbers, arranged in rows and columns.
 * 
 * @see LinkedList
 */
struct Matrix {
    unsigned int rows;    // The amount of rows of the matrix.
    unsigned int columns; // The amount of columns of the matrix.
	LinkedList data;      // Data stored in the matrix.

	/**
	 * Constructor for the Matrix class.
	 * 
	 * @param rows The amount of the rows of the new matrix.
	 * @param columns The amount of the columns of the new matrix.
	 * @returns A new Matrix object.
	 * @throws std::runtime_error Thrown if any of the dimensions provided is invalid.
	 */
    Matrix(unsigned int rows = 1, unsigned int columns = 1);

	/**
	 * Flip the matrix over its diagonal.
	 * (Switch the row and column indices.)
	 */
	void transpose();

	/**
	 * Multiply the chosen row by the given value.
	 * 
	 * @param index Row index to multiply (0-based).
	 * @param lambda Scalar by which to multiply.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 */
	void multiplyRow(const unsigned &index, const double &lambda);

	/**
	 * Shuffle two chosen rows of the matrix.
	 * 
	 * @param index1 Index of the first row to shuffle.
	 * @param index2 Index of the second row to shuffle.
	 * @throws std::out_of_range Thrown if any of the indices provided is invalid.
	 */
	void shuffleRows(unsigned index1, unsigned index2);

	/**
	 * Adds one row to another one.
	 * 
	 * @param sourceIndex The index of the row whose values are added.
	 * @param targetIndex The index of the row whose values are added to.
	 * @param lambda Optional, 1 by default. Source row will be multiplied by this value before being added.
	 * @throws std::out_of_range Thrown if any of the indices provided is invalid.
	 */
	void addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, const double &lambda = 1);

	/**
	 * Get the n-th cell of the matrix.
	 * 
	 * @param index Index of the desired cell (left to right, top to bottom).
	 * @returns A Node reference to the n-th cell of the matrix.
	 * @throws std::out_of_range Thrown if the index provided is invalid.
	 */
	Node& get(const unsigned &index) const;

	Matrix operator+(const Matrix &) const;
	Matrix operator-(const Matrix &) const;
	Matrix operator*(const Matrix &) const;

	// double& operator()(const unsigned int&, const unsigned int&) const;

	/**
	 * Access the chosen row of the matrix. To be used with the second operator[].
	 * 
	 * @param index Index of the desired row.
	 * @returns A Node reference to the n-th row of the matrix.
	 */
	Node& operator[](const unsigned int &index) const;
	friend std::ostream& operator<<(std::ostream &, const Matrix &);
};
