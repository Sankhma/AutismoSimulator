#define _DEBUG

#include "Track.h"

template<typename T>
Track<T>::Track(const std::vector<T> &curves, const std::string &name, const double &length, const double &width)
    : name(name), length(length), width(width), curves(curves){
        if(length < 0 || width < 0) throw std::runtime_error("Lenght or width of a track cannot be less than 0.");
        #ifdef _DEBUG
        std::cout << "Created track entity with parameters:" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "length: " << length << std::endl;
        std::cout << "width: " << width << std::endl;
        std::cout << "Number of defined curves: " << curves.size() << std::endl;
        #endif
    }

template<typename T>
std::string Track<T>::default_track_name(){
    std::string result = "track";
    if(Track<T>::track_index < 10){
        result += "0";
    }
    result += std::to_string(Track<T>::track_index);
    Track<T>::track_index++;
    return result;
}

template<typename T>
void Track<T>::Print(){
    std::cout << "Track: '" << this->name << "'\tlength: " << this->length << "\twidth: " << this->width << "\tno. of Bezier curves: " << this->curves.size() << std::endl;
}

template<typename T>
Track<T> Track<T>::GenerateTrack(std::string &type) {
    std::cout << "Generating Track: " << std::endl;
    if(type == "Vector2") {
        char bezierAnswer = 'y';
        char vectorAnswer = 'y';
        bool valid;
        double x, y;
        std::string temp;
        std::vector<Bezier<Vector2<double>>> *bezierList;
        Bezier<Vector2<double>> *bezier;
        Vector2<double> *vector;

        std::cout << "\tstarting at the origin (0, 0)" << std::endl;

        vector->x = 0;
        vector->y = 0;

        bezier->addPoint(vector);

        while(bezierAnswer == 'y') {
            vector->x = (bezier->points.head)->value.x;
            vector->y = (bezier->points.head)->value.y;

            bezier->clear();

            bezier->addPoint(vector);

            while(vectorAnswer == 'y') {
                std::cout << "\tspecify the next point: \n";
                do{
                    std::cout << "\t\tx: ";
                    std::cin >> x;
                    std::cout << "\t\ty: ";
                    std::cin >> y;

                    vector->x = x;
                    vector->y = y;

                    if(bezier->m_points == 0) {
                        //TODO: check if the point is valid.
                        
                        std::cout << "Invalid point. The point should lie on the line going through the penultimate and last points in last Bezier curve, to ensure continuity C1.\n";
                    } else {
                        valid = true;
                    }
                } while(valid);
                

                bezier->addPoint(vector);

                std::cout << "Points in this bezier: " << bezier->m_points << std::endl;

                std::cout << "\n\tDo you wish to continue adding points to this bezier? (y/n): ";
                std::cin >> vectorAnswer;
            }

            bezierList->push_back(bezier);
            std::cout << "Number of Bezier curves: " << bezierList->size() << std::endl;


            std::cout << "\n\tDo you wish to continue? (y/n): ";
            std::cin >> bezierAnswer;
        }
    }
}

template class Track<Bezier<Vector2<double>>>;
template class Track<Bezier<Vector3<double>>>;
