// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <obi/util/io.hpp>
#include <obi/util/show.hpp>
#include <obi/util/scoped_timer.hpp>

std::size_t char_to_int(const auto& c) {
    return *c - '0';
}

template<typename T, std::size_t N> //enable_if N > 2
T prod_num(T num,std::array<T,N>& array){
    T result = num;
    for(std::size_t i = 0; i < N-1; i++){
        result *= array[i+1];
        array[i] = array[i+1];
    }
    array[N-1] = num;
    return result;
}

int main(int argc, const char *argv[]) {


    obi::util::scoped_timer timer;
    auto stream = std::ifstream("number");
    //std::string s(std::istreambuf_iterator<char>(stream), {})
    auto number_string = obi::util::stream_to_string(stream, true);
    timer.add_step("file read");

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
            //std::cout << numbers << std::endl;
        }
    }
    timer.add_step("solution found");

    std::cout << "result: " << backup << " = " << max << " at " << std::distance(number_string.begin(), max_pos)<< std::endl;
    timer.add_step("result printed");

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
    timer.add_step("second solution found - by tlutz0808");
    printf("Max product: %lld\n",maxProd);

    return 0;
}
