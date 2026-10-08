// Программа для вычисления площади четырехугольника, если
// заданы координаты его вершин (x1, y1), (х2, y2), (x3, y3), (x4, y4)

#include <iostream>
#include "input.h"
#include <algorithm>

struct Side {
    double length;

    Side(const Point& a, const Point& b) {
        length = std::sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));
    }

    bool operator==(const Side& compared) const {
        return this->length == compared.length;
    }
};

int main() {
    const std::vector<std::string> tokens = input_numbers("Введите x1, y1, x2, y2, x3, y3, x4 и y4 через пробел:\n", 8);

    std::vector<Point> points;
    for (size_t i = 0; i < tokens.size()-1; i += 2) {
        Point point = Point(tokens.at(i), tokens.at(i+1));
        if (std::find(points.begin(), points.end(), point) != points.end()) {
            std::cout << "Координаты введеных точек повторяются!\n";
            return 0;
        }
        points.push_back(point);
    }

    std::vector<Side> sides;
    /*  index_pairs - индексы пар точек, из которых составляются стороны, которые надо
        проверить на равенство между собой */
    std::vector<std::vector<uint8_t>> const index_pairs = {{0,1}, {1,2}, {2,3}, {3,0}};
    for (const std::vector<uint8_t>& pair : index_pairs) {
        Side side = Side(points[pair[0]], points[pair[1]]);
        // одинаковые по длине стороны не дублируются в векторе сторон
        if (std::find(sides.begin(), sides.end(), side) == sides.end()) {
            sides.push_back(side);
        }
    }

    double rect_area = 0.0;
    bool wrong_coords = false;
    switch (sides.size()) {
    /*  в случае наличия лишь одной стороны считается, что остальные три равны первой ->
        введены координаты квадрата*/
    case 1:
        rect_area = pow(sides.at(0).length, 2.0);
        break;
    /*  в случае наличия двух -> остальные две равны первым двум, введены координаты
        прямоугольника */
    case 2:
        rect_area = sides.at(0).length * sides.at(1).length;
        break;
    default:
        std::cout << "Введены координаты не прямоугольника!\n";
        wrong_coords = true;
        break;
    }

    if (not wrong_coords) {
        std::cout << "Площадь прямоугольника равна " << rect_area << ".\n";
    }
    return 0;
}
