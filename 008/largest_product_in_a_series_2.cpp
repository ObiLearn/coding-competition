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

inline std::size_t char_to_int(char c) {
    if (c == '0') { return 1; }
    return c - '0';
}

int main(int argc, const char *argv[]) {

    obi::util::scoped_timer timer;
    auto stream = std::ifstream("number");
    auto number_string = obi::util::stream_to_string(stream, true);
    timer.add_step("file read");

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
    timer.add_step("solution found");

    std::cout << "result: " << max << " at " << std::distance(number_string.begin(), max_pos)<< std::endl;
    timer.add_step("result printed");

    return 0;
}
