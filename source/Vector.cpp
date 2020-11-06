#include "Vector.h"

// struct Vector3{
//     double x;
//     double y;
//     double z;

//     Vector3(double x=0., double y=0., double z=0.);

//     Vector3 operator+(const Vector3&) const;
//     Vector3 operator-(const Vector3&) const;
//     Vector3 operator*(const double&) const;

//     double dot(const Vector3&, const Vector3&) const;
//     Vector3 cross(const Vector3&, const Vector3&) const;
// };

Vector3::Vector3(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::operator+(const Vector3& vec) const{
    Vector3 result;
    result.x = this->x + vec.x;
    result.y = this->y + vec.y;
    result.z = this->z + vec.z;
    return result;
}

Vector3 Vector3::operator-(const Vector3& vec) const{
    Vector3 result;
    result.x = this->x - vec.x;
    result.y = this->y - vec.y;
    result.z = this->z - vec.z;
    return result;
}

Vector3 Vector3::operator*(const double& lambda) const{
    Vector3 result;
    result.x = this->x * lambda;
    result.y = this->y * lambda;
    result.z = this->z * lambda;
    return result;
}

double Vector3::dot(const Vector3& vec1, const Vector3& vec2){
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Vector3 Vector3::cross(const Vector3& vec1, const Vector3& vec2){
    Vector3 result;
    result.x = vec1.y * vec2.z - vec2.y * vec1.z;
    result.y = vec1.z * vec2.x - vec2.z * vec1.x;
    result.z = vec1.x * vec2.y - vec2.x * vec1.y;
    return result;
}