// Copyright Grama Nicolae 2019

// Note - wherever you find array[MAX_ATHLETES], I would have used
// the number of athletes as the size, but cpplint.py had some
// problems with that

#include "../headers/homework.h"
#include <string>

#define MAX_ATHLETES 1000

// The logic behind the racing algorithm
void race() {
    // There will never be an athlete with the index lower than 0
    SkipList<Athlete> list(Athlete(-1));
    int32_t nrAthl, nrRaces, nrPrints;

    // Open the input file and check if it was succesfull
    std::ifstream input("races.in");
    if (input.fail()) {
        exit(0);
    }

    std::ofstream output("races.out");

    input >> nrAthl >> nrRaces >> nrPrints;

    for (int32_t i = 0; i < nrAthl; ++i) {
        list.Insert(Athlete(i));
    }

    std::string lastRead;
    bool first = true;
    // Reads the data and process it on the fly
    while (input >> lastRead) {
        if (lastRead == "print") {
            printRanking(list, output, first);
            first = false;
        } else {
            // Stores the results of every race
            Times results[MAX_ATHLETES];
            results[0] = Times(0, std::stoi(lastRead));
            for (int32_t i = 1; i < nrAthl; ++i) {
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
    int32_t attending = 0;
    int32_t nrAthl = list.getCount();

    // Order the times in a ascending order
    Quicksort(results, compareTimes, nrAthl);

    // Where times are equal, change postions depending on the last ranking
    bool changed = true;
    while (changed) {
        changed = false;
        for (int32_t i = 0; i < nrAthl - 1; ++i) {
            if (results[i].time == results[i + 1].time) {
                // Compares the last positions and switches (if needed)
                int32_t pos1 = list.Search(Athlete(results[i].index))
                                   ->value.get_currPosition();
                int32_t pos2 = list.Search(Athlete(results[i + 1].index))
                                   ->value.get_currPosition();

                if (pos1 > pos2 && pos2 != 0) {
                    Times aux = results[i];
                    results[i] = results[i + 1];
                    results[i + 1] = aux;
                    changed = true;
                }
            }
        }
    }

    // Find how many actually participated
    for (int32_t i = 0; i < nrAthl; ++i) {
        if (results[i].time != 0) {
            attending++;
        }
    }

    // Compute the number of points to be given to each athlete
    int32_t points[MAX_ATHLETES];
    for (int32_t i = nrAthl - attending; i < nrAthl; ++i) {
        int32_t pGiven;
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
    for (int32_t i = 0; i < nrAthl - attending; ++i) {
        points[results[i].index] = 0;
    }

    // Updates the points
    for (int32_t i = 0; i < nrAthl; ++i) {
        list.Search(Athlete(i))->value.addPoints(points[i]);
    }

    Athlete ranking[MAX_ATHLETES];
    updateRanking(list, ranking);
}

// Updates the positions of the athletes
void updateRanking(SkipList<Athlete> &list, Athlete *ranking) {
    // Copy athletes to an array, so it can be sorted with quicksort
    for (int32_t i = 0; i < list.getCount(); ++i) {
        ranking[i] = list.Search(Athlete(i))->value;
    }

    // Sort athletes by their ranking
    Quicksort(ranking, comparePoints, list.getCount());

    for (int32_t i = 0; i < list.getCount(); ++i) {
        // Updates the ranking of the athletes
        list.Search(Athlete(ranking[i].get_id()))->value.updatePosition(i + 1);
    }
}

// Print ranking - first = true if it is the first print
void printRanking(SkipList<Athlete> &list, std::ofstream &output, bool first) {
    Athlete ranking[MAX_ATHLETES];
    updateRanking(list, ranking);

    // Print the data
    for (int32_t i = 0; i < list.getCount(); ++i) {
        if (first) {
            output << ranking[i].get_id() + 1 << " " << ranking[i].get_points()
                   << " 0" << std::endl;
        } else {
            output << ranking[i].get_id() + 1 << " " << ranking[i].get_points()
                   << " " << ranking[i].positionDifference() << std::endl;
        }
    }
    output << std::endl;

    for (int32_t i = 0; i < list.getCount(); ++i) {
        list.Search(Athlete(i))->value.updatePrint();
    }
}

// Function used by the quicksort algorithm, to compare elements (sort
// times)
bool compareTimes(const Times &first, const Times &second) {
    if (first.time > second.time) {
        return true;
    } else if (first.time == second.time && first.index > second.index) {
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
    } else if (first.get_points() == second.get_points() &&
               first.get_id() > second.get_id()) {
        return true;
    } else {
        return false;
    }
}
