#pragma once
#ifndef RNG
#define RNG

#include <random>
#include <chrono>

namespace RNG {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 mt_generator(seed);

    uint64_t shuffle_table[4];

    uint64_t generate_xoshiro(void) {
        uint64_t s1 = shuffle_table[0];
        uint64_t s0 = shuffle_table[1];
        uint64_t result = s0 + s1;
        shuffle_table[0] = s0;
        s1 ^= s1 << 23;
        shuffle_table[1] = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
        return result;
    }

    unsigned generate_mt19937() {
        return mt_generator();
    }
};

#endif
