// Copyright Grama Nicolae 2019
#include "include/Random.h"

bool CoinFlip::initialized = false;
std::mt19937 CoinFlip::generator;
std::uniform_int_distribution<int> CoinFlip::distribution;
