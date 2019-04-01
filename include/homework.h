// Copyright Grama Nicolae 2019
#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <iostream>
#include <fstream>
#include <string>
#include "./Athlete.h"
#include "./Quicksort.h"
#include "./SkipList.h"
#include "./Time.h"

// Computes the number of points every athlete will get after a race
void computePoints(Times results[], SkipList<Athlete> &list);

// Read the data from the input files and does all the required operations
void race();

// Updates the positions of the athletes
void updateRanking(SkipList<Athlete> &list, Athlete *ranking);

// Prints the ranking
void printRanking(SkipList<Athlete> &list, std::ofstream &output, bool first);

// Function used by the quicksort algorithm, to compare the times
bool compareTimes(const Times &first, const Times &second);

// Function that compares the points earned by each athlete (if the second
// has less points)
bool comparePoints(const Athlete &first, const Athlete &second);

#endif