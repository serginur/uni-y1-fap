/*Написать программу, в которой с помощью генератора случайных значений сформировать
одномерный массив вещественных значений, содержащий n (где n<=10) элементов.
Значения элементов массива формируются в диапазоне [0.5*p, 3.5*p], где значение p>=2
вводится с клавиатуры.
Вывести на экран сформированный массив и вывести среднее арифметическое элементов,
значения которых больше удвоенного минимального*/

#include <iostream>
#include <cstdlib>
#include <random>

void create_array(const uint16_t& n, const double& p, double* array) {
    std::random_device rd;
    std::srand(rd());

    const double min = 0.5*p;
    const double max = 3.5*p;
    for (uint16_t i = 0; i < n; i++) {
        array[i] = std::rand()/(1.0*RAND_MAX) * (max-min) + min;
        if (std::rand() % 2 == 0) array[i] *= -1;
    }
}

double get_specific_arithmetic_mean(const uint16_t& n, const double* array) {
    double min = array[0];
    for (uint16_t i = 1; i < n; i++) if (array[i] < min) min = array[i];
    min *= 2.0;

    double sum = 0.0;
    uint16_t count = 0;
    for (uint16_t i = 0; i < n; i++) if (array[i] > min) {sum += array[i]; count++;}

    if (count == 0) return 0.0;
    return sum/count;
}

int main() {
    uint16_t n;
    double p;
    do {
        std::cout << "Введите n (n ≤ 10): ";
        std::cin >> n;
        if (n > 10 || n < 1) {
            std::cout << "Ошибка!!! Число должно быть меньше равно десяти!\n"; continue;
        }
        break;
    } while (true);
    do {
        std::cout << "Введите p (p ≥ 2): ";
        std::cin >> p;
        if (p < 2) {
            std::cout << "Ошибка!!! Число должно быть больше равно двух!\n"; continue;
        }
        break;
    } while (true);

    double array[n];
    create_array(n, p, array);

    std::cout << "array = {";
    for (uint16_t i = 0; i < n; i++) {
        std::cout << array[i];
        if (i != n-1) std::cout << ", ";
        else std::cout << '}' << std::endl;
    }

    const double mean = get_specific_arithmetic_mean(n, array);
    std::cout << "Среднее арифметическое элементов, значения которых больше удвоенного"
                 " минимального: ";
    if (mean != 0.0) std::cout << mean;
    else std::cout << "такие элементы отсутствуют";
    std::cout << std::endl;
}