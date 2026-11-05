/*Написать программу, в которой с клавиатуры вводится n (где n<=12) строк, каждая
из которых содержит не более 50 символов. Вывести на экран строки, в которых содержится
не более двух цифр из набора 4 5 7*/

#include <iostream>
#include <random>

bool check_for_less_than_two_mathes(const unsigned char* array, const size_t& length) {
    uint16_t amount = 0;
    for (uint16_t i = 0; i < length; i++) {
        if (array[i] == '4' || array[i] == '5' || array[i] == '7') amount++;
        if (amount > 2) break;
    }
    return amount <= 2;
}

void gen_array(unsigned char* array, const size_t& length) {
    std::mt19937 mt(std::random_device{}());

    const uint16_t max_len = mt()%(length-1) + 1;
    for (uint16_t i = 0; i < max_len; i++) array[i] = mt()%40 + 48;
    array[max_len] = '\0';
}

int main() {
    uint16_t n;
    constexpr uint16_t max_ch = 51;
    do {
        std::cout << "Введите количество строк n (n ≤ 12): ";
        std::cin >> n;
    } while (n < 1 || n > 12);

    unsigned char arrays[n][max_ch]; // 51 элемент, 50 для символов, 51-й = \0
    for (uint16_t i = 0; i < n; i++) {
        std::cout << "Введите " << i+1 << "-ю строку (≤50 символов):\n";
        std::cin >> arrays[i];
        for (uint16_t j = 0; j < 51; j++) {
            if (arrays[i][j] == '\0') break;  // если найден \0 - выйти из цикла
            if (j == 50) arrays[i][j] = '\0'; // если не найден - последний элемент = \0
        }
    }

    uint16_t printed = 0;
    for (uint16_t i = 0; i < n; i++) {
        if (check_for_less_than_two_mathes(arrays[i], max_ch)) {
            std::cout << arrays[i] << "\n";
            printed++;
    }
    std::cout << printed << " строк имеют не более двух цифр из набора [4,5,7]" << std::endl;
    return 0;
}