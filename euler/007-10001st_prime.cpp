// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <cmath>
#include <obi/math/primes.hpp>

void show_prime(const auto& prime){
    std::cout << "prime " << prime.n << " : " << prime.value << std::endl;
}

auto euler_007(bool debug = false) {
    auto sieve = obi::math::create_sieve_of_eratosthenes(40000000);
    auto prime = find_nth_prime(1,sieve);
    if(debug){
        for(std::size_t i = 1; i < 20; i++){
            auto next = obi::math::find_next_prime(prime, sieve);
            show_prime(next);
            prime = next;
        }
    }

    auto result = obi::math::find_nth_prime(10001, sieve);
    if(debug){
        show_prime(result);
    }
    return result;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0007_10001st_prime){
    EXPECT_EQ(euler_007().value,104743);
}
#else
int main(int argc, const char *argv[]) {
    euler_007(true);
    return 0;
}
#endif
