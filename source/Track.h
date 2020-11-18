#pragma once

#include <string>
#include <vector>

#include "Bezier.h"

template <typename T>
struct Track{
    inline static unsigned char track_index = 0;

    std::string name;
    double length;
    double width;
    std::vector<T> curves;

private:
    static std::string default_track_name();

public:
    /**
     * Constructor for Track class.
     * @param curves A vector of Bezier curves.
     * @param name Name that will be assigned to the track, if not specified it will generate trackxx (xx signifies no. of track eg. 00, 10, 99).
     * @param length Length of a circuit default 0.
     * @param width Width of a circuit default 0.
     * @returns A new Track object.
     */
    Track(const std::vector<T> &curves, const std::string &name = default_track_name(), const double &length = 0., const double &width = 0.);

    //TODO: variadic template for multiple options
    // Track(const std::vector<Bezier2> &curves, ...);

    /**
     * Prints name, length, width, and number of Bezier curves it is defined by. Ends with a new line.
     */
    void Print();
};