/*  Программа для вычисления площади четырехугольника, если
    заданы координаты его вершин (x1, y1), (х2, y2), (x3, y3), (x4, y4) */
//TODO: ЧЕТ НЕ РАБОТАЕТ ЗАДУМКО!!!
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

// struct Rectangle {
//     std::vector<Line> lines;
//     double area = 0.0;
//
//     Rectangle() {
//         lines.emplace_back(Point{0, 0}, Point{0, 0});
//     }
//
//     void add_line(const Line& new_line) {
//         bool is_doubling = false;
//         for (const Line& line : lines) {
//             if (line.points[0] == new_line.points[0] && line.points[1] == new_line.points[1]) {
//                 is_doubling = true;
//             }
//         }
//         if (not is_doubling) {
//             lines.emplace_back(new_line);
//         }
//     }
// };

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
            bool is_diagonal = false;
            for (const Line & diagonal : diagonals) {
                if (not diagonal.compare_points(start_point, end_point)) {
                    is_diagonal = true;
                    break;
                }
            }
            if (not is_diagonal) {
                bool is_doubling = false;
                Line line = Line{start_point, end_point};
                for (const Line & side : sides) {
                    if (not side.compare_points(line) && side != line) {
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

    double rect_area = 0.0;
    switch (sides.size()) {
        case 1:
            rect_area = sides.at(0).length*sides.at(0).length;
            break;
        case 2:
            rect_area = sides.at(0).length*sides.at(1).length;
        default:
            rect_area = -1.0;
    }

    std::cout << rect_area << sides.size() << std::endl;

    // //  создаём всевозможные отрезки из полученных точек без дублирования
    // //  одновременно ищем самый длинный отрезок
    // std::vector<Line> lines;
    // double max_line_length = 0.0;
    // for (const Point& start_point : points) {
    //     for (const Point& end_point : points) {
    //         if (start_point != end_point) {
    //             bool is_doubling = false;
    //             for (const Line& line : lines) {
    //                 if (line.points[0] == end_point && line.points[1] == start_point) {
    //                     is_doubling = true;
    //                     break;
    //                 }
    //             }
    //             if (not is_doubling) {
    //                 lines.emplace_back(start_point, end_point);
    //                 if (lines.back().length > max_line_length) {
    //                     max_line_length = lines.back().length;
    //                 }
    //             }
    //         }
    //     }
    // }

    // //  самыми длинными должны быть две равные диагонали
    // std::vector<uint8_t> max_lines;
    // for (uint8_t i = 0; i < lines.size(); i++) {
    //     if (lines.at(i).length == max_line_length) {
    //         max_lines.push_back(i);
    //     }
    // }

    // //  если самых длинных отрезков не 2 - это не прямоугольник
    // if (max_lines.size() != 2) {
    //     std::cout << "Введены координаты не прямоугольника!" << std::endl;
    //     return 0;
    // }

    // // удаляем все самые длинные отрезки из вектора
    // for (uint8_t i = max_lines.size()-1; i > 0; i--) {
    //     lines.erase(lines.begin() + max_lines.at(i));
    // }

    // double rect_area = 0.0;
    // bool wrong_coords = false;
    // switch (lines.size()) {
    // /*  в случае наличия лишь одной стороны считается, что остальные три равны первой ->
    //     введены координаты квадрата*/
    // case 1:
    //     rect_area = pow(lines.at(0).length, 2.0);
    //     break;
    // /*  в случае наличия двух -> остальные две равны первым двум, введены координаты
    //     прямоугольника */
    // case 2:
    //     rect_area = lines.at(0).length * lines.at(1).length;
    //     break;
    // default:
    //     std::cout << "Введены координаты не прямоугольника!\n";
    //     wrong_coords = true;
    //     break;
    // }
    //
    // if (not wrong_coords) {
    //     std::cout << "Площадь прямоугольника равна " << rect_area << ".\n";
    // }
    return 0;
}
