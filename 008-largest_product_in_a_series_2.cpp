// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>

// based on tlutz0808 solution
// https://projecteuler.net/thread=8;page=9

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <obi/util/io.hpp>
#include <obi/util/show.hpp>
#include <obi/util/scoped_timer.hpp>

static std::size_t char_to_int(char c) {
    if (c == '0') { return 1; }
    return c - '0';
}

std::size_t euler_008_faster(bool debug = false) {

    obi::util::scoped_timer timer;
    auto stream = std::ifstream("008-number");
    auto number_string = obi::util::ifstream_to_string(stream, true);
    if(debug){
        timer.add_step("file read");
    }

    std::size_t num_of_items = 13;
    std::size_t current = 1;
    std::size_t disqualified = num_of_items;
    auto begin = number_string.begin();
    std::size_t max = 0;
    auto max_pos = begin;

    using obi::util::operator<<;
    for(auto seq_end = begin, seq_begin = begin - num_of_items
       ; seq_end != number_string.end()
       ; ++seq_end, ++seq_begin
       ) {
        if( seq_begin >= begin ){
            current /= char_to_int(*seq_begin);
        }
        current *= char_to_int(*seq_end);

        if (*seq_end == '0') {
            disqualified = num_of_items;
        } else if (disqualified > 0) {
            disqualified--;
        }

        if (! disqualified && current > max) {
            max = current;
            max_pos = seq_end;
        }
    }
    if(debug){
        timer.add_step("solution found");

        std::cout << "result: " << max << " at " << std::distance(number_string.begin(), max_pos)<< std::endl;
        timer.add_step("result printed");
    } else {
        timer.disable();
    }

    return max;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0008_largest_product_in_a_series_faster){
    EXPECT_EQ(euler_008_faster(), 23514624000);
}
#else
int main(int argc, const char *argv[]) {
    euler_008_faster(true)
    return 0;
}
#endif
