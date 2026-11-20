/* Программу из предыдущего задания преобразовать таким образом, чтобы вычисление
интегралов на основе формул левых, правых, трапеций и Симпсона было реализовано
на основе использования механизма перегрузки функций.*/

#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846
constexpr double min_a = 0.0;
constexpr double max_b = PI/3.0;

double func(const double& x) {
    return 0.7*x + 2.1*std::sin(x) + 1.6;
}

double pre_func(const double& x) {
    return 0.35*x*x - 2.1*std::cos(x) + 1.6*x;
}

double newton_leibniz(const double& a, const double& b) {
    return pre_func(b) - pre_func(a);
}

double get_h(const double& a, const double& b, const uint16_t& n) {
        return (b-a)/n;
}

double integral(const double *func_values, const uint16_t& max_k, const double& h, const bool& is_right_rect) {
    // Расчет по формулам левых и правых прямоугольников
    double sum = 0.0;
    for (uint16_t k = is_right_rect; k <= max_k-1 + is_right_rect; k++) {
        sum += func_values[k];
    }
    return h*sum;
}

double integral(const double *func_values, const uint16_t& max_k, const double& h) {
    // Расчет по формуле трапеций
    double sum = (func_values[0]+func_values[max_k])/2.0;
    for (uint16_t k = 1; k <= max_k-1; k++) {
        sum += func_values[k];
    }
    return h*sum;
}

double integral(const double *func_values, const uint16_t& max_k, const double& h, const double& a, const double& b) {
    // Расчет по формуле Симпсона
    if (max_k != 2) {
        double sum = func_values[0] + func_values[max_k];

        double odds_sum = 0.0;
        for (uint16_t k = 1; k <= max_k - 1; k += 2) {
            odds_sum += func_values[k];
        }
        sum += 4.0*odds_sum;

        double evens_sum = 0.0;
        for (uint16_t k = 2; k <= max_k - 2; k += 2) {
            evens_sum += func_values[k];
        }
        sum += 2.0*evens_sum;

        return h/3.0*sum;
    }
    // в случае max_k == 2 формула упрощается
    return (b-a)/6.0*(func(a) + 4*func((a+b)/2) + func(b));
}

int main() {
    double a, b;
    do {
        std::cout << "Введите a и b в пределах [0; π/3]: ";
        std::cin >> a >> b;
        if (a < min_a || b > max_b) {
            std::cout << "Ошибка! a и b не должны быть меньше 0 и больше π/3!\n"; continue;
        }
        if (a > b) {
            std::cout << "Ошибка! a должно быть меньше b!\n"; continue;
        }
        break;
    } while (true);
    uint16_t k;
    std::cout << "Введите k: ";
    do {
        std::cin >> k;
        if (k%2 != 0) {
            std::cout << "Ошибка! В связи с использованием формулы Симпсона k должно быть чётным!\n";
            continue;
        }
        break;
    } while (true);
    std::cout << std::endl;

    std::cout << std::fixed;
    std::cout.precision(4);
    std::cout << "Точное значение интеграла: " << newton_leibniz(a, b) << '\n';

    const uint16_t n1 = k, n2 = k*10;
    const double h1 = get_h(a, b, n1), h2 = get_h(a, b, n2);
    double func_values1[k + 1], func_values2[k*10 + 1];
    for (uint16_t i = 0; i <= n2; i++) {
        if (i <= k) func_values1[i] = func(a + i*h1);
        func_values2[i] = func(a + i*h2);
    }

    std::cout << "Значение интеграла по формуле левых прямоугольников для n = k: "
    << integral(&func_values1[0], n1, h1, false) << '\n'
    << "Значение интеграла по формуле левых прямоугольников для n = 10k: "
    << integral(&func_values2[0], n2, h2, false) << std::endl;

    std::cout << "Значение интеграла по формуле правых прямоугольников для n = k: "
    << integral(&func_values1[0], n1, h1, true) << '\n'
    << "Значение интеграла по формуле правых прямоугольников для n = 10k: "
    << integral(&func_values2[0], n2, h2, true) << std::endl;

    std::cout << "Значение интеграла по формуле трапеций для n = k: "
    << integral(&func_values1[0], n1, h1) << '\n'
    << "Значение интеграла по формуле трапеций для n = 10k: "
    << integral(&func_values2[0], n2, h2) << std::endl;

    std::cout << "Значение интеграла по формуле Симпсона для n = k: "
    << integral(&func_values1[0], n1, h1, a, b) << '\n'
    << "Значение интеграла по формуле Симпсона для n = 10k: "
    << integral(&func_values2[0], n2, h2, a, b) << std::endl;
}