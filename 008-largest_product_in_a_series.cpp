// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <obi/util/io.hpp>
#include <obi/util/show.hpp>
#include <obi/util/scoped_timer.hpp>

static inline std::size_t char_to_int(const auto& c) {
    return *c - '0';
}

template<typename T, std::size_t N> inline//enable_if N > 2
T prod_num(T num,std::array<T,N>& array){
    T result = num;
    for(std::size_t i = 0; i < N-1; i++){
        result *= array[i+1];
        array[i] = array[i+1];
    }
    array[N-1] = num;
    return result;
}

std::size_t euler_0008(bool debug = false) {
    obi::util::scoped_timer timer;
    std::ifstream stream("008-number");
    auto number_string = obi::util::ifstream_to_string(stream, true);

    if(debug) {
        timer.add_step("file read");
    }

    std::array<std::size_t,13> numbers{}; //value initialization
    auto backup = numbers;
    std::size_t max = 0;
    auto begin = number_string.begin();
    auto max_pos = begin;

    using obi::util::operator<<;
    for(auto it = begin; it != number_string.end(); ++it) {
        auto num = char_to_int(it);
        auto prod = prod_num(num,numbers);
        if (prod > max) {
            max = prod;
            max_pos = it;
            backup = numbers;
        }
    }

    if(debug) {
        timer.add_step("solution found");

        std::cout << "result: " << backup << " = " << max << " at " << std::distance(number_string.begin(), max_pos)<< std::endl;
        timer.add_step("result printed");
    }

    // https://projecteuler.net/thread=8;page=9
    auto bignum = number_string;
    #define DIGITS 13
    #define CHAR_TO_INT(x) ((x)=='0'?1:(x)-'0')
    long long int maxProd = 1,currProd = 1, dq = 0;
    for(int i=0, j=i-DIGITS; bignum[i]; ++i, ++j) {
        currProd /= CHAR_TO_INT( j>=0 ? bignum[j] : '1' );
        currProd *= CHAR_TO_INT( bignum[i] );
        if ( (dq = (bignum[i]=='0')?DIGITS:(dq-1)) <= 0 &&
             currProd > maxProd)
            maxProd = currProd;
    }
    if(debug) {
        timer.add_step("second solution found - by tlutz0808");
        printf("Max product: %lld\n",maxProd);
    } else {
        timer.disable();
    }

    return max;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0008_largest_product_in_a_series){
    EXPECT_EQ(euler_0008(), 23514624000);
}
#else
int main(int argc, const char *argv[]) {
    euler_0008(true);
    return 0;
}
#endif
