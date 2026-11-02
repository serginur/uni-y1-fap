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

int main() {
    constexpr char delimiter[81] = "================================================================================";
    int a = 3; int b = 5;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Используем первый вариант функции: " << std::endl;
    swap_raw(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << delimiter << std::endl;

    a = 3; b = 5;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Используем второй вариант функции: " << std::endl;
    swap_pointers(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << delimiter << std::endl;

    a = 3; b = 5;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Используем третий вариант функции: " << std::endl;
    swap_reference(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << delimiter << std::endl;
    return 0;
}