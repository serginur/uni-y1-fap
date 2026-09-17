#include <iostream>
#include "input_coords.h"
#include <vector>

int main() {
    std::vector<std::string> tokens = input_coordinates("Введите координаты точки x и y:\n", 2);
    Point point(tokens.at(0), tokens.at(1));

    

    return 0;
}
