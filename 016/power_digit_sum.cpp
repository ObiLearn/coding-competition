// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/util/scoped_timer.hpp>

std::size_t char_to_int(const auto& c) {
    return *c - '0';
}


int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;

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

    timer.add_step("solution found");
    std::cout << "result: " << sum << std::endl;
    timer.add_step("result printed");

    return 0;
}
