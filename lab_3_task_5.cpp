// Программа для вычисления площади четырехугольника, если
// заданы координаты его вершин (x1, y1), (х2, y2), (x3, y3), (x4, y4)

#include <iostream>
#include "input_coords.h"
#include <algorithm>

struct Side {
    double length;

    Side(Point a, Point b) {
        length = std::sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));
    }

    bool operator==(const Side& compared) const {
        return length == compared.length;
    }
};

int main() {
    std::vector<std::string> tokens = input_coordinates("Введите x1, y1, x2, y2, x3, y3, x4 и y4 через пробел:\n", 8);
    
    std::vector<Point> points;
    for (size_t i = 0; i < tokens.size() - 1; i += 2) {
        Point p = Point(stod(tokens.at(i)), stod(tokens.at(i+1)));
        if (std::find(points.begin(), points.end(), p) != points.end()) {
            std::cout << "Координаты введеных точек повторяются!\n";
            return 0;
        }
        points.push_back(p);
    }

    std::vector<Side> sides;
    std::vector<std::vector<uint8_t>> index_pairs = {{0,1}, {1,2}, {2,3}, {3,0}};
    for (const std::vector<uint8_t>& pair : index_pairs) {
        Side s = Side(points[pair[0]], points[pair[1]]);
        if (std::find(sides.begin(), sides.end(), s) == sides.end()) {
            sides.push_back(s);
        }
    }

    if (sides.size() != 1 && sides.size() != 2) {
        std::cout << "Введены координаты не прямоугольника!\n";
        return 0;
    }

    double rect_area;
    switch (sides.size()) {
    case 1:
        rect_area = pow(sides.at(0).length, 2.0);
        break;
    case 2:
        rect_area = sides.at(0).length * sides.at(1).length;
        break;
    default:
        break;
    }

    std::cout << "Площадь прямоугольника равна " << rect_area << ".\n";
    return 0;
}
