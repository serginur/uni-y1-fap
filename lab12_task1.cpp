/*Написать программу, в которой с помощью генератора случайных значений сформировать
4 одномерных массива array1, array2, array3, array4, каждый из которых содержит m
(где m<=7) целочисленных значений.
Значения элементов массивов формируются в диапазоне [k, +3*k], где значение 3 < k < 9
вводится с клавиатуры. Вывести на экран все сформированные массивы, и предусмотреть функцию, с
помощью которой затем вывести среднее арифметическое элементов кратных 9 в каждом массиве.*/

#include <iostream>
#include <cstdlib>
#include <random>

void create_array(const uint16_t& n, const uint8_t& k, int16_t* array) {
    std::random_device rd;
    std::srand(rd());
    const uint16_t min = k;
    const uint16_t max = k*3;
    for (uint16_t i = 0; i < n; i++) {
        array[i] = static_cast<int16_t>(std::rand()/(1.0*RAND_MAX) * (max-min) + min);
        if (std::rand() % 2 == 0) {
            array[i] *= -1;
        }
    }
}

double print_arithmetic_mean_of_multiples_of_nine(const uint16_t m, const int16_t* array) {
    int64_t sum = 0;
    uint16_t n = 0;
    for (uint16_t i = 0; i < m; i++) {
        if (array[i] % 9 == 0) {
            sum += array[i]; n++;
        }
    }
    if (n == 0) return 0.0;
    return static_cast<double>(sum)/n;
}

int main() {
    uint16_t m, k;
    do {
        std::cout << "Введите m (m ≤ 7): ";
        std::cin >> m;
    } while (m > 7 || m < 1);
    do {
        std::cout << "Введите k (3 < k < 9): ";
        std::cin >> k;
    } while (k <= 3 || k >= 9);

    int16_t arrays[4][m];
    for (uint16_t i = 0; i < 4; i++) {
        create_array(m, k, arrays[i]);
    }

    for (uint16_t i = 0; i < 4; i++) {
        std::cout << "array" << i+1 << " = {";
        for (unsigned int j = 0; j < m; j++) {
            std::cout << arrays[i][j] << (j != m - 1 ? ", " : "");
        }
        std::cout << "}" << std::endl;
    }

    for (uint16_t i = 0; i < 4; i++) {
        const double mean = print_arithmetic_mean_of_multiples_of_nine(m, arrays[i]);
        std::cout << "Среднее арифметическое элементов кратных 9 массива array" << i+1 << ": ";
        if (mean != 0.0) std::cout << mean;
        else std::cout << "элементы кратные 9 отсутствуют";
        std::cout << std::endl;
    }
    return 0;
}