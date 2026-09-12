// Программа для вычисления площади четырехугольника, если
// заданы координаты его вершин (x1, y1), (х2, y2), (x3, y3), (x4, y4)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void wrong_coordinate(const std::string& token) {
    std::cout << "Неверный ввод координаты: " << token << '\n';
}

template<typename T>
void clear_input(std::vector<T>& vec, std::istringstream& iss) {
    vec.clear();
    iss.clear();
    iss.str("");
}

struct Point {
    double x, y;

    Point(double new_x, double new_y) {
        x = new_x; y = new_y;
    }

    bool operator==(const Point& compared) const {
        return this->x == compared.x && this->y == compared.y;
    }
};

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
    std::vector<std::string> tokens;
    bool input_check = false;
    while (not input_check) {

        std::cout << "Введите x1, y1, x2, y2, x3, y3, x4 и y4 через пробел:\n";
        std::string input;
        std::getline(std::cin, input);
        
        std::string token;
        std::istringstream input_stream(input);
        while (input_stream >> token) {
            tokens.push_back(token);
        }

        if (tokens.size() != 8) {
            std::cout << "Введено неверное количество координат: "\
             << tokens.size() << '\n';
            clear_input(tokens, input_stream);
            continue;
        }

        for (std::string& t : tokens) {
            bool is_negative = false;
            int point_pos = -1;
            for (size_t i = 0; i < t.size(); i++) {
                switch (t.at(i)) {
                    case '-':
                    if (i != 0 || is_negative) {
                        wrong_coordinate(t);
                        clear_input(tokens, input_stream);
                        continue;
                    } else {
                        is_negative = true;
                    }
                    break;
                    case ',' | '.':
                    if (point_pos != -1) {
                        wrong_coordinate(t);
                        clear_input(tokens, input_stream);
                        continue;
                    } else {
                        point_pos = i;
                    }
                    break;
                    default:
                    if (t.at(i) < '0' || t.at(i) > '9') {
                        wrong_coordinate(t);
                        clear_input(tokens, input_stream);
                        continue;
                    }
                    break;
                }
            }
        }
        input_check = true;
    }

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
        std::cout << "Введены координаты не прямоугольника; " \
            << "количество равных сторон - " << 4 - sides.size() << '\n';
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
