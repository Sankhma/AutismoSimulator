#pragma once
#include <cstddef>
#include <iostream>

struct Node {
	double value;
	Node *next;

	Node();
	Node(const double &);

	static void swapValues(Node *, Node *);

	double& operator[](const unsigned int &);
};

struct LinkedList {
	Node *head, *tail;

	LinkedList();

	void addNode(const double &);
	LinkedList copy() const;

	double& operator[](const unsigned int &);
};

struct Matrix {
    unsigned int rows;
    unsigned int columns;
	LinkedList data;

    Matrix(unsigned int rows = 1, unsigned int columns = 1);

	void transpose();
	// static Matrix transpose(const Matrix &);

	/**
	 * Multiply the chosen row by the value given.
	 * 
	 * @param index Row index to multiply (0-based).
	 * @param lambda Scalar by which to multiply.
	 */
	void multiplyRow(const unsigned &index, const double &lambda);

	/**
	 * Shuffle two chosen rows of the matrix.
	 * 
	 * @param index1 Index of the first row to shuffle.
	 * @param index2 Index of the second row to shuffle.
	 */
	void shuffleRows(const unsigned &index1, const unsigned &index2);

	/**
	 * Adds/subtracts one row to/from another one.
	 * 
	 * @param sourceIndex The index of the row whose values are added/subtracted.
	 * @param targetIndex The index of the row whose values are added to/subtracted from.
	 * @param addition Optional, true by default. If false, subtraction will be performed instead.
	 */
	void addRowToRow(const unsigned &sourceIndex, const unsigned &targetIndex, bool addition = true);

	/**
	 * Get the n-th cell of the matrix.
	 * 
	 * @param index Index of the wanted cell (left to right, top to bottom).
	 * @returns A Node reference to the n-th cell of the matrix.
	 */
	Node& get(const unsigned &index) const;

	Matrix operator+(const Matrix &) const;
	Matrix operator-(const Matrix &) const;
	Matrix operator*(const Matrix &) const;

	// double& operator()(const unsigned int&, const unsigned int&) const;
	Node& operator[](const unsigned int &) const;
	friend std::ostream& operator<<(std::ostream &, const Matrix &);
};
