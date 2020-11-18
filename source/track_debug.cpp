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

    std::vector<Bezier2> empty = {};
    Track<> track0 = Track<>(empty);

    std::vector<Bezier2> not_empty = {bez};
    Track<> track1 = Track<>(not_empty, name, len, width);
}