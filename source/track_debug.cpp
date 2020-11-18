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

    Vector2 vec1 = {69, 420};
    Vector2 vec2 = {420, 69};

    Bezier2 bez = Bezier2(2, &vec1, &vec2);

    std::vector<Bezier2> empty{};
    Track<Bezier2> track0(empty);

    std::vector<Bezier2> not_empty = {bez};
    Track<Bezier2> track1(not_empty, name, len, width);
}