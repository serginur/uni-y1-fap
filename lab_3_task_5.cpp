// Программа для вычисления площади четырехугольника, если
// заданы координаты его вершин (x1, y1), (х2, y2), (x3, y3), (x4, y4)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
        std::cout << "Point (" << x << ", " << y << ") added;\n";
    }
};

struct Side {
    double length;

    Side(Point a, Point b) {
        std::cout << "Side with (" << a.x << ", " << a.y;
        std::cout << ") and (" << b.x << ", " << b.y << ")";
        length = std::sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));
        std::cout << " with length = " << length << " added;\n";
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
        points.emplace_back(Point(stod(tokens.at(i)), stod(tokens.at(i+1))));
    }

    std::vector<Side> sides;
    std::vector<std::vector<uint8_t>> pairs = {{0,1}, {1,2}, {2,3}, {3,0}};
    for (const std::vector<uint8_t>& pair : pairs) {
        sides.emplace_back(Side(points[pair[0]], points[pair[1]]));
    }


    //TODO: Перепроверить алгоритм проверки равности сторон
    
    int equal_sides = 0;
    for (uint8_t i = 0; i < sides.size(); i++) {
        for (uint8_t j = 0; j < sides.size(); j++) {
            if (j == i) continue;
            if (sides.at(j).length == sides.at(j).length) equal_sides++;
        }
        if (i == 0 && equal_sides == 3) break;
        if (equal_sides != 4) {
            std::cout << "Введены координаты НЕ прямоугольника, равных сторон " << equal_sides << '\n';
            return 0; 
        }
    }

    // std::cout << std::string(37, '_') << "POINTS" << std::string(37, '_') << "\n";
    // for (const Point& point : points) {
    //     std::cout << point.x;
    //     std::cout << "\t|\t";
    //     std::cout << point.y;
    //     std::cout << '\n';
    // }
    return 0;
}
