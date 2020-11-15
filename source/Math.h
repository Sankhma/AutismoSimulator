#pragma once

namespace Math{
	/**
	 * Calculate the binomial factor ( n choose k, combinations).
	 * 
	 * @param n,k Integers. k has to be less than or equal to n.
	 * @returns The binomial factor ( n choose k, combinations).
	 */
    double binomial(const unsigned int& n, const unsigned int& k);

	/**
	 * Calculate the factorial of n (n!).
	 * 
	 * @param n Integer.
	 * @returns The factorial of n.
	 */
    unsigned int factorial(const unsigned int& n);
}
