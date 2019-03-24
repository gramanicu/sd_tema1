#include <fstream>
#include <string>
#include "./Athlete.hpp"
#include "./LinkedList.hpp"

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
    return 0;
}