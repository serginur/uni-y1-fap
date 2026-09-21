/*  Используя инструкцию do … while написать программу нахождения такого
    наименьшего n, для которого (1 + 1/2 + 1/3 + … + 1/n) > f(x). Значение
    х вводится с клавиатуры, а f(x) = 3.9x^2 + cos(x) */

#include "input.h"

int main () {
    const double x = std::stod(input_numbers("Введите x: ", 1).at(0));
    const double f = 3.9*std::pow(x, 2.0f) + std::cos(x);

    uint64_t n = 0;
    double sum = 0.0f;
    do {
        n++;
        sum += 1.0f/n;
    } while (sum <= f);

    std::cout << "Искомое n = " << n << std::endl;
}