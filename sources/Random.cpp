// Copyright Grama Nicolae 2019
#include "../headers/Random.h"

bool CoinFlip::initialized = false;
std::mt19937 CoinFlip::generator;
std::uniform_int_distribution<int32_t> CoinFlip::distribution;

void CoinFlip::seed() {
    distribution = std::uniform_int_distribution<int32_t>(0, 1);
    std::random_device rDevice;
    generator = std::mt19937(rDevice());
    initialized = true;
}

int32_t CoinFlip::flip() {
    if (!initialized) {
        seed();
    }
    int32_t random = distribution(generator);
    if (random==1) {
        return true;
    } else {
        return false;
    }
}
