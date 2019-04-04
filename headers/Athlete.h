// Copyright Grama Nicolae 2019
#ifndef HEADERS_ATHLETE_H_
#define HEADERS_ATHLETE_H_

#include <stdint.h>
#include <iostream>

class Athlete {
 private:
  int32_t id;
  int32_t lastPosition;
  int32_t currPosition;
  int32_t points;

 public:
  // Constructors
  Athlete() : id(0), lastPosition(0), currPosition(0), points(0) {}
  explicit Athlete(int32_t _id)
      : id(_id), lastPosition(0), currPosition(0), points(0) {}
  Athlete(int32_t _id, int32_t _pos)
      : id(_id), lastPosition(_pos), currPosition(_pos), points(0) {}

  // Destructor
  ~Athlete() {}

  // Copy-constructor
  Athlete(const Athlete&);

  // Getters
  int32_t get_id() const { return id; }
  int32_t get_lastPosition() const { return lastPosition; }
  int32_t get_currPosition() const { return currPosition; }
  int32_t get_points() const { return points; }

  // Operator overloads
  friend std::ostream& operator<<(std::ostream& os, const Athlete& ath) {
    os << ath.id << " " << ath.points << " " << ath.currPosition;
    return os;
  }

  // This operators compare the id because it is needed by the SkipList
  bool operator<(const Athlete& other) {
    if (id < other.id) {
      return true;
    }
    return false;
  }

  bool operator>(const Athlete& other) {
    if (id > other.id) {
      return true;
    }
    return false;
  }

  bool operator<=(const Athlete& other) {
    if (id <= other.id) {
      return true;
    }
    return false;
  }

  bool operator>=(const Athlete& other) {
    if (id >= other.id) {
      return true;
    }
    return false;
  }

  bool operator==(const Athlete& other) {
    if (id == other.id) {
      return true;
    }
    return false;
  }

  bool operator!=(const Athlete& other) {
    if (id != other.id) {
      return true;
    }
    return false;
  }

  // Other methods
  void updatePosition(int32_t);  // Updates the athlete position
  void addPoints(int32_t);       // Adds points
  int32_t positionDifference();  // Computes the "progress"
  void updatePrint();            // Updates the rank on last print
};

#endif  // HEADERS_ATHLETE_H_
