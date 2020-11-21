#include <iostream>
#include <vector>
#include <string>

#include "Vector.h"
#include "Bezier.h"
#include "Math.h"
#include "Track.h"

int main(){
    int len = 10;
    int width = 3;

    std::string name = "siemano";

    Vector3<double> vec1 = {69, 420, 69};
    Vector3<double> vec2 = {420, 69, 420};

    Bezier3 bez = Bezier3(3, &vec1, &vec2, &vec1);

    std::vector<Bezier3> empty{};
    Track<Bezier3> track0(empty);

    std::vector<Bezier3> not_empty = {bez};
    Track<Bezier3> track1(not_empty, name, len, width);

    track1.Print();
}