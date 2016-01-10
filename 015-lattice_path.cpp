#include <iostream>
#include <cstdint>
#include <obi/math/basic_functions.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace bmp = boost::multiprecision;

bmp::uint1024_t euler_0015(bool debug = false) {
    namespace om = obi::math;

    bmp::uint1024_t n = 40;
    bmp::uint1024_t k = 20;

    auto fn = om::factorial(n);
    auto fk = om::factorial(k);
    auto fnk = om::factorial(n-k);

    auto result = fn / (fk * fnk);

    if (debug) {
        std::cout << "fn: " << fn << std::endl;
        std::cout << "fk: " << fk << std::endl;
        std::cout << "result: " << result << std::endl;
        std::cout << "result: " << om::binomial_coefficient(n,k) << std::endl;
    }

    return result;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0015_large_sum){
    EXPECT_EQ(euler_0015().str(), "137846528820");
}
#else
int main(int argc, const char *argv[]) {
    euler_0015(true)
    return 0;
}
#endif
