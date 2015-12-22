#include <iostream>
#include <obi/math/basic_functions.hpp>
#include <obi/util/show.hpp>
#include <boost/multiprecision/cpp_int.hpp>

int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;
    bmp::uint1024_t n = 600851475143ULL;
    //bmp::uint1024_t n = 13ULL;
    auto result = obi::math::prime_factors_naive(n,true);

    using namespace obi::util;
    std::cout  << "factorization " << result << std::endl
               << "result: " << result.back() << std::endl;

    std::cout << std::endl;
    return 0;
}
