#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <random>

class CoinFlip {
   private:
    static bool initialized;
    static std::mt19937 generator;
    static std::uniform_int_distribution<int> distribution;

    static void seed() {
        distribution = std::uniform_int_distribution<int>(0, 1);
        std::random_device rDevice;
        generator = std::mt19937(rDevice());
        initialized = true;
    };

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
    };
};

#endif