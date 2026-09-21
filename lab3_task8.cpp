/* Текущее показание электронных часов: h часов     (0 ≤ h ≤ 23)
                                        m минут     (0 ≤ m ≤ 59)
                                        s секунд    (0 ≤ k ≤ 59).

Какое время будут показывать часы через р часов q минут r секунд? */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

template<typename T>
void clear_input(std::vector<T>& vec, std::istringstream& iss) {
    vec.clear();
    iss.clear();
    iss.str("");
}

struct Time {
    uint8_t hours, minutes, seconds;

    Time(uint8_t new_h, uint8_t new_m, uint8_t new_s): 
        hours(new_h), minutes(new_m), seconds(new_s) {};

    std::string get_time() const {
        std::string h_str = std::to_string(hours);
        std::string m_str = std::to_string(minutes);
        std::string s_str = std::to_string(seconds);
        for (std::string* str : {&h_str, &m_str, &s_str}) {
            if (str->size() == 1) {
                str->insert(0, "0");
            }
        }
        return std::string(h_str + ":" + m_str + ":" + s_str);
    }

    Time operator+(const Time& other) const {
        uint8_t s = this->seconds + other.seconds;
        uint8_t m = this->minutes + other.minutes;
        uint8_t h = this->hours + other.hours;
        if (s > 59) {
            s -= 60;
            m++;
        }
        if (m > 59) {
            m -= 60;
            h++;
        }
        if (h > 23) {
            h -= 24;
        }
        return {h, m, s};
    }
};

Time input_time() {
    std::vector<std::string> tokens;
    
    bool input_check = false;
    while (not input_check) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.size() != 3) {
            std::cout << "Введено неверное количество показаний!\n";
            clear_input(tokens, iss);
            continue;
        }

        for (const std::string& t : tokens) {
            for (const char& c : t) {
                if (not std::isdigit(c)) {
                    std::cout << "Введены неверные показания!\n";
                    clear_input(tokens, iss);
                    continue;
                }
            }
        }

        bool is_correct = true;
        for (uint8_t i = 0; i < 3; i++) {
            auto temp = static_cast<uint8_t>(std::stoi(tokens.at(i)));
            if (((i == 0) && temp > 23) || ((i > 0) && temp > 59)) {
                is_correct = false;
                break;
            }
        }
        if (not is_correct) {
            std::cout << "Введены неверные показания!\n";
            clear_input(tokens, iss);
            continue;
        }

        input_check = true;
    }
    return {static_cast<uint8_t>(stoi(tokens.at(0))),
             static_cast<uint8_t>(stoi(tokens.at(1))),
              static_cast<uint8_t>(stoi(tokens.at(2)))};
}

int main () {
    std::cout << "Введите показания электронных часов (h m s):\n";

    Time clock = input_time();

    std::cout << "Часы установлены на " << clock.get_time() << '\n';
    std::cout << "Введите прошедшее время (h m s):\n";

    Time time_passed = input_time();

    clock = clock + time_passed;

    std::cout << "Часы через " << time_passed.get_time() <<
                 " будут показывать " << clock.get_time() << '\n';

    return 0;
}
