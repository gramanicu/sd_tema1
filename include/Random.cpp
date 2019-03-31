#include "./Random.hpp"

bool CoinFlip::initialized = false;
std::mt19937 CoinFlip::generator;
std::uniform_int_distribution<int> CoinFlip::distribution;