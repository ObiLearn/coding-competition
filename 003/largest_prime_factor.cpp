#include <iostream>
#include <obi/math/basic_functions.hpp>
#include <boost/multiprecision/cpp_int.hpp>

int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;
    bmp::uint1024_t n = 600851475143ULL;
    //bmp::uint1024_t n = 13ULL;
    auto result = obi::math::prime_factors_naive(n,true);

    std::cout << result.back() << std::endl;

    for(auto& i : result){
        std::cout << i << ", ";
    }

    std::cout << std::endl;
    return 0;
}
