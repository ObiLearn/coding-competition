#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/math/basic_functions.hpp>
#include <obi/util/show.hpp>
#include <obi/algorithm.hpp>

template <typename T>
T sum_of_range(T n){
    return ( n*n + n ) / T(2); // Gauss
}

template <typename T>
T sum_of_squares_of_range(T n){
    return (n*(n+T(1))*(T(2)*n+T(1)))/T(6);
}

auto euler_0006(bool in_main = false) {

    double in = 100;
    auto sum = sum_of_range(in);
    auto squared  = sum_of_squares_of_range(in);
    auto result = sum * sum - squared;
    if (in_main) {
        std::cout << "result: " << (int) (sum * sum)
                  << " - " << squared << " = "
                  << (int) result << std::endl;
    }

    //  // this works more reliable
    //  long int sum_ = 0;
    //  long int squared_ = 0;
    //  for(int i = 1; i <= 100; i++){
    //      sum_ += i;
    //      squared_ += i*i;
    //  }
    //  auto result_ = sum_ * sum_ - squared_;
    //  if (in_main) {
    //      std::cout << "result: " << sum_ * sum_
    //                << " - " << squared_ << " = "
    //                << result_ << std::endl;
    //  }

    return result;
}

#ifndef OBI_RUN_MAIN
#include <gtest/gtest.h>
TEST(solution, 0006_sum_square_difference){
    EXPECT_EQ(euler_0006(),25164150);
}
#else
int main(int argc, const char *argv[]) {
    euler_0006(true);
    return 0;
}
#endif
