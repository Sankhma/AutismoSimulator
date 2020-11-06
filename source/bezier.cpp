#include <iostream>

struct Vector2
{
    double x;
    double y;
    Vector2(double x = 0., double y = 0.);
    Vector2 operator-(const Vector2&) const;
    Vector2 operator*(const double&) const;
    Vector2 operator+(const Vector2&) const;
};

Vector2::Vector2(double x, double y){
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator-(const Vector2& vec) const{
    Vector2 result;
    result.x = (this->x - vec.x);
    result.y = (this->y - vec.y);
    return result;
}

Vector2 Vector2::operator*(const double& lambda) const{
    Vector2 result;
    result.x = (this->x * lambda);
    result.y = (this->y * lambda);
    return result;
}

Vector2 Vector2::operator+(const Vector2& vec) const{
    Vector2 result;
    result.x = (this->x + vec.x);
    result.y = (this->y + vec.y);
    return result;
}

int main() {
    Vector2 p1 = Vector2(0, 0);
    Vector2 p2 = Vector2(10, 10);
    Vector2 p3 = Vector2(20, 0);

    Vector2 vec1 = p2 - p1;
    Vector2 vec2 = p3 - p2;

    int timesteps = 1000;
    for(int i=0; i <= timesteps; i++){
        double lambda = double(i) / double(timesteps);

        Vector2 point1 = p1 + vec1 * lambda;
        Vector2 point2 = p2 + vec2 * lambda;

        Vector2 vec = point2 - point1;

        double x = (point1 + vec * lambda).x;
        double y = (point1 + vec * lambda).y;

        std::cout << "timestep: " << i << std::endl;
        std::cout << "x: " << x << "  " << "y: " << y << std::endl;
    }

    return 0;
}