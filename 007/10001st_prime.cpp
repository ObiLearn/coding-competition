// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <cmath>
#include <obi/math/primes.hpp>

void show_prime(const auto& prime){
    std::cout << "prime " << prime.n << " : " << prime.value << std::endl;
}

int main(int argc, const char *argv[]) {

    auto sieve = obi::math::create_sieve_of_eratosthenes(40000000);
    auto prime = find_nth_prime(1,sieve);
    show_prime(prime);
    for(std::size_t i = 1; i < 20; i++){
        auto next = obi::math::find_next_prime(prime, sieve);
        show_prime(next);
        prime = next;
    }

    show_prime(obi::math::find_nth_prime(10001, sieve));

    return 0;
}
