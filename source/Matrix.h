#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>

struct LinkedList;
struct Pair;

struct Matrix {
    unsigned int rows;
    unsigned int columns;
	LinkedList *root;

    Matrix(unsigned int rows = 1, unsigned int columns = 1);

	void transpose();
	static Matrix transpose(const Matrix &);

	// LinkedList operator()(const std::size_t &, const std::size_t &);
	Pair operator[](const int &) const;
};

struct LinkedList {
	double value = 0;
	LinkedList *next = nullptr;

	LinkedList();
	LinkedList(const double &);
};

struct Pair {
	LinkedList* elem;
	unsigned int n;

	Pair(LinkedList*, const unsigned int &);

	double operator[](const int &);
};
