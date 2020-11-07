#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>


struct Node;
struct LinkedList;
struct Pair;


struct Matrix {
    unsigned int rows;
    unsigned int columns;
	LinkedList *data;

    Matrix(unsigned int rows = 1, unsigned int columns = 1);

	void transpose();
	static Matrix transpose(const Matrix &);

	// LinkedList operator()(const std::size_t &, const std::size_t &);
	Pair operator[](const int &) const;
};


struct Node {
	double value;
	Node *next;

	Node();
	Node(const double &);
};


struct LinkedList {
	Node *head, *tail;

	LinkedList();

	void addNode(const double &);
};


struct Pair {
	Node* elem;
	unsigned int n;

	Pair(Node*, const unsigned int &);

	double operator[](const int &);
};
