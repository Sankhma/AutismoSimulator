#include <iostream>
#include "Bezier.h"

int main() {
	// Bezier<Vector2<double>> bezier_2p = Bezier<Vector2<double>>({{0, 0}, {1, 1}});
	// Bezier<Vector2<double>> bezier_3p = Bezier<Vector2<double>>({{0, 0}, {0, 1}, {1, 0}});
	// Bezier<Vector2<double>> bezier_4p = Bezier<Vector2<double>>({{0, 0}, {1, 3}, {4, 3}, {3, 0}});
	Bezier<Vector2<double>> bezier_5p = Bezier<Vector2<double>>({{0, 0}, {1, 2}, {2, 0}, {3, 2}, {4, 0}});

	short steps = 10;

	// std::cout << "\n2 points:\n";
	// for (short i = 0; i <= steps; i++) {
	// 	double t = double(i) / steps;
	// 	Bezier<Vector2<double>>::GenerateVertex2(bezier_2p, t);
	// }

	// std::cout << "\n3 points:\n";
	// for (short i = 0; i <= steps; i++) {
	// 	double t = double(i) / steps;
	// 	Bezier<Vector2<double>>::GenerateVertex2(bezier_3p, t);
	// }

	// std::cout << "\n4 points:\n";
	// for (short i = 0; i <= steps; i++) {
	// 	double t = double(i) / steps;
	// 	Bezier<Vector2<double>>::GenerateVertex2(bezier_4p, t);
	// }

	std::cout << "\n5 points:\n";
	for (short i = 0; i <= steps; i++) {
		double t = double(i) / steps;
		Bezier<Vector2<double>>::GenerateVertex2(bezier_5p, t);
	}
}