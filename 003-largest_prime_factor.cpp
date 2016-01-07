#include <iostream>
#include <obi/math/primes.hpp>
#include <obi/util/show.hpp>
#include <boost/multiprecision/cpp_int.hpp>

auto euler_0003(){
    namespace bmp = boost::multiprecision;
    bmp::uint1024_t n = 600851475143ULL;
    auto result = obi::math::prime_factors_naive(n,true);
    return result;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0003_largest_prime_factor){
    EXPECT_EQ(euler_0003().back(),6857);
}

#else
int main(int argc, const char *argv[]) {

    using namespace obi::util;
    auto result = run_euler();
    std::cout  << "factorization " << result << std::endl
               << "result: " << result.back() << std::endl;

    std::cout << std::endl;
    return 0;
}
#endif
