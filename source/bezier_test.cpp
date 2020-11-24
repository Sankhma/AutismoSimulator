#include <iostream>

#include "Vector.h"
#include "Bezier.h"

// I guess this is also fcked

int main(){
    std::cout << "-============ Bezier2 test =============-" << std::endl;
	{
        int steps = 20;

		Vector2<double> p0 = {0, 0};
        Vector2<double> p1 = {1, 1};
        Vector2<double> p2 = {10, -10};
        Vector2<double> p3 = {3.14, 2.73};

        Bezier<Vector2<double>> b0 = Bezier<Vector2<double>>(2, &p0, &p1);
        Bezier<Vector2<double>> b1 = Bezier<Vector2<double>>(3, &p0, &p1, &p2);
        Bezier<Vector2<double>> b2 = Bezier<Vector2<double>>(4, &p0, &p1, &p2, &p3);

        std::cout << "Bezier(2-D) for 2 points, steps=20" << std::endl;
        for(int i=0; i <= steps; i++){
            Vector2<double> temp = Bezier<Vector2<double>>::GenerateVertex(b0, i / double(steps));
            std::cout << "[ " << temp.x << ", " << temp.y << " ]" << std::endl;
        }

        std::cout << "Bezier(2-D) for 3 points, steps=20" << std::endl;
        for(int i=0; i <= steps; i++){
            Vector2<double> temp = Bezier<Vector2<double>>::GenerateVertex(b1, i / double(steps));
            std::cout << "[ " << temp.x << ", " << temp.y << " ]" << std::endl;
        }

        std::cout << "Bezier(2-D) for 4 points, steps=20" << std::endl;
        for(int i=0; i <= steps; i++){
            Vector2<double> temp = Bezier<Vector2<double>>::GenerateVertex(b2, i / double(steps));
            std::cout << "[ " << temp.x << ", " << temp.y << " ]" << std::endl;
        }
	}

    Vector3<int> siema;

    std::cout << siema.name() <<std::endl;
}