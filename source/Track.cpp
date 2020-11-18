#define _DEBUG

#include "Track.h"

template <typename T>
Track<T>::Track(const std::vector<T> &curves, const std::string &name, const double &length, const double &width)
    : name(name), length(length), width(width), curves(curves){
        #ifdef _DEBUG
        std::cout << "Created track entity with parameters:" << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "length: " << length << std::endl;
        std::cout << "width: " << width << std::endl;
        std::cout << "Number of defined curves: " << curves.size() << std::endl;
        #endif
    }

template class Track<Bezier2>;
template class Track<Bezier3>;

template <typename T>
std::string Track<T>::default_track_name(){
    std::string result = "track";
    if(Track<T>::track_index < 10){
        result += "0";
    }
    result += std::to_string(Track<T>::track_index);
    Track<T>::track_index++;
    return result;
}