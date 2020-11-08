#include "Math.h"

double Math::binomial(const unsigned int& n, const unsigned int& k){
    double result;
    result = Math::factorial(n) / (Math::factorial(k) * Math::factorial(n - k));
    return result;
}

unsigned int Math::factorial(const unsigned int& n){
    if(n >= 1){
        return n * Math::factorial(n - 1);
    }
    return 1;
}