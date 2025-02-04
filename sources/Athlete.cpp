// Copyright Grama Nicolae 2019
#include "../headers/Athlete.h"

Athlete::Athlete(const Athlete &other) {
    id = other.id;
    currPosition = other.currPosition;
    lastPosition = other.lastPosition;
    points = other.points;
}

void Athlete::updatePrint() { lastPosition = currPosition; }

void Athlete::updatePosition(int32_t _pos) { currPosition = _pos; }

void Athlete::addPoints(int32_t _points) { points += _points; }

int32_t Athlete::positionDifference() { return lastPosition - currPosition; }
