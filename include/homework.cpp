#include "homework.hpp"

void race() {
    // There will never be an athlete with the index lower than 0
    SkipList<Athlete> list(Athlete(-1));
    int nrAthl, nrRaces, nrPrints;
    std::ifstream input("races.in");

    input >> nrAthl >> nrRaces >> nrPrints;

    for (int i = 0; i < nrAthl; i++) {
        list.Insert(Athlete(i));
    }

    // Reads the data (on the fly, it will process it)
    std::string lastRead;
    while (input >> lastRead) {
        if (lastRead == "print") {
            printRanking(list);
        } else {
            // Stores the results of every race
            Times results[nrAthl];
            results[0] = Times(0, std::stoi(lastRead));
            for (int i = 1; i < nrAthl; i++) {
                input >> lastRead;
                results[i] = Times(i, std::stoi(lastRead));
            }

            // Computes the number of points awarded to each athlete
            computePoints(results, list);
        }
    }

    // Closes the input
    input.close();
}

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
}

void printRanking(SkipList<Athlete> &list) {
    Athlete ranking[list.getCount()];
    for (int i = 0; i < list.getCount(); i++) {
        ranking[i] = list.Search(Athlete(i))->value;
    }

    Quicksort(ranking, comparePoints, list.getCount());

    for (int i = 0; i < list.getCount(); i++) {
        std::cout << ranking[i] << "\n";
    }
    std::cout << std::endl;
}

bool comparePoints(const Athlete &first, const Athlete &second) {
    if (first.get_points() > second.get_points()) {
        return true;
    } else {
        return false;
    }
}