// Copyright Grama Nicolae 2019
#ifndef INCLUDE_TIME_H_
#define INCLUDE_TIME_H_

#include <iostream>

class Times {
 public:
  int index;
  int time;
  Times() {}
  Times(const int index, const int time) : index(index), time(time) {}
  ~Times() {}
  Times(const Times &other) : index(other.index), time(other.time) {}

  bool operator<(const Times &other) {
    if (time < other.time) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const Times &other) {
    if (time > other.time) {
      return true;
    } else {
      return false;
    }
  }
  bool operator==(const Times &other) {
    if (time == other.time) {
      return true;
    } else {
      return false;
    }
  }

  friend std::ostream &operator<<(std::ostream &output, const Times &result) {
    output << "index: " << result.index << " time: " << result.time;
    return output;
  }
};

#endif  // INCLUDE_TIME_H_
