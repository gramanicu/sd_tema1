#ifndef HOMEWORK_HPP
#define HOMEWORK_HPP

#include <fstream>
#include <string>
#include "./Athlete.hpp"
#include "./Quicksort.hpp"
#include "./SkipList.hpp"
#include "./Time.hpp"

// Computes the number of points every athlete will get after a race
void computePoints(Times results[], SkipList<Athlete> &list);

// Read the data from the input files and does all the required operations
void race();

// Prints the ranking
void printRanking(SkipList<Athlete> &list);

// Function that compares the points earned by each athlete (if the second
// has less points)
bool comparePoints(const Athlete &first, const Athlete &second);


#endif