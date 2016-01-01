// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/util/io.hpp>
#include <obi/util/scoped_timer.hpp>

std::size_t char_to_int(const auto& c) {
    return *c - '0';
}


int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;

    bmp::uint1024_t sum = 0;
    obi::util::scoped_timer timer;
    auto stream = std::ifstream("number");
    for(auto it = std::istream_iterator<std::string>(stream)
       ;it != std::istream_iterator<std::string>()
       ;++it
       ){
        sum += bmp::uint1024_t(*it);
    }
    timer.add_step("solution found");
    std::cout << "result: " << sum << std::endl;
    timer.add_step("result printed");

    return 0;
}
