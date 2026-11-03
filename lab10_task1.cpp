/* Определите, какой из представленных вариантов правильно решает поставленную
   задачу, а какой неправильно и почему? Выберите наиболее приемлемый вариант
   реализации функции swap. */
#include <iostream>

void swap_raw(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap_pointers(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_reference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void print_delimiter() {
    constexpr uint8_t delim = 80;
    std::cout.width(delim);
    std::cout.fill('=');
    std::cout << "" << std::endl;
}

int main() {
    int a = 3; int b = 5;
    std::cout << "a = " << a << ", b = " << b << ". ";
    std::cout << "Используем первую перегрузку функции: " << '\n';
    swap_raw(a, b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    print_delimiter();

    a = 3; b = 5;
    std::cout << "a = " << a << ", b = " << b << ". ";
    std::cout << "Используем вторую перегрузку функции: " << '\n';
    swap_pointers(&a, &b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    print_delimiter();

    a = 3; b = 5;
    std::cout << "a = " << a << ", b = " << b << ". ";
    std::cout << "Используем третью перегрузку функции: " << '\n';
    swap_reference(a, b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    print_delimiter();
    return 0;
}