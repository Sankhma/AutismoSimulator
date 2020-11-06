#pragma once
#include <cstddef>

struct LinkedList;

struct Matrix {
    unsigned int rows;
    unsigned int columns;
	LinkedList *root; // matrix[0][0] ???

    Matrix(unsigned int rows = 1, unsigned int columns = 1);

	void fill(/* nie wiem co tutaj */);

	void transpose();
	static Matrix transpose(const Matrix &);

	LinkedList operator()(const std::size_t &, const std::size_t &);
	// LinkedList operator[](const size_t &);
};

struct LinkedList {
	double value = 0;
	LinkedList *next = nullptr;

	// LinkedList operator[](const size_t &);
};
