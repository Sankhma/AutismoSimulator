// deprecated
// #include "Vector.h"
// #include <iostream>
// #include <cmath>

// //-============ Vector2 =============-

// Vector2::Vector2(const double &x, const double &y) : x(x), y(y) {}

// Vector2 Vector2::operator+(const Vector2 &v1) const {
// 	return {this->x + v1.x, this->y + v1.y};
// }

// Vector2 Vector2::operator-(const Vector2 &v1) const {
// 	return {this->x - v1.x, this->y - v1.y};
// }

// Vector2& Vector2::operator+=(const Vector2& vec){
//     this->x += vec.x;
//     this->y += vec.y;
//     return *this;
// }

// Vector2& Vector2::operator-=(const Vector2& vec){
//     this->x -= vec.x;
//     this->y -= vec.y;
//     return *this;
// }

// Vector2& Vector2::operator*=(const double& lambda){
//     this->x *= lambda;
//     this->y *= lambda;
//     return *this;
// }

// std::ostream& operator<<(std::ostream& os, const Vector2& vec){
//     os << "[" << vec.x << ", " << vec.y << "]";
//     return os;
// }

// Vector2 operator*(const Vector2& vec, const double lambda){
// 	return {vec.x * lambda, vec.y * lambda};
// }

// Vector2 operator*(const double lambda, const Vector2& vec){
// 	return vec * lambda;
// }

// bool operator==(const Vector2 &vec1, const Vector2 &vec2) {
// 	return vec1.x == vec2.x && vec1.y == vec2.y;
// }

// bool operator!=(const Vector2 &vec1, const Vector2 &vec2) {
// 	return vec1.x != vec2.x || vec1.y != vec2.y;
// }

// double Vector2::dot(const Vector2 &v1, const Vector2 &v2) {
// 	return v1.x * v2.x + v1.y * v2.y;
// }

// double Vector2::angle(const Vector2& vec1, const Vector2& vec2){
//     double result = std::acos(Vector2::dot(vec1, vec2) / std::sqrt(Vector2::dot(vec1, vec1) * Vector2::dot(vec2, vec2)));
//     return result;
// }

// //-============ Vector3 =============-

// Vector3::Vector3(double x, double y, double z){
//     this->x = x;
//     this->y = y;
//     this->z = z;
// }

// Vector3 Vector3::operator+(const Vector3& vec) const{
//     Vector3 result;
//     result.x = this->x + vec.x;
//     result.y = this->y + vec.y;
//     result.z = this->z + vec.z;
//     return result;
// }

// Vector3 Vector3::operator-(const Vector3& vec) const{
//     Vector3 result;
//     result.x = this->x - vec.x;
//     result.y = this->y - vec.y;
//     result.z = this->z - vec.z;
//     return result;
// }

// Vector3& Vector3::operator+=(const Vector3& vec){
//     this->x += vec.x;
//     this->y += vec.y;
//     this->z += vec.z;
//     return *this;
// }

// Vector3& Vector3::operator-=(const Vector3& vec){
//     this->x -= vec.x;
//     this->y -= vec.y;
//     this->z -= vec.z;
//     return *this;
// }

// Vector3& Vector3::operator*=(const double& lambda){
//     this->x *= lambda;
//     this->y *= lambda;
//     this->z *= lambda;
//     return *this;
// }

// std::ostream& operator<<(std::ostream& os, const Vector3& vec){
//     os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
//     return os;
// }

// Vector3 operator*(const Vector3& vec, const double lambda){
//     Vector3 result;
//     result.x = vec.x * lambda;
//     result.y = vec.y * lambda;
//     result.z = vec.z * lambda;
//     return result;
// }

// Vector3 operator*(const double lambda, const Vector3& vec){
//     return vec * lambda;
// }

// bool operator==(const Vector3 &vec1, const Vector3 &vec2) {
// 	return vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z;
// }

// bool operator!=(const Vector3 &vec1, const Vector3 &vec2) {
// 	return vec1.x != vec2.x || vec1.y != vec2.y || vec1.z != vec2.z;
// }

// double Vector3::dot(const Vector3& vec1, const Vector3& vec2){
//     return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
// }

// Vector3 Vector3::cross(const Vector3& vec1, const Vector3& vec2){
//     Vector3 result;
//     result.x = vec1.y * vec2.z - vec2.y * vec1.z;
//     result.y = vec1.z * vec2.x - vec2.z * vec1.x;
//     result.z = vec1.x * vec2.y - vec2.x * vec1.y;
//     return result;
// }

// double Vector3::angle(const Vector3& vec1, const Vector3& vec2){
//     double result = std::acos(Vector3::dot(vec1, vec2) / std::sqrt(Vector3::dot(vec1, vec1) * Vector3::dot(vec2, vec2)));
//     return result;
// }
