// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <obi/util/scoped_timer.hpp>

std::size_t euler_0009(bool debug = false) {

    obi::util::scoped_timer timer;
    std::size_t result;

    for(std::size_t a = 0; a <= 1000 ; ++a){
        for(std::size_t b = a+1; a+b <= 1000 ; ++b){
            std::size_t c=1000-(a+b);
            if( a*a + b*b == c*c){
                if (b==c) continue;
                if (debug) {
                    timer.add_step("soulution found");
                    std::cout << "solution found - a: " << a
                              << " b: " << b << " c: " << c
                              << " - result " << a*b*c << std::endl;
                } else {
                    timer.disable();
                }
                result = a*b*c;
                break;
            }
        }
    }
    return result;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0009_special_pythagorean_triplet){
    EXPECT_EQ(euler_0009(), 31875000);
}
#else
int main(int argc, const char *argv[]) {
    euler_0009(true);
    return 0;
}
#endif
