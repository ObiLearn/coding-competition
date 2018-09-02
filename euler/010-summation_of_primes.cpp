// Copyright - 2015 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <cmath>
#include <obi/math/primes.hpp>
#include <obi/util/scoped_timer.hpp>

std::size_t euler_0010(bool debug = false) {
    obi::util::scoped_timer timer;

    if (debug) {
        timer.add_step("main begin");
    } else {
        timer.disable();
    }

    std::size_t max = 2 * 1000 * 1000;
    auto sieve = obi::math::create_sieve_of_eratosthenes(max);
    if (debug) {
        timer.add_step("sieve created");
    }

    auto prime = find_nth_prime(1,sieve);
    std::size_t prime_sum = 0;

    while(true) {
        prime_sum += prime.value;
        if (obi::math::find_next_prime(prime, sieve).value == 0) {
            return 1;
        }
        else if (prime.value > sieve.max_value) {
            break;
        }
    }

    if(debug) {
        timer.add_step("sum_calculated");
        std::cout << "result: " << prime_sum << std::endl;
    }

    return prime_sum;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0010_special_pythagorean_triplet){
    EXPECT_EQ(euler_0010(), 142913828922);
}
#else
int main(int argc, const char *argv[]) {
    euler_0010(true);
    return 0;
}
#endif
