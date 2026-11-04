/*Написать программу, в которой с помощью генератора случайных значений сформировать
4 одномерных массива array1, array2, array3, array4, каждый из которых содержит m
(где m<=7) целочисленных значений.
Значения элементов массивов формируются в диапазоне [k, +3*k], где значение 3 < k < 9
вводится с клавиатуры. Вывести на экран все сформированные массивы, и предусмотреть функцию, с
помощью которой затем вывести среднее арифметическое элементов кратных 9 в каждом массиве.*/

#include <iostream>
#include <cstdlib>
#include <random>

void create_array(const uint8_t& n, const uint8_t& k, int* array) {
    std::random_device rd;
    std::srand(rd());
    const uint8_t min = k;
    const uint8_t max = k*3;
    for (uint8_t i = 0; i < n; i++) {
        array[i] = std::rand()/(1.0*RAND_MAX) * (max-min) + min;
    }
}

int main() {
    unsigned int m, k;
    do {
        std::cout << "Введите m (m ≤ 7)" << std::endl;
        std::cin >> m;
        std::cout << (m > 7 || m < 1) << std::endl;
    } while (m > 7 || m < 1);
    do {
        std::cout << "Введите k (3 < k < 9): ";
        std::cin >> k;
    } while (k <= 3 || k >= 9);

    int arrays[4][m];
    for (unsigned int i = 0; i < 4; i++) {
        create_array(m, k, arrays[i]);
    }

    for (unsigned int i = 0; i < 4; i++) {
        std::cout << "array" << i << " = {";
        for (unsigned int j = 0; j < m; j++) {
            std::cout << arrays[i][j] << (j != m - 1 ? ", " : "");
        }
        std::cout << "}" << std::endl;
    }
}