#include <iostream>
#include <vector>
#include <chrono>
#include "Matrix.h"
#include "Vector.h"

int main() {
	{
		// Matrix m1 = Matrix(3, 2);
		// Matrix m2 = Matrix(4, 4);
		// Matrix m3 = Matrix(5, 6);

		// std::cout << "m1:\n";

		// std::cout << "m2:\n";

		// std::cout << "m3:\n";

		// Matrix m4 = {3, 3};
		// m4[0][0] = 1, m4[0][1] = 2, m4[0][2] = 3;
		// m4[1][0] = 420, m4[1][1] = 5, m4[1][2] = 6;
		// m4[2][0] = 7, m4[2][1] = 8, m4[2][2] = 9;

		// std::cout << "m4:\n" << m4 << '\n';

		// Matrix m5 = {5, 3};
		// m5[0][0] = 1, m5[0][1] = 2, m5[0][2] = 3;
		// m5[1][0] = 4, m5[1][1] = 5, m5[1][2] = 6;
		// m5[2][0] = 7, m5[2][1] = 8, m5[2][2] = -69;
		// m5[3][0] = 10, m5[3][1] = 11, m5[3][2] = 12;
		// m5[4][0] = 13, m5[4][1] = 14, m5[4][2] = 15;

		// std::cout << "m5:\n" << m5 << '\n';

		// for (int i = 0; i < m5.rows - 1; i++) {
		// 	m5.shuffleRows(i, i + 1);
		// 	std::cout << "m5 after shuffling rows " << i << " and " << i + 1 << ":\n" << m5 << '\n';
		// }
		// m5.shuffleRows(4, 0);
		// std::cout << "m5 after shuffling rows 4 and 0:\n" << m5 << '\n';
		// m5.transpose();
		// m5.shuffleRows(1, 0);
		// std::cout << "m5 after transposing and shuffling rows 1 and 0:\n" << m5 << '\n';
		// m5.shuffleRows(0, 0);
		// std::cout << "m5 after shuffling rows 0 and 0:\n" << m5 << '\n';

		// m5.shuffleRows(-1, 7);

		// Matrix m6 = Matrix(2, 3);
		// m6[0][0] = 1, m6[0][1] = 2, m6[0][2] = 3;
		// m6[1][0] = 4, m6[1][1] = 5, m6[1][2] = 6;
		// std::cout << "m6:\n" << m6 << '\n';
		// m6.shuffleRows(0, 1);
		// std::cout << "m6 after shuffling rows 0 and 1:\n" << m6 << '\n';
		// m6.transpose();

		// Matrix<double> m7 = Matrix<double>(4, 1);
		// m7[0][0] = 1, m7[1][0] = 2, m7[2][0] = 3, m7[3][0] = 4;
		// std::cout << "m7:\n" << m7 << '\n';
		// m7.shuffleRows(0, 1);
		// std::cout << "m7 after shuffling rows 0 and 1:\n" << m7 << '\n';
		// m7.shuffleRows(3, 0);
		// std::cout << "m7 after shuffling rows 3 and 0:\n" << m7 << '\n';
		// m7.addRowToRow(2, 3, -2.5);
		// std::cout << "m7 after adding row 2 to row 3 -2.5 times:\n" << m7 << '\n';

		// Matrix<double> m9 = Matrix<double>(4, 4);
		// m9[0][0] = 1, m9[0][1] = 2, m9[0][2] = 3, m9[0][3] = 4;
		// m9[1][0] = 5, m9[1][1] = 6, m9[1][2] = 7, m9[1][3] = 8;
		// m9[2][0] = 9, m9[2][1] = 10, m9[2][2] = 11, m9[2][3] = 12;
		// m9[3][0] = 13, m9[3][1] = 14, m9[3][2] = 15, m9[3][3] = 16;

		// AugmentedMatrix am1 = AugmentedMatrix(m9, m7);
		// std::cout << "am1:\n" << am1 << '\n';
		// am1.solve();
		// std::cout << "am1 after obtaining its reduced row-echelon form:\n" << am1 << '\n';
	}
	
	// TEMPLATES
	{
		// Matrix<double> m1 = Matrix<double>(4, 3);
		// m1[0][0] = 1, m1[0][1] = 2, m1[0][2] = 3;
		// m1[1][0] = 4, m1[1][1] = 5, m1[1][2] = 6;
		// m1[2][0] = 7, m1[2][1] = 8, m1[2][2] = 9;
		// m1[3][0] = 10, m1[3][1] = 11, m1[3][2] = 12;

		// std::cout << m1 << '\n';

		// Matrix<int> m2 = Matrix<int>(2, 3);
		// m2[0][0] = 1, m2[0][1] = 2, m2[0][2] = 3;
		// m2[1][0] = 4, m2[1][1] = 5, m2[1][2] = 6;

		// std::cout << m2 << '\n';

		// Matrix<Vector2> m3 = Matrix<Vector2>(3, 2);
		// m3[0][0] = 1, m3[0][1] = 2, m3[0][2] = 3;
		// m3[1][0] = 4, m3[1][1] = 5, m3[1][2] = 6;

		// std::cout << m3 << '\n';
	}
	
	// std::cout << "Comparing two matricies" << std::endl;
	// std::cout << "Matrix<double>::compare(m7, m9): " << Matrix<double>::compare(m7, m9) << std::endl;
	// std::cout << "m7 == m9: " << (m7 == m9) << std::endl;

	std::cout << "Generating 10 random matrices with size 1000x1000...\n";
	Matrix<unsigned> m10;
	for (int i = 0; i < 10; i++) {
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		m10 = Matrix<unsigned>(1000, 1000, true);
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]\n";
	}
	// Matrix<unsigned> m11 = Matrix<unsigned>::MatrixRandom(100, 100);

	// std::cout << "m10 == m11: " << Matrix<unsigned>::compare(m10, m11) << std::endl;
	// std::cout << m10 << "\t" << m11 << std::endl;

	std::cin.get();

	return 0;
}