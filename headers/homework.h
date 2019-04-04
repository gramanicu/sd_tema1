// Copyright Grama Nicolae 2019
#ifndef HEADERS_HOMEWORK_H_
#define HEADERS_HOMEWORK_H_

#include <stdint.h>
#include <fstream>
#include <iostream>
#include <string>
#include "Athlete.h"
#include "Quicksort.h"
#include "SkipList.h"
#include "Time.h"

// Computes the number of points every athlete will get after a race
void computePoints(Times[], SkipList<Athlete>&);

// Read the data from the input files and does all the required operations
void race();

// Updates the positions of the athletes
void updateRanking(SkipList<Athlete>&, Athlete*);

// Prints the ranking
void printRanking(SkipList<Athlete>&, std::ofstream&, bool);

// Function used by the quicksort algorithm, to compare the times
bool compareTimes(const Times&, const Times&);

// Function that compares the points earned by each athlete (if the second
// has less points)
bool comparePoints(const Athlete&, const Athlete&);

#endif  // HEADERS_HOMEWORK_H_
