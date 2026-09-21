#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Point {
    double x, y;

    Point(const double new_x, const double new_y) {
        x = new_x; y = new_y;
    }
    Point(const std::string& new_x, const std::string& new_y) {
        x = std::stod(new_x); y = std::stod(new_y);
    }

    bool operator==(const Point& compared) const {
        return this->x == compared.x && this->y == compared.y;
    }
};

inline void wrong_input(const std::string& token) {
    std::cout << "Неверный ввод: " << token << '\n';
}

inline void input_tokens(std::vector<std::string> *tokens) {
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

inline std::vector<std::string> input_numbers(const std::string& input_prompt, const size_t num_of_tokens) {
    std::vector<std::string> tokens;
    bool input_check = false;
    while (not input_check) {
        if (not tokens.empty()) {tokens.clear();}
        std::cout << input_prompt;
        input_tokens(&tokens);

        if (tokens.size() != num_of_tokens) {
            std::cout << "Введено неверное количество переменных: "\
                        << tokens.size() << '\n';
            continue;
        }

        bool is_wrong = false;
        for (std::string& t : tokens) {
            bool is_negative = false;
            bool is_float = false;
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
                        if (is_float) {
                            is_wrong = true;
                            break;
                        } else {
                            is_float = true;
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
                    wrong_input(t);
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

inline std::vector<std::string> input_natural_numbers(const std::string& input_prompt, const size_t num_of_tokens, const bool is_positive) {
    std::vector<std::string> tokens;
    bool input_check = false;
    while (not input_check) {
        if (not tokens.empty()) {tokens.clear();}
        std::cout << input_prompt;
        input_tokens(&tokens);

        if (tokens.size() != num_of_tokens) {
            std::cout << "Введено неверное количество переменных: "\
                        << tokens.size() << '\n';
            continue;
        }

        bool is_wrong = false;
        for (std::string& t : tokens) {
            bool is_negative = false;
            for (size_t i = 0; i < t.size(); i++) {
                switch (t.at(i)) {
                    case '-':
                        if (not is_positive) {
                            if (i != 0 || is_negative) {
                                is_wrong = true;
                                break;
                            } else {
                                is_negative = true;
                            }
                        } else {
                            is_wrong = true;
                            break;
                        }
                        break;
                    case ',' | '.':
                        is_wrong = true;
                        break;
                    default:
                        if (t.at(i) < '0' || t.at(i) > '9') {
                            is_wrong = true;
                            break;
                        }
                        break;
                }
                if (is_wrong) {
                    wrong_input(t);
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


inline char input_symbol(const std::string& input_prompt) {
    std::vector<std::string> tokens;
    bool input_check = false;
    while (not input_check) {
        std::cout << input_prompt;
        input_tokens(&tokens);
        std::cout << std::endl;

        if (tokens.size() > 1) {
            std::cout << "Введено неверное количество символов: "\
                        << tokens.size() << '\n';
            continue;
        }

        if (tokens.at(0).size() > 1) {
            std::cout << "Введено больше одного символа!" << '\n';
            continue;
        }

        input_check = true;
    }

    return tokens.at(0).at(0);
}
