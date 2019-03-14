#include <iostream>

#include "./Athlete.h"

void testAthlete() {
    Athlete a = Athlete(3);
    std::cout << a;
    a.updatePosition(5);
    std::cout << a;
    a.addPoints(-2);
    std::cout << a;
    a.updatePosition(2);
    std::cout << a;
    a.addPoints(5);
    std::cout << a;
}

int main() {
    testAthlete();
    return 0;
}