#include <iostream>
#include "input_coords.h"
#include <vector>

void answer(const uint8_t& is_it) {
    std::string no = (is_it == 0) ? " не " : "  ";
    std::cout << "Данная точка" << no << "входит в заштрихованную область.\n";
}

int main() {
    std::vector<std::string> tokens = input_coordinates("Введите координаты точки x и y:\n", 2);
    double x = std::stod(tokens.at(0));
    double y = std::stod(tokens.at(1));

    if (pow(y, 2.0) + pow(y, 2.0) <= 4) {
        answer(0);
    } else if ((x > 0 && y > 0) && (x <= 4 && y <= 4)) {
        answer(1);
    } else if ((x < 0 && y < 0) && (-x - y <= 4)) {
        answer(1);
    } else if (((x < 0 && y > 0) || (x > 0 && y < 0)) && (pow(x, 2.0) + pow(y, 2.0) <= 16)) {
        answer(1);
    } else {
        answer(0);
    }

    return 0;
}
