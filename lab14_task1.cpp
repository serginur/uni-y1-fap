/*Написать программу, в которой с помощью генератора случайных значений формируются три
матрицы A, B, C вещественных значений размерности m x n (где значения 2<=m<=5 и 2<=m<=6
вводятся с клавиатуры).
Значения элементов матриц должны быть в диапазоне [-k, 2k], где значение 1.5<=k<=4.5 вводится
с клавиатуры.
В программе вывести на экран три сформированные матрицы и имя (имена) матриц(ы) с четным
количеством отрицательных элементов в нечетных столбцах*/

#include <iostream>
#include <random>

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

void print_array(double array[max_m][max_n], const int& m, const int& n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << array[i][j] << " ";
        std::cout << '\n';
    }
    std::cout << std::endl;
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
    } while (m < 2 || m > 5);
    do {
        std::cout << "Введите n (2 ≤ n ≤ 6): ";
        std::cin >> n;
    } while (n < 2 || n > 6);

    double k;
    do {
        std::cout << "Введите k (1.5 ≤ k ≤ 4.5): ";
        std::cin >> k;
    } while (k < 1.5 || k > 4.5);

    double A[max_m][max_n], B[max_m][max_n], C[max_m][max_n];
    gen_array(A, m, n, k);
    gen_array(B, m, n, k);
    gen_array(C, m, n, k);
    print_array(A, m, n);
    print_array(B, m, n);
    print_array(C, m, n);

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
