// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <fstream>
#include <string>
#include <obi/util/show.hpp>
#include <obi/util/scoped_timer.hpp>

using obi::util::operator<<;

int euler_XXXX(bool debug = false) {

    obi::util::scoped_timer timer;
    if(!debug){
        timer.disable();
    }

    return 1337;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, XXXX_TEMPLATE){
    EXPECT_EQ(euler_XXXX(), 1337);
}
#else
int main(/*int argc, const char *argv[]*/) {
    euler_XXXX(true)
    return 0;
}
#endif
