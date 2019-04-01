// Copyright Grama Nicolae 2019
#ifndef INCLUDE_RANDOM_H_
#define INCLUDE_RANDOM_H_

#include <random>

class CoinFlip {
 private:
  // The next 3 are used for random generation
  static bool initialized;
  static std::mt19937 generator;
  static std::uniform_int_distribution<int> distribution;

  static void seed() {
      distribution = std::uniform_int_distribution<int>(0, 1);
      std::random_device rDevice;
      generator = std::mt19937(rDevice());
      initialized = true;
  }

  CoinFlip() = delete;

 public:
  static int flip() {
      if (!initialized) {
          seed();
      }
      int random = distribution(generator);
      if (random) {
          return true;
      } else {
          return false;
      }
  }
};

#endif  // INCLUDE_RANDOM_H_
