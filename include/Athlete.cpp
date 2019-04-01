// Copyright Grama Nicolae 2019
#include "include/Athlete.h"

Athlete::Athlete(const Athlete &other) {
    id = other.id;
    currPosition = other.currPosition;
    lastPosition = other.lastPosition;
    points = other.points;
}

void Athlete::updatePrint() { lastPosition = currPosition; }

void Athlete::updatePosition(int _pos) { currPosition = _pos; }

void Athlete::addPoints(int _points) { points += _points; }

int Athlete::positionDifference() { return lastPosition - currPosition; }
