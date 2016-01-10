// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/util/io.hpp>
#include <obi/util/scoped_timer.hpp>

static std::size_t char_to_int(const auto& c) {
    return *c - '0';
}

namespace bmp = boost::multiprecision;
bmp::uint1024_t euler_0013(bool debug = false) {

    bmp::uint1024_t sum = 0;
    obi::util::scoped_timer timer;
    auto stream = std::ifstream("013-number");
    if(! stream.is_open()){
        throw std::logic_error("stream not open");
    }

    for(auto it = std::istream_iterator<std::string>(stream)
       ;it != std::istream_iterator<std::string>()
       ;++it
       ){
        sum += bmp::uint1024_t(*it);
    }
    if(debug) {
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
TEST(solution, 0013_large_sum){
    EXPECT_EQ(euler_0013().str(), "5537376230390876637302048746832985971773659831892672");
}
#else
int main(int argc, const char *argv[]) {
    euler_0013(true)
    return 0;
}
#endif
