/*  Написать программу, в которой с помощью метода деления отрезка пополам найти и
    вывести действительное значение корня на отрезке [a, b] с точностью 0.005. Значения
    a и b необходимо предварительно определить (перед выполнением программы), причем
    длина интервала [a, b] не должна быть больше 1.
    В процессе выполнения программы ввести значения a и b с клавиатуры и предусмотреть
    вывод промежуточных результатов вычисления корня с 5 знаками после десятичной
    точки. f(x) = 0.7x^3 - 7x - 8*/

#include <iostream>
#include <cmath>
#include <iomanip>

void input_a_b(double &a, double &b) {
    while (true) {
        std::cout << "Введите 'a': ";
        std::cin >> a;
        std::cout << "Введите 'b': ";
        std::cin >> b;
        std::cout.flush();

        if (a >= b) {
            std::cout << "'a' должно быть меньше 'b'!\n";
            continue;
        }
        if (b - a > 1) {
            std::cout << "Длина интервала [a, b] должна быть ≤1!\n";
            continue;
        }
        const double f_a = 0.7f*(a*a*a) - 7*a - 8;
        const double f_b = 0.7f*(b*b*b) - 7*b - 8;
        if (f_a < 0 && f_b < 0 || f_a > 0 && f_b > 0) {
            std::cout << "На данном промежутке нет корней!\n";
            continue;
        }
        break;
    }
}

int get_length_of_number(double num) {
    int len = 6;
    if (num < 0) len++;
    int temp = static_cast<int>(num);
    while (temp > 0) {
        temp /= 10; len++;
    }
    return len;
}

int main () {
    double a, b, x, f;
    input_a_b(a, b);

    std::cout << "\n┏━━━━━━━━━━━━━┳━━━━━━━━━━━━━┓\n"
      << std::setfill(' ') << "┃" << std::setw(7) << "x" << std::setw(9)
        << "┃" << std::setw(9) << "f (x)" << std::setw(7) << "┃"
          << "\n┣━━━━━━━━━━━━━╋━━━━━━━━━━━━━┫" << std::endl;

    std::cout << std::fixed << std::setprecision(6);
    while (true) {
        x = (b+a) / 2;
        f = 0.7f*(x*x*x) - 7*x - 8;

        int x_len = get_length_of_number(x)/2;
        int f_len = get_length_of_number(f)/2;

        std::cout << "┃" << std::setw(8+x_len) << x << std::setw(8-x_len) <<
          "┃" << std::setw(8+f_len) << f << std::setw(8-f_len) << "┃" << std::endl;
        if (std::abs(f) <= 0.005) {
            break;
        }

        const double f_a = 0.7f*(a*a*a) - 7*a - 8;
        if (f < 0) {
            if (f_a < 0) a = x;
            else b = x;
        } else {
            if (f_a > 0) a = x;
            else b = x;
        }
    }

    std::cout << "┗━━━━━━━━━━━━━┻━━━━━━━━━━━━━┛\n";
    std::cout << std::setprecision(6) << "x = " << x << "\nf(x) = " << f << std::endl;
    return 0;
}