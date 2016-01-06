#include <iostream>
#include <obi/math/basic_functions.hpp>

template <typename T>
void num_out(T x, T base = T(10)) {
    std::cout << std::boolalpha << x << ": " << obi::math::is_palindrome_number(x,base) << std::endl;
}

auto euler_004(bool in_main = false){
    unsigned int biggest = 0;

    for(unsigned int i = 999; i >= 100; i--){
        for(unsigned int j = 999; j >= 100; j--){
            unsigned product = i * j;
            if(obi::math::is_palindrome_number(product) && (product > biggest)) {
                biggest = product;
                if(in_main) {
                    std::cout << i << " * " << j << " = " << product << std::endl;
                }
            }
        }
    }
    return biggest;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(e004r_largest_palindrome_product, result){
    EXPECT_EQ(euler_004(),906609);
}
#else
int main(int argc, const char *argv[]) {
    num_out(1234);
    num_out(123321);
    num_out(1234321);
    num_out(110011);

    euler_004(true);

    return 0;
}
#endif
