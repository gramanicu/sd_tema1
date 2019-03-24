#include <fstream>
#include <string>
#include "./Athlete.hpp"

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
    if (a < b) {
        std::cout << "b " << b.get_points() << " " << a.get_points()
                  << std::endl;
    } else {
        std::cout << "a " << a.get_points() << " " << b.get_points()
                  << std::endl;
    }

    b.addPoints(-3);
    if (a < b) {
        std::cout << "b " << b.get_points() << " " << a.get_points()
                  << std::endl;
    } else if (a > b) {
        std::cout << "a " << a.get_points() << " " << b.get_points()
                  << std::endl;
    } else {
        std::cout << "equal\n";
    }

    b = a;
    std::cout << a << b;
}

int main() {
    std::ifstream input("races.in");
    int nrAthl, nrRaces, nrPrints;

    input >> nrAthl >> nrRaces >> nrPrints;
    std::cout << nrAthl << " " << nrRaces << " " << nrPrints << std::endl;

    std::string lastRead;
    while (input >> lastRead) {
        if (lastRead == "print") {
        } else {
            int timpi[5];
            timpi[0] = std::stoi(lastRead);
            for (int i = 1; i < 5; i++) {
                input >> lastRead;
                timpi[i] = std::stoi(lastRead);
            }
            std::cout << timpi[0] << " " << timpi[1] << " " << timpi[2] << " "
                      << timpi[3] << " " << timpi[4] << "\n";
        }
    }

    // testAthlete();
    input.close();
    return 0;
}