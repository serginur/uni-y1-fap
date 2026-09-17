#include <iostream>
#include <vector>

struct Point {
    double x, y;

    Point(double new_x, double new_y) {
        x = new_x; y = new_y;
    }

    bool operator==(const Point& compared) const {
        return this->x == compared.x && this->y == compared.y;
    }
};

int main() {
    double x, y;


    return 0;
}
