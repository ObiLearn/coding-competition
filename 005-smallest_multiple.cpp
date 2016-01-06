#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/math/basic_functions.hpp>
#include <obi/math/primes.hpp>
#include <obi/util/show.hpp>
#include <obi/algorithm.hpp>

auto euler_005(bool in_main = false){
    using obi::util::operator<<;
    namespace bmp = boost::multiprecision;
    std::vector<std::vector<int>> rv;

    std::map<int,int> factor_map;
    for(int i = 1; i <= 20; i++) {
        auto factor_vector = obi::math::prime_factors_naive(i);
        auto occurrence_map = obi::algorithm::count_occurrences(factor_vector);
        obi::algorithm::merge_maps(factor_map, occurrence_map, std::less<>());
    }

    bmp::uint1024_t result = 1;
    for(auto& mpair : factor_map) {
        result = result * bmp::uint1024_t(std::pow(mpair.first,mpair.second));
    }

    if (in_main){
        std::cout << factor_map << std::endl;
        std::cout << "result: " << result << std::endl;
    }

    return result;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(e005r_smallest_multiple, result){
    EXPECT_EQ(euler_005(),232792560);
}
#else
int main(int argc, const char *argv[]) {
    euler_005(true)
    return 0;
}
#endif
