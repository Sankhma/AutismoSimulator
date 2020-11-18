#pragma once

#include <string>
#include <vector>

#include "Bezier.h"

// default set to Bezier2, might be usefull later on to change to Bezier3
template <typename T>
class Track{
public:
    inline static unsigned char track_index = 0;

    std::string name;
    double length;
    double width;
    std::vector<T> curves;

    Track(const std::vector<T> &curves, const std::string &name = default_track_name(), const double &length = 0., const double &width = 0.);

    //TODO: variadic template for multiple options
    // Track(const std::vector<Bezier2> &curves, ...);

    void Print();

    static std::string default_track_name();
};