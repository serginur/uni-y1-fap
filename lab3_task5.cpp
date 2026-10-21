/*  Программа для вычисления площади четырехугольника, если
    заданы координаты его вершин (x1, y1), (х2, y2), (x3, y3), (x4, y4) */

#include <iostream>
#include "input.h"
#include <algorithm>
#include <map>

struct Line {
    double length;
    Point points[2];

    Line(const Point& a, const Point& b) : points{a, b} {
        const double x_length = points[1].x - points[0].x;
        const double y_length = points[1].y - points[0].y;
        length = std::sqrt(x_length * x_length + y_length * y_length);
    }

    bool compare_points(const Point& a, const Point& b) const {
        return (this->points[0] == a && this->points[1] == b) || (this->points[1] == a && this->points[0] == b);
    }

    bool compare_points(const Line& compared) const {
        return (this->points[0] == compared.points[0] && this->points[1] == compared.points[1]) || (this->points[1] == compared.points[0] && this->points[0] == compared.points[1]);
    }

    bool operator==(const Line& compared) const {
        return this->length == compared.length;
    }

    bool operator!=(const Line& compared) const {
        return this->length != compared.length;
    }
};

int main() {
    const std::vector<std::string> tokens = input_numbers("Введите координаты точек (x, y) прямоугольника через пробел:\n", 8);

    // заполнение вектора точками по введённым координатам
    std::vector<Point> points;
    for (size_t i = 0; i < tokens.size()-1; i += 2) {
        Point point = Point(tokens.at(i), tokens.at(i+1));
        if (std::find(points.begin(), points.end(), point) != points.end()) {
            std::cout << "Координаты введённых точек повторяются!\n";
            return 0;
        }
        points.push_back(point);
    }

    // поиск самых удаленных точек
    std::map<Point*, Point*> point_to_farthest;
    for (Point& start_point : points) {
        double max_length = 0.0;
        Point* farthest;
        for (Point& end_point : points) {
            if (start_point != end_point) {
                Line line = Line{start_point, end_point};
                if (line.length > max_length) {
                    max_length = line.length;
                    farthest = &end_point;
                }
            }
        }
        if (point_to_farthest.find(farthest) == point_to_farthest.end()) {
            point_to_farthest[&start_point] = farthest;
        }
    }

    std::vector<Line> diagonals;
    diagonals.reserve(2);
    for (const auto& kv : point_to_farthest) {
        diagonals.emplace_back(*kv.first, *kv.second);
    }

    if (diagonals.at(0).length != diagonals.at(1).length) {
        std::cout << "Координаты не соответствуют прямоугольнику!" << std::endl;
        return 0;
    }

    // создаём всевозможные отрезки из полученных точек без дублирования
    std::vector<Line> sides;
    for (const Point& start_point : points) {
        for (const Point& end_point : points) {
            if (start_point != end_point) {
                bool is_diagonal = false;
                for (const Line& diagonal : diagonals) {
                    if (diagonal.compare_points(start_point, end_point)) {
                        is_diagonal = true;
                        break;
                    }
                }
                if (not is_diagonal) {
                    bool is_doubling = false;
                    Line line = Line{start_point, end_point};
                    for (const Line& side : sides) {
                        if (side.compare_points(line) || side == line) {
                            is_doubling = true;
                            break;
                        }
                    }
                    if (not is_doubling) {
                        sides.emplace_back(line);
                    }
                }
            }
        }
    }

    double rect_area = 0.0;
    switch (sides.size()) {
        case 1:
            rect_area = sides.at(0).length*sides.at(0).length;
            break;
        case 2:
            rect_area = sides.at(0).length*sides.at(1).length;
            break;
        default:
            rect_area = -1.0;
    }

    std::cout << "Площадь прямоугольника: " << rect_area << std::endl;
    return 0;
}
