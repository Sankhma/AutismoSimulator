#pragma once
#include <cstddef>
#include <iostream>

struct Node {
	double value;
	Node *next;

	Node();
	Node(const double &);

	static void swapValues( Node *,  Node *);

	double& operator[](const int &);
};

struct LinkedList {
	Node *head, *tail;

	LinkedList();

	void addNode(const double &);
	LinkedList copy() const;

	double& operator[](const int &);
};

struct Matrix {
    unsigned int rows;
    unsigned int columns;
	LinkedList data;

    Matrix(unsigned int rows = 1, unsigned int columns = 1);

	void transpose();
	static Matrix transpose(const Matrix &);

	double& operator()(const int&, const int&) const;

	Node& operator[](const int &) const;
};
