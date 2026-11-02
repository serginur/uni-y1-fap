/* Напишите программу, в которой реализуйте три варианта перегрузки функции flip,
   которая возвращает число, полученное записью всех цифр задаваемого натурального
   N в обратном порядке, т.е, если функция принимает в качестве параметра число
   567321, то возвращает число 123765. В первом и втором варианте функция изменяет
   само число, в третьем – формирует возвращаемое значение .*/

#include <iostream>

void flip(int *N) {
    int temp = *N;
    uint8_t len_of_N = 0;
    while (temp != 0) {
        temp /= 10;
        len_of_N++;
    }

    if (len_of_N > 1) {
        temp = 0;
        int k = 1;
        for (int i = 0; i < len_of_N; i++) {
            int div_power_of_10 = 1;
            for (int j = 0; j < len_of_N - k; j++) {
                div_power_of_10 *= 10;
            }
            int multi_power_of_10 = 1;
            for (int j = 0; j < k - 1; j++) {
                multi_power_of_10 *= 10;
            }

            temp += (((*N / div_power_of_10) % 10) * multi_power_of_10);
            k += 1;
        }

        *N = temp;
    }
}

void flip(int &N) {
    int temp = N;
    uint8_t len_of_N = 0;
    while (temp != 0) {
        temp /= 10;
        len_of_N++;
    }

    if (len_of_N > 1) {
        temp = 0;
        int k = 1;
        for (int i = 0; i < len_of_N; i++) {
            int div_power_of_10 = 1;
            for (int j = 0; j < len_of_N - k; j++) {
                div_power_of_10 *= 10;
            }
            int multi_power_of_10 = 1;
            for (int j = 0; j < k - 1; j++) {
                multi_power_of_10 *= 10;
            }

            temp += (((N / div_power_of_10) % 10) * multi_power_of_10);
            k += 1;
        }

        N = temp;
    }
}

int flip(int N) {
    int temp = N;
    uint8_t len_of_N = 0;
    while (temp != 0) {
        temp /= 10;
        len_of_N++;
    }

    if (len_of_N > 1) {
        temp = 0;
        int k = 1;
        for (int i = 0; i < len_of_N; i++) {
            int div_power_of_10 = 1;
            for (int j = 0; j < len_of_N - k; j++) {
                div_power_of_10 *= 10;
            }
            int multi_power_of_10 = 1;
            for (int j = 0; j < k - 1; j++) {
                multi_power_of_10 *= 10;
            }

            temp += (((N / div_power_of_10) % 10) * multi_power_of_10);
            k += 1;
        }

        return temp;
    } else {
        return N;
    }
}

int main() {
    int N;
    std::cout << "Введите натуральное N: ";
    std::cin >> N;
    while (N < 0) {
        std::cout << "N должно быть натуральным! Введите N повторно: ";
        std::cin >> N;
    }
    std::cout << "Введенное N = " << N << std::endl;

    int temp_N = N;
    flip(&temp_N);
    std::cout << "Результат перегрузки void flip(int* N): " << temp_N << std::endl;

    temp_N = N;
    static_cast<void(*)(int &)>(flip)(temp_N);
    std::cout << "Результат перегрузки void flip(int& N): " << temp_N << std::endl;

    temp_N = N;
    temp_N = flip(+temp_N);
    std::cout << "Результат перегрузки int flip(int N): " << temp_N << std::endl;
    return 0;
}
