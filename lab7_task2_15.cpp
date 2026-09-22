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
#include <string>

int main() {
   std::cout << "_____" << std::endl;
   std::string output;
   for (int i = 1; i <= 4; ++i) {
      for (int j = 0; j <= 1; ++j) {
         output.append("|");
         for (int k = 0; k < 4; ++k) {
            if (k < i) {
               if (j == 0) {
                  output.append(std::to_string(i));
                  output.append("|");
               } else {
                  output.append("0|");
               }
            } else {
               output.append(" |");
            }
         }
         std::cout << output << std::endl;
         output.clear();
      }
   }
   std::cout << "–––––" << std::endl;
}
