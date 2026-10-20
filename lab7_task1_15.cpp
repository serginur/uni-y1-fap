/*  Используя инструкцию for написать программу для вычисления S, где k вводится
    с клавиатуры, а S задается формулой: S = (i=1 to k)∑(i + (7.5*i)/(1.5*i + k))*/

#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string input;
    while (true) {
        std::cout << "Введите натуральное k: ";
        std::cin >> input;
        bool is_wrong = false;
        for (const char& c : input) {
            if (not std::isdigit(c)) {
                is_wrong = true;
                std::cout << "Введите натуральное число!" << std::endl;
                break;
            }
        }
        if (is_wrong) {
            input.clear();
            continue;
        }
        break;
    }

    const uint64_t k = std::stoul(input);
    double sum = 0.0;
    for (uint64_t i = 1; i <= k; i++) {
        const auto d_i = static_cast<double>(i);
        const auto d_k = static_cast<double>(k);
        sum += d_i + (7.5*d_i)/(1.5*d_i + d_k);
    }
    std::cout << sum << std::endl;
}
