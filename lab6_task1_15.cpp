/*  Используя инструкцию while написать программу для вывода на экран
    таблицы значений функции F(x) в диапазоне от Xнач. до Xконеч. с шагом dx.
    f(x) = 1.9x^2 - 1.7/(x^2 - 9) + cos(x) */

#include "input.h"
#include <cmath>
#include <iomanip>

int main() {
    std::vector<std::string> arguments = input_numbers("Введите x начальное, x конечное и dx: ", 3);
    double x1 = std::stod(arguments.at(0));
    double x2 = std::stod(arguments.at(1));
    double dx = std::stod(arguments.at(2));

    if (x1 < x2) {
        if (dx <= 0) {
            std::cout << "dx <= 0, а x1 < x2!" << std::endl;
            return 0;
        }
        if (x2-x1 / dx - round(x2-x1 / dx) > 0.000001) {
            std::cout << "разница между x1 и x2 не делится нацело на dx!" << std::endl;
            return 0;
        }
    } else if (x1 > x2) {
        if (dx >= 0) {
            std::cout << "dx >= 0, а x1 > 2!" << std::endl;
            return 0;
        }
        if (x1-x2 / dx - round((x1-x2) / dx) > 0.000001) {
            std::cout << "разница между x1 и x2 не делится нацело на dx!" << std::endl;
            return 0;
        }
    } else {
        if (dx != 0.0) {
            std::cout << "dx != 0, а x1 = x2!" << std::endl;
            return 0;
        }
    }

    std::cout << "_________________________\n";
    std::cout << "|      x|           f(x)|\n";
    std::cout << "-------------------------\n";
    while (x1 <= x2) {
        std::cout << "|" << std::setw(7) << x1 << "|"\
            << std::setw(15) << 1.9*x1*x1 - 1.7/(x1*x1 - 9.0) + std::cos(x1) << "|\n";;
        x1 += dx;
    }
    std::cout << "_________________________\n";

    return 0;
}
