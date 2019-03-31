#include <fstream>
#include <string>
#include "./include/Athlete.hpp"
#include "./include/SkipList.hpp"

typedef struct Times {
    int index;
    int time;
    Times(){};
    Times(const int index, const int time) : index(index), time(time){};
    ~Times(){};
    Times(const Times &other) : index(other.index), time(other.time){};

    bool operator<(const Times &other) { return time < other.time; }
    bool operator>(const Times &other) { return time > other.time; }
    bool operator==(const Times &other) { return time == other.time; }

    friend std::ostream &operator<<(std::ostream &output, const Times &result) {
        output << "index: " << result.index << " time: " << result.time;
        return output;
    }
} Times;


void computePoints(Times results[], SkipList<Athlete> &list) {
    bool ordered = false;
    int attending = 0;
    int nrAthl = list.getCount();

    // Order the times in a ascending order
    while (!ordered) {
        ordered = true;
        for (int i = 0; i < nrAthl - 1; ++i) {
            if (results[i] > results[i + 1]) {
                Times aux = results[i + 1];
                results[i + 1] = results[i];
                results[i] = aux;
                ordered = false;
            }
        }
    }

    // Find how many actually participated
    for (int i = 0; i < nrAthl; ++i) {
        if (results[i].time != 0) {
            attending++;
        }
    }

    // Compute the number of points to be given to each athlete
    int points[nrAthl];
    for (int i = nrAthl - attending; i < nrAthl; i++) {
        int pGiven = (attending / 2) - i + 1;
        if (attending % 2 == 0 && pGiven <= 0) {
            pGiven--;
        }
        points[results[i].index] = pGiven;
    }

    // Gives 0 points to the ones who didn't participate
    for (int i = 0; i < nrAthl - attending; ++i) {
        points[results[i].index] = 0;
    }

    // Updates the points
    for (int i = 0; i < nrAthl; ++i) {
        list.Search(Athlete(i))->value.addPoints(points[i]);
    }
    std::cout << list << "\n";
}

void race() {
    // There will never be an athlete with the index lower than 0
    SkipList<Athlete> list(Athlete(-1));
    
    std::ifstream input("races.in");
    int nrAthl, nrRaces, nrPrints;

    input >> nrAthl >> nrRaces >> nrPrints;
    for (int i = 0; i < nrAthl; i++) {
        list.Insert(Athlete(i));
    }

    std::string lastRead;
    while (input >> lastRead) {
        if (lastRead == "print") {
        } else {
            Times results[nrAthl];
            results[0] = Times(0, std::stoi(lastRead));
            for (int i = 1; i < nrAthl; i++) {
                input >> lastRead;
                results[i] = Times(i, std::stoi(lastRead));
            }

            computePoints(results, list);
        }
    }

    input.close();
}

int main() {
    race();
    return 0;
}