/* Напишите программу, в которой реализуйте функцию нахождения старшей и младшей цифры
   некоторого натурального числа N: void F(int N, int& First, int& Last). */

#include <iostream>

void F(int N, int &First, int &Last) {
    uint8_t len_of_N = 0;
    int temp = N;
    while (temp > 0) {
        temp /= 10;
        len_of_N++;
    }

    int power_of_10 = 1;
    for (int i = 0; i < len_of_N - 1; i++) {
        power_of_10 *= 10;
    }
    First = N / (power_of_10);
    Last = N % 10;
}

int main() {
    int N;
    std::cout << "Введите натуральное N: ";
    std::cin >> N;
    while (N < 0) {
        std::cout << "N должно быть натуральным! Введите N повторно: ";
        std::cin >> N;
    }
    std::cout << "Введенное число: " << N << std::endl;

    int First, Last;
    F(N, First, Last);
    std::cout << "Старшая цифра: " << First << ", младшая: " << Last << std::endl;
    return 0;
}
