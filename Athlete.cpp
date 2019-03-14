#include "./Athlete.h"

Athlete::Athlete(const Athlete &other) {
    id = other.id;
    currPosition = other.currPosition;
    lastPosition = other.lastPosition;
    points = other.points;
}

void Athlete::updatePosition(int _pos) {
    lastPosition = currPosition;
    currPosition = _pos;
}

void Athlete::addPoints(int _points) { points += _points; }

int Athlete::positionDifference() const {
    if (lastPosition) {
        return lastPosition - currPosition;
    } else {
        return currPosition - lastPosition;
    }
}