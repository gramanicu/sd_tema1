// Copyright Grama Nicolae 2019
#ifndef HEADERS_RANDOM_H_
#define HEADERS_RANDOM_H_

#include <stdint.h>
#include <random>

class CoinFlip {
 private:
  // The next 3 variables are used for random generation
  static bool initialized;
  static std::mt19937 generator;
  static std::uniform_int_distribution<int32_t> distribution;

  static void seed() ;
  CoinFlip() = delete;

 public:
  static int32_t flip();
};

#endif  // HEADERS_RANDOM_H_
