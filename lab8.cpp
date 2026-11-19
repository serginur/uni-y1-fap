/* f(x) – непрерывная и дифференцируемая достаточное число раз на отрезке [a, b]
функция и h = (b-a)/n, xk = x0 + kh (k=0, 1, 2, …, n), yk = f(xk).
Написать программу, в которой с помощью формул левых, правых, трапеций
и Симпсона вычислить приближенные значения интегралов функций на указанном
отрезке [a, b]. Значение a и b вводятся с клавиатуры. Значение k вводится с клавиатуры.
Интегралы вычисляются для n=k и n=10k. В программе предусмотреть вывод значений
с 4 цифрами после десятичной точки. В результате выполнения программы на экран
вывести как соответствующие приближенные значения интеграла, так и точное значение
(вычисленное по соответствующей формуле). В программе предусмотреть использование
четырех функций (соответственно для вычисления по формулам левых, правых,
трапеций, Симпсона)!!!
15. f(x) = 0.7x+2.1sin(x)+1.6 на отрезке [0; π/3]*/

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

double h(const double& a, const double& b, const uint16_t& n) {
    return (b-a)/n;
}

double integral_left(const double& h, const double& a, const uint16_t& n) {
    double x = a;
    double sum = 0.0;
    for (uint16_t k = 0; k < n; k++) {
        x += k*h;
        sum += func(x);
    }
    return h*sum;
}

double integral_right(const double& h, const double& a, const uint16_t& n) {
    double x = a;
    double sum = 0.0;
    for (uint16_t k = 1; k <= n; k++) {
        x += k*h;
        sum += func(x);
    }
    return h*sum;
}

double integral_trapeze(const double& h, const double& a, const uint16_t& n) {
    double x = a;
    double sum = (func(x)+func(x + n*h)/2.0);
    for (uint16_t k = 1; k <= n; k++) {
        x += k*h;
        sum += func(x);
    }
    return h*sum;
}

double integral_simpson(const double& h, const double& a, const uint16_t& n) {
    double x = a;
    double sum = func(x) + func(x + n*h);
    double odds_sum = 0.0;
    for (uint16_t k = 1; k <= n/2; k += 2) {
        odds_sum += func(x + k*h);
    }
    sum += 4.0*odds_sum;
    double evens_sum = 0.0;
    for (uint16_t k = 2; k <= n/2 - 1; k += 2) {
        evens_sum += func(x + k*h);
    }
    sum += 2.0*evens_sum;
    return h/3.0*sum;
}

int main() {
    double a, b;
    do {
        std::cout << "Введите a и b в пределах [0; π/3]: ";
        std::cin >> a >> b;
        if (a < min_a || b > max_b) {
            std::cout << "Ошибка! a и b не должны быть меньше 0 и больше π/3!\n";
        }
        if (a > b) {
            std::cout << "Ошибка! a должно быть меньше b!\n";
        }
    } while ((a < min_a || b > max_b) && a > b);
    uint16_t k;
    std::cout << "Введите k: ";
    std::cin >> k;
    std::cout << std::endl;

    uint16_t n1 = k;
    uint16_t n2 = k*10;

    std::cout << std::fixed;
    std::cout.precision(4);
    std::cout << "Точное значение интеграла: " << newton_leibniz(a, b) << '\n';

    std::cout << "Значение интеграла по формуле левых прямоугольников для n = k: "
    << integral_left(h(a, b, k), a, k) << '\n'
    << "Значение интеграла по формуле левых прямоугольников для n = 10k: "
    << integral_left(h(a, b, k*10), a, k*10) << std::endl;

    std::cout << "Значение интеграла по формуле правых прямоугольников для n = k: "
    << integral_right(h(a, b, k), a, k) << '\n'
    << "Значение интеграла по формуле правых прямоугольников для n = 10k: "
    << integral_right(h(a, b, k*10), a, k*10) << std::endl;

    std::cout << "Значение интеграла по формуле трапеций для n = k: "
    << integral_trapeze(h(a, b, k), a, k) << '\n'
    << "Значение интеграла по формуле трапеций для n = 10k: "
    << integral_trapeze(h(a, b, k*10), a, k*10) << std::endl;

    std::cout << "Значение интеграла по формуле Симпсона для n = k: "
    << integral_simpson(h(a, b, k), a, k) << '\n'
    << "Значение интеграла по формуле Симпсона для n = 10k: "
    << integral_simpson(h(a, b, k*10), a, k*10) << std::endl;
}