#include <iostream>
#include <obi/math/primes.hpp>
#include <obi/util/show.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(e003_largest_prime_factor, 600851475143ULL){
    namespace bmp = boost::multiprecision;
    bmp::uint1024_t n = 600851475143ULL;
    auto result = obi::math::prime_factors_naive(n,true);
    EXPECT_EQ(result.back(),6857);
}

#else
int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;
    bmp::uint1024_t n = 600851475143ULL;
    //bmp::uint1024_t n = 13ULL;
    auto result = obi::math::prime_factors_naive(n,true);

    using namespace obi::util;
    std::cout  << "factorization " << result << std::endl
               << "result: " << result.back() << std::endl;

    std::cout << std::endl;
    return 0;
}
#endif