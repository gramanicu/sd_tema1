// Copyright Grama Nicolae 2019
#ifndef HEADERS_RANDOM_H_
#define HEADERS_RANDOM_H_

#include <random>
#include <stdint.h>

class CoinFlip {
 private:
  // The next 3 variables are used for random generation
  static bool initialized;
  static std::mt19937 generator;
  static std::uniform_int_distribution<int32_t> distribution;

  static void seed() {
    distribution = std::uniform_int_distribution<int32_t>(0, 1);
    std::random_device rDevice;
    generator = std::mt19937(rDevice());
    initialized = true;
  }

  CoinFlip() = delete;

 public:
  static int32_t flip() {
    if (!initialized) {
      seed();
    }
    int32_t random = distribution(generator);
    if (random) {
      return true;
    } else {
      return false;
    }
  }
};

#endif  // HEADERS_RANDOM_H_
