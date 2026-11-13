/*Написать программу, в которой с помощью генератора случайных значений формируются три
матрицы A, B, C вещественных значений размерности m x n (где значения 2<=m<=5 и 2<=m<=6
вводятся с клавиатуры).
Значения элементов матриц должны быть в диапазоне [-k, 2k], где значение 1.5<=k<=4.5 вводится
с клавиатуры.
В программе вывести на экран три сформированные матрицы и имя (имена) матриц(ы) с четным
количеством отрицательных элементов в нечетных столбцах*/

#include <iomanip>
#include <iostream>
#include <random>
#include "input.h"

constexpr uint32_t max_m = 5;
constexpr uint32_t max_n = 6;

void gen_array(double array[max_m][max_n], const int& m, const int& n, const double& k) {
    std::random_device rd;
    std::mt19937 gen(rd());

    const double min = -k;
    const double max = 2.0*k;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
        array[i][j] = (gen()/(gen.max()*1.0))*(max-min)+min;
}

void print_array(double array[max_m][max_n], const int& m, const int& n, const char& name) {
    std::cout.precision(5);
    std::cout << std::fixed;
    std::cout << "\n    ┏";
    for (uint32_t i = 0; i < n; i++) {
        std::cout << "━━━━━━━━";
        if (i != n-1) std::cout << "┳"; else std::cout << "┓\n";
    }
    for (int i = 0; i < m; i++) {
        if (i == m/2) std::cout << name << " = ";
        else std::cout << "    ";
        std::cout << "┃";
        for (int j = 0; j < n; j++) {
            if (array[i][j] > 0) std::cout << ' ';
            std::cout << array[i][j] << "┃";
        }
        std::cout << '\n';
    }
    std::cout << "    ┗";
    for (uint32_t i = 0; i < n; i++) {
        std::cout << "━━━━━━━━";
        if (i != n-1) std::cout << "┻"; else std::cout << "┛\n";
    }
}

uint16_t amount_of_negatives_in_odd_columns(double array[max_m][max_n], const int& m, const int& n) {
    uint16_t amount = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (j%2 != 0) if (array[i][j] < 0) amount += 1;
    return amount;
}

int main() {
    uint16_t m, n;
    do {
        std::cout << "Введите m (2 ≤ m ≤ 5): ";
        std::cin >> m;
        if (m < 2 || m > 5) {
            std::cout << "Ошибка!!! Число должно быть больше равно двух и меньше равно пяти!\n";
            continue;
        }
        break;
    } while (true);
    do {
        std::cout << "Введите n (2 ≤ n ≤ 6): ";
        std::cin >> n;
        if (n < 2 || n > 6) {
            std::cout << "Ошибка!!! Число должно быть больше равно двух и меньше равно шести!\n";
            continue;
        }
        break;
    } while (true);

    double k;
    do {
        std::cout << "Введите k (1.5 ≤ k ≤ 4.5): ";
        std::cin >> k;
        if (k < 1.5 || k > 4.5) {
            std::cout << "Ошибка!!! Число должно быть больше равно 1.5 и меньше равно 4.5!\n";
            continue;
        }
        break;
    } while (true);

    double A[max_m][max_n], B[max_m][max_n], C[max_m][max_n];
    gen_array(A, m, n, k);
    gen_array(B, m, n, k);
    gen_array(C, m, n, k);
    print_array(A, m, n, 'A');
    print_array(B, m, n, 'B');
    print_array(C, m, n, 'C');

    const bool is_even[3] = {
        amount_of_negatives_in_odd_columns(A, m, n)%2 == 0,
        amount_of_negatives_in_odd_columns(B, m, n)%2 == 0,
        amount_of_negatives_in_odd_columns(C, m, n)%2 == 0
    };
    std::cout << "Матрицы с четным количеством отрицательных элементов в нечетных столбцах: "
    << (is_even[0] ? (is_even[1] || is_even[2] ? "A, " : "A") : "")
    << (is_even[1] ? (is_even[2] ? "B, " : "B") : "") << (is_even[2] ? "C" : "")
    << (is_even[0] == false && is_even[1] == false && is_even[2] == false ? "отсутствуют" : "")
    << std::endl;

    return 0;
}
