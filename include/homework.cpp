// Copyright Grama Nicolae 2019
// Note - wherever you find array[1000], I would have used the number of
// as the size, but cpplint.py had some problems with that

#include "homework.hpp"
#include <string>

void race() {
    // There will never be an athlete with the index lower than 0
    SkipList<Athlete> list(Athlete(-1));
    int nrAthl, nrRaces, nrPrints;
    std::ifstream input("races.in");
    std::ofstream output("races.out");

    input >> nrAthl >> nrRaces >> nrPrints;

    for (int i = 0; i < nrAthl; i++) {
        list.Insert(Athlete(i));
    }

    // Reads the data (on the fly, it will process it)
    std::string lastRead;
    while (input >> lastRead) {
        if (lastRead == "print") {
            printRanking(list, output);
        } else {
            // Stores the results of every race
            Times results[1000];
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
    output.close();
}

void computePoints(Times results[], SkipList<Athlete> &list) {
    int attending = 0;
    int nrAthl = list.getCount();

    // Order the times in a ascending order
    Quicksort(results, compareTimes, nrAthl);

    // Where times are equal, change postions depending on the last ranking
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < nrAthl - 1; ++i) {
            if (results[i] == results[i + 1]) {
                // Compares the last positions and switches (if needed)
                int pos1 = list.Search(Athlete(results[i].index))
                               ->value.get_currPosition();
                int pos2 = list.Search(Athlete(results[i + 1].index))
                               ->value.get_currPosition();
                if (pos1 > pos2) {
                    Times aux = results[i];
                    results[i] = results[i + 1];
                    results[i + 1] = aux;
                    changed = true;
                }
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
    int points[1000];
    for (int i = nrAthl - attending; i < nrAthl; i++) {
        int pGiven;
        if (attending % 2 == 0) {
            pGiven = attending / 2 - i + nrAthl - attending;
            if (pGiven <= 0) {
                pGiven--;
            }
        } else {
            pGiven = attending / 2 - i + nrAthl - attending;
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

    Athlete ranking[1000];
    updateRanking(list, ranking);
}

// Updates the positions of the athletes
void updateRanking(SkipList<Athlete> &list, Athlete *ranking) {
    // Copy athletes to an array, so it can be sorted with quicksort
    for (int i = 0; i < list.getCount(); i++) {
        ranking[i] = list.Search(Athlete(i))->value;
    }

    // Sort athletes by their ranking
    Quicksort(ranking, comparePoints, list.getCount());


    for (int i = 0; i < list.getCount(); i++) {
        // Updates the ranking of the athletes
        list.Search(Athlete(ranking[i].get_id()))->value.updatePosition(i+1);
    }
}

void printRanking(SkipList<Athlete> &list, std::ofstream &output) {
    Athlete ranking[1000];
    updateRanking(list, ranking);

    // Print the data
    for (int i = 0; i < list.getCount(); i++) {
        output << ranking[i].get_id() + 1 << " " << ranking[i].get_points()
               << " " << ranking[i].positionDifference() << std::endl;
    }
    output << std::endl;
}

// Function used by the quicksort algorithm, to compare elements (sort
// times)
bool compareTimes(const Times &first, const Times &second) {
    if (first.time > second.time) {
        return true;
    } else {
        return false;
    }
}

// Function used by the quicksort algorithm, to compare elements (sort
// athletes by their points)
bool comparePoints(const Athlete &first, const Athlete &second) {
    if (first.get_points() < second.get_points()) {
        return true;
    } else {
        return false;
    }
}
