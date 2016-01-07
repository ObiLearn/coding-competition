#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/math/basic_functions.hpp>
#include <obi/util/show.hpp>
#include <obi/algorithm.hpp>

// not precise enough
template <typename T>
T sum_of_range(T n){
    return ( n*n + n ) / T(2); //gauss
}

// // this is wrong
// template <typename T, typename F>
// T sum_of_range(F from, T to){
//     return (to+T(from)+1) * ((to-T(from))/T(2)); //gauss
//     //                       range
// }

template <typename T>
T sum_of_squares_of_range(T n){
    return (n*(n+T(1))*(T(2)*n+T(1)))/T(6);
}

int main(int argc, const char *argv[]) {

    double in = 100;
    auto sum = sum_of_range(in);
    auto squared  = sum_of_squares_of_range(in);
    auto result = sum * sum - squared;
    std::cout << "result: " << (int) (sum * sum)
              << " - " << squared << " = "
              << (int) result << std::endl;

    // this works more reliable
    long int sum_ = 0;
    long int squared_ = 0;
    for(int i = 1; i <= 100; i++){
        sum_ += i;
        squared_ += i*i;
    }
    auto result_ = sum_ * sum_ - squared_;
    std::cout << "result: " << sum_ * sum_ << " - " << squared_ << " = " << result_ << std::endl;

    return 0;
}
