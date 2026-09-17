/*  Используя инструкцию switch напишите программу, которая запрашивает у
    пользователя ввести одну из следующих 6 букв латинского алфавита:
    P K T B L R, а затем выводит на английском языке название столицы
    европейского государства, которое начинается с этой буквы или сообщение
    об ошибке, если символ введен не из предложенного набора */

#include "input.h"
#include <locale>

int main() {
    char input = input_symbol("Введите одну из букв: P K T B L R");

    std::string to_print;
    switch (input) {
    case 'P' | 'p':
        to_print = "Warsaw";
        break;
    case 'K' | 'k':
        to_print = "Nicosia";
        break;
    case 'T' | 't':
        to_print = "Ankara";
        break;
    case 'B' | 'b':
        to_print = "Brussels";
        break;
    case 'L' | 'l':
        to_print = "Vaduz";
        break;
    case 'R' | 'r':
        to_print = "Bucharest";
        break;
    default:
        to_print = "Введена буква не из предложенного набора!";
        break;
    }

    std::cout << to_print << std::endl;

    return 0;
}

