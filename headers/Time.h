// Copyright Grama Nicolae 2019
#ifndef HEADERS_TIME_H_
#define HEADERS_TIME_H_

#include <stdint.h>
#include <iostream>

class Times {
 public:
  int32_t index;
  int32_t time;

  // Constructors
  Times() {}
  Times(const int32_t index, const int32_t time) : index(index), time(time) {}

  // Destructor
  ~Times() {}

  // Copy-Constructor
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

#endif  // HEADERS_TIME_H_
