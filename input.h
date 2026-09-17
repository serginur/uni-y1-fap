#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Point {
    double x, y;

    Point(double new_x, double new_y) {
        x = new_x; y = new_y;
    }
    Point(const std::string& new_x, const std::string& new_y) {
        x = std::stod(new_x); y = std::stod(new_y);
    }

    bool operator==(const Point& compared) const {
        return this->x == compared.x && this->y == compared.y;
    }
};

void wrong_coordinate(const std::string& token) {
    std::cout << "Неверный ввод координаты: " << token << '\n';
}

void input_tokens(std::vector<std::string> *tokens) {
    std::string input;
    std::getline(std::cin, input);
    
    std::string token;
    std::istringstream input_stream(input);
    while (input_stream >> token) {
        tokens->push_back(token);
    }
    input_stream.clear();
    input_stream.str("");
}

std::vector<std::string> input_coordinates(const std::string& input_prompt, size_t num_of_tokens) {
    std::vector<std::string> tokens;
    bool input_check = false;
    while (not input_check) {
        if (tokens.size()) {tokens.clear();}
        std::cout << input_prompt;
        input_tokens(&tokens);

        if (tokens.size() != num_of_tokens) {
            std::cout << "Введено неверное количество координат: "\
             << tokens.size() << '\n';
            continue;
        }

        bool is_wrong = false;
        for (std::string& t : tokens) {
            bool is_negative = false;
            int8_t point_pos = -1;
            for (size_t i = 0; i < t.size(); i++) {
                switch (t.at(i)) {
                    case '-':
                        if (i != 0 || is_negative) {
                            is_wrong = true;
                            break;
                        } else {
                            is_negative = true;
                        }
                        break;
                    case ',' | '.':
                        if (point_pos != -1) {
                            is_wrong = true;
                            break;
                        } else {
                            point_pos = i;
                        }
                        break;
                    default:
                        if (t.at(i) < '0' || t.at(i) > '9') {
                            is_wrong = true;
                            break;
                        }
                        break;
                }
                if (is_wrong) {
                    wrong_coordinate(t);
                    break;
                }
            }
            if (is_wrong) {
                break;
            }
        }
        if (is_wrong) {
            continue;
        }
        input_check = true;
    }
    return tokens;
}

std::vector<std::string> input_symbol(const std::string& input_prompt, const std::string& allowed_chars) {
    std::vector<std::string> tokens;
    bool input_check = false;
    while (not input_check) {

        input_check = true;
    }

    return tokens;
}
