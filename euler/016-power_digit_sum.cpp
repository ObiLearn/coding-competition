// Copyright - 20016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/util/scoped_timer.hpp>

namespace bmp = boost::multiprecision;

bmp::uint1024_t euler_0016(bool debug = false) {

    obi::util::scoped_timer timer;
    bmp::uint1024_t num = bmp::pow(bmp::uint1024_t(2),1000);
    bmp::uint1024_t sum = 0;
    bmp::uint1024_t rest = 0;
    while ( num >= bmp::uint1024_t(10) ){
        rest = num % bmp::uint1024_t(10);
        num /= bmp::uint1024_t(10);
        sum += rest;
    }
    sum += num;

    if (debug) {
        timer.add_step("solution found");
        std::cout << "result: " << sum << std::endl;
        timer.add_step("result printed");
    } else {
        timer.disable();
    }

    return sum;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0016_large_sum){
    EXPECT_EQ(euler_0016().str(), "1366");
}
#else
int main(int argc, const char *argv[]) {
    euler_0016(true);
    return 0;
}
#endif
