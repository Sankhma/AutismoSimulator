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
        double x, y;
        std::string temp;
        Bezier<Vector2<double>> bezier;

        std::cout << "\tstarting at the origin (0, 0)" << std::endl;;
        std::cout << "\tspecify the next point: ";
        std::cin >> x, y;

        
    }
}

template class Track<Bezier<Vector2<double>>>;
template class Track<Bezier<Vector3<double>>>;
