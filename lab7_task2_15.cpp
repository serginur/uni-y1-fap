/* Используя вложенные циклы for написать программу для вывода на экран чисел
   следующим образом:
   |1| | | |
   |0| | | |
   |2|2| | |
   |0|0| | |
   |3|3|3| |
   |0|0|0| |
   |4|4|4|4|
   |0|0|0|0|*/

#include <iostream>

int main() {
   std::cout << "_____" << std::endl;
   for (int i = 1; i <= 4; ++i) {
      for (int j = 0; j < 1; ++j) {
         std::cout << "|";
         for (int k = 0; k < 4; ++k) {
            if (k < i) {
               std::cout << i << "|";
            } else {
               std::cout << " |";
            }
         }
         std::cout << std::endl;
      }
   }
   std::cout << "–––––" << std::endl;
}
