#pragma once
#include <cstddef>
#include <iostream>

template<typename T>
struct Node {
	T value;
	Node<T> *next;

	Node() : value(0), next(nullptr) {};
	Node(const T &value) : value(value), next(nullptr) {};

	static void swapValues(Node *node1, Node *node2) {
		auto temp = node1->value;
		node1->value = node2->value;
		node2->value = temp;
	}

	T& operator[](const int &index) {
		Node *cell = this;
		for (int i = 0; i < index; i++) {
			cell = cell->next;
		}
		return cell->value;
	}
};


template<typename T>
struct LinkedList {
	Node<T> *head, *tail;

	LinkedList() : head(nullptr), tail(nullptr) {}

	void add(const T &value) {
		Node<T> *temp = new Node<T>(value);

		if (head == nullptr) {
			head = tail = temp;
		} else {
			tail = tail->next = temp;
		}
	}

	LinkedList copy() const {
		LinkedList newList = LinkedList();
		Node<T> *node = head;
		while (node != nullptr) {
			newList.add(node->value);
			node = node->next;
		}
		return newList;
	}

	T& operator[](const int &index) {
		if (head == nullptr) throw std::runtime_error("The LinkedList is empty.");
		Node<T> *node = head;
		for (unsigned int i = 0; i < index; i++) {
			node = node->next;
			if (node == nullptr) throw std::runtime_error("Out of range.");
		}
		return node->value;
	}
};


template<typename T>
struct Matrix {
    unsigned int rows;
    unsigned int columns;
	LinkedList<T> data;

    Matrix(unsigned int rows = 1, unsigned int columns = 1) : rows(rows), columns(columns) {
		data = LinkedList<T>();
		for (int i = 0; i < rows * columns; i++) {
			data.add(0);
		}
	}

	void transpose() {
		LinkedList<T> old = data.copy();
		Node<T> *n1 = data.head->next;
		unsigned iters = rows * columns - 1;
		for (unsigned i = 1; i < iters; i++) {
			n1->value = old[(i * columns) % iters];
			n1 = n1->next;
		}
		unsigned temp = rows;
		rows = columns;
		columns = temp;
	}

	Matrix operator*(const Matrix &other) const {
		if (columns != other.rows) throw std::runtime_error("The numbers of columns of the left Matrix and rows of the right Matrix are not equal.");
		Matrix result = Matrix(rows, other.columns);
		for (unsigned y = 0; y < result.rows; y++) {
			for (unsigned x = 0; x < result.columns; x++) {
				for (unsigned i = 0; i < columns; i++) {
					result[y][x] += (*this)[y][i] * other[i][x];
				}
			}
		}
		return result;
	}

	T& operator()(const int &row, const int &col) const {
		Node<T> *cell = data.head;
		for (int i = 0; i < row * columns + col; i++) {
			cell = cell->next;
		}
		return cell->value;
	}
	
	Node<T>& operator[](const int &index) const {
		Node<T> *cell = data.head;
		for (int i = 0; i < index * columns; i++) {
			cell = cell->next;
		}
		return *cell;
	}
};
