#define _DEBUG_ADD
#define _DEBUG_VA
#define _DEBUG_VERT
// #define _DEBUG_GV2

#include "Bezier.h"

template<typename T>
Bezier<T>::Bezier(const std::vector<T> &points){
    for(unsigned char i = 0; i < points.size(); i++){
        this->addPoint(points[i]);
    }
}

template<typename T>
Bezier<T>::Bezier(const LinkedList<T> &points) {
	Node<T> *n = points.head;
	while (n != nullptr) {
		this->points.add(n->value);
		n = n->next;
	}
}

template<typename T>
Bezier<T>::Bezier(const Matrix<T> &points) {
    if(points.columns != 1 || points.rows != 1)
        throw std::runtime_error("The provided matrix shoul have only one clomuns/row.");
    if(points.columns == 1) {
        for(unsigned char i = 0; i < points.rows; i++) {
            this->addPoint(points[i][0]);
        }
    } else {
        for(unsigned char i = 0; i < points.columns; i++) {
            this->addPoint(points[0][i]);
        }
    }
}

template<typename T>
Bezier<T>::Bezier(const unsigned char &size, ...){
    va_list vl;
    va_start(vl, size);
    for(unsigned char i = 0; i < size; i++){
        T* ptr = va_arg(vl, T*);
        #ifdef _DEBUG_VA
            if(ptr->name() == "Vector2") {
                std::cout << "Vector2 @ " << ptr << " with value " << *ptr << std::endl;
            } else {
                std::cout << "Vector3 @ " << ptr << " with value " << *ptr << std::endl;
            }
        #endif
        this->addPoint(*ptr);
    }
    va_end(vl);
}

template<typename T>
void Bezier<T>::addPoint(const T& Point){
	this->points.add(Point);
    #ifdef _DEBUG_ADD
        std::cout << "Added point: " << Point << std::endl;
    #endif
    this->m_points++;
}

template<typename T>
T Bezier<T>::GenerateVertex(Bezier<T> &bezier, const double &t){
    T result = T();

    if(bezier.m_points == 2){
        result = bezier.points[1] * t + bezier.points[0] * (1 - t);
    }

    if(bezier.m_points == 3){
        result = bezier.points[2] * std::pow(t, 2) + bezier.points[1] * 2 * t * (1 - t) + bezier.points[0] * std::pow((1 - t), 2);
    }

    if(bezier.m_points == 4){
        result = bezier.points[3] * std::pow(t, 3) + bezier.points[2] * 3 * (1 - t) * std::pow(t, 2) + bezier.points[1] * 3 * std::pow((1 - t), 2) * t + bezier.points[0] * std::pow((1 - t), 3);
    }

    if(bezier.m_points > 4){
        for(unsigned char i = 0; i <= bezier.m_points - 1; i++){
            double bbp = Math::binomial(bezier.m_points - 1, i) * std::pow((1 - t), bezier.m_points - 1 - i) * pow(t, i);
            result += bezier.points[i] * bbp;
        }
    }

    #ifdef _DEBUG_VERT
            std::cout << "Generated Vertex @ " << result << std::endl;
    #endif
    return result;
}

// template<typename T>
// T Bezier<T>::GenerateVertex2(const Bezier<T> &bezier, const double &t) {
// 	std::vector<T> points = bezier.points;
// 	#ifdef _DEBUG_GV2
// 		std::cout << "Generating a vertex with:\n\tvertices: ";
// 		for (const T &v : points) std::cout << v << ", ";
// 		std::cout << "\n\tt = " << t << "\nEntering the outer loop...\n\n";
// 	#endif
// 	for (unsigned char i = 0; i < bezier.m_points - 1; i++) {
// 		#ifdef _DEBUG_GV2
// 			std::cout << "Iteration " << i << "...\nEntering the inner loop...\n\n";
// 		#endif
// 		for (unsigned char j = 0; j < points.size() - 1; j++) {
// 			#ifdef _DEBUG_GV2
// 				std::cout << "(" << points[j + 1] << " - " << points[j] << ") * " << t;
// 			#endif
// 			points[j] += (points[j + 1] - points[j]) * t;
// 			#ifdef _DEBUG_GV2
// 				std::cout << " = " << points[j] << '\n';
// 			#endif
// 		}
// 		#ifdef _DEBUG_GV2
// 			std::cout << "\nFinished the inner loop.\n";
// 			std::cout << "Removing the last vertex in points...\n\n";
// 		#endif
// 		points.pop_back();
// 	}
// 	#ifdef _DEBUG_GV2
// 		std::cout << "Finished the outer loop.\n";
// 	#endif
// 	std::cout << "Generated vertex @ " << points[0] << '\n';
// 	return points[0];
// }

template<typename T>
unsigned char Bezier<T>::getSize() const {
	return m_points;
}

template<typename T>
void Bezier<T>::clear() {
    this->m_points = 0;
    LinkedList<T> temp = this->points;
    this->points = LinkedList<T>;
    delete(temp);
}

// TODO: make so it works with all types!!
template class Bezier<Vector2<double>>;
template class Bezier<Vector2<float>>;
template class Bezier<Vector2<int>>;

template class Bezier<Vector3<double>>;
template class Bezier<Vector3<float>>;
template class Bezier<Vector3<int>>;
