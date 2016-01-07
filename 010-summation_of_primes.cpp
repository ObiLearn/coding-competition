// Copyright - 2015 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <cmath>
#include <obi/math/primes.hpp>
#include <obi/util/scoped_timer.hpp>

int main(int argc, const char *argv[]) {
    obi::util::scoped_timer timer;
    timer.add_step("main begin");

    std::size_t max = 2 * 1000 * 1000;
    auto sieve = obi::math::create_sieve_of_eratosthenes(max);
    timer.add_step("sieve created");

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
    timer.add_step("sum_calculated");

    std::cout << "result: " << prime_sum << std::endl;
    return 0;
}
