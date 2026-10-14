/*  Используя инструкцию do … while написать программу нахождения такого
    наименьшего n, для которого (1 + 1/2 + 1/3 + … + 1/n) > f(x). Значение
    х вводится с клавиатуры, а f(x) = 3.9x^2 + cos(x) */

#include "input.h"
#include <cmath>
#define EGAMMA 0.5772156649015328606

int main () {
    bool is_euler_method = false;
    const double x = std::stod(input_numbers("Введите x: ", 1).at(0));
    if (x > 2.0) {
        is_euler_method = true;
    }
    const double f = 3.9*x*x + std::cos(x);

    uint64_t n = 0;
    double sum = 0.0f;
    do {
        n++;
        sum = is_euler_method ? std::log(n) + EGAMMA : sum + 1.0/static_cast<double>(n);
    } while (sum <= f);

    std::cout << "Искомое n = " << n << std::endl;
}