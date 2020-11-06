#include <iostream>

#include "Vector.h"

int main(){
    Vector3 a = Vector3(5, 5, 5);
    Vector3 b = Vector3(-2, 7, 14);

    Vector3 add = a + b;
    Vector3 sub = a - b;
    Vector3 mul = b * 0.3;
    double dot = Vector3::dot(a, b);
    Vector3 cross = Vector3::cross(a, b);

    std::cout << "Adding: x: " << add.x << " y: " << add.y << " z: " << add.z << std::endl;
    std::cout << "Subtracting: x: " << sub.x << " y: " << sub.y << " z: " << sub.z << std::endl;
    std::cout << "Multiplying by a scalar: x: " << mul.x << " y: " << mul.y << " z: " << mul.z << std::endl;
    std::cout << "Dot Product: " << dot << std::endl;
    std::cout << "Cross Product: x: " << cross.x << " y: " << cross.y << " z: " << cross.z << std::endl;
}