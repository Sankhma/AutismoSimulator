#include <iostream>

#include "Vector.h"
#include "Bezier.h"

// I guess this is also fcked

int main(){
    std::cout << "-============ Bezier2 test =============-" << std::endl;
	{
        int steps = 20;

		Vector2 p0 = {0, 0};
        Vector2 p1 = {1, 1};
        Vector2 p2 = {10, -10};
        Vector2 p3 = {3.14, 2.73};

        Bezier2 b0 = Bezier2(2, &p0, &p1);
        Bezier2 b1 = Bezier2(3, &p0, &p1, &p2);
        Bezier2 b2 = Bezier2(4, &p0, &p1, &p2, &p3);

        std::cout << "Bezier2 for 2 points, steps=20" << std::endl;
        for(int i=0; i <= steps; i++){
            Vector2 temp = Bezier2::GenerateVertex(b0, i / double(steps));
            std::cout << "[ " << temp.x << ", " << temp.y << " ]" << std::endl;
        }

        std::cout << "Bezier2 for 3 points, steps=20" << std::endl;
        for(int i=0; i <= steps; i++){
            Vector2 temp = Bezier2::GenerateVertex(b1, i / double(steps));
            std::cout << "[ " << temp.x << ", " << temp.y << " ]" << std::endl;
        }

        std::cout << "Bezier2 for 4 points, steps=20" << std::endl;
        for(int i=0; i <= steps; i++){
            Vector2 temp = Bezier2::GenerateVertex(b2, i / double(steps));
            std::cout << "[ " << temp.x << ", " << temp.y << " ]" << std::endl;
        }
	}
}