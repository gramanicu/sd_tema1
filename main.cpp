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

    Athlete b = Athlete(2);
    b.addPoints(6);
    if(a<b) {
        std::cout << "b " << b.get_points() << " " << a.get_points() << std::endl;
    } else {
        std::cout << "a " << a.get_points() << " " << b.get_points() << std::endl;
    }

    b.addPoints(-3);
    if(a<b) {
        std::cout << "b " << b.get_points() << " " << a.get_points() << std::endl;
    } else if(a>b) {
        std::cout << "a " << a.get_points() << " " << b.get_points() << std::endl;
    } else {
        std::cout << "equal\n";
    }

    b = a;
    std::cout << a << b;
}

int main() {
    testAthlete();
    return 0;
}