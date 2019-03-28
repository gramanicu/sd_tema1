#include <fstream>
#include <string>
#include "./Athlete.hpp"
#include "./SkipList.hpp"

int main() {
    std::ifstream input("races.in");
    int nrAthl, nrRaces, nrPrints;

    input >> nrAthl >> nrRaces >> nrPrints;

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
        }
    }

    input.close();

    SkipList<int> list(10000);

    for(int i=0; i<10000; i++) {
        list.Insert(i);
    }

    std::cout << list << std::endl;

    return 0;
}