/*  Используя инструкцию switch напишите программу, которая запрашивает у
    пользователя ввести один из следующих 8 символов: * < ! > % ? = +, а
    затем выводит название этого символа или сообщение об ошибке, если
    символ введен не из предложенного набора. */

#include "input.h"

int main() {
    char input = input_symbol("Введите один из символов: * < ! > % ? = +");

    std::string to_print;
    switch (input) {
    case '*':
        to_print = "Астериск";
        break;
    case '<':
        to_print = "Открывающая кавычка";
        break;
    case '!':
        to_print = "Восклицательный знак";
        break;
    case '>':
        to_print = "Закрывающая кавычка";
        break;
    case '%':
        to_print = "Знак процента";
        break;
    case '?':
        to_print = "Вопросительный знак";
        break;
    case '=':
        to_print = "Знак равенства";
        break;
    case '+':
        to_print = "Знак плюса";
        break;
    default:
        to_print = "Введен символ не из предложенного набора!";
        break;
    }

    std::cout << to_print << std::endl;

    return 0;
}
