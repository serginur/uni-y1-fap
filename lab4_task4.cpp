// Определение принадлежности точки с координатами (x,y) заштрихованной области

#include <iostream>
#include "input.h"
#include <vector>

int main() {
    std::vector<std::string> tokens = input_numbers("Введите координаты точки x и y: ", 2);
    double x = std::stod(tokens.at(0));
    double y = std::stod(tokens.at(1));

    if (x*x + y*y >= 4 && ((((x >= 0 && y <= 0) || (x <= 0 && y >= 0)) && x*x + y*y <= 16) || (x > 0 && y > 0 && x <= 16 && y <= 16) || (x < 0 && y < 0 && -x-y <= 4))) {
        std::cout << "Данная точка входит в заштрихованную область.\n";
    } else {
        std::cout << "Данная точка не входит в заштрихованную область.\n";
    }
    return 0;
}
