#include <iostream>
#include <cstdint>
#include <obi/math/basic_functions.hpp>
#include <boost/multiprecision/cpp_int.hpp>

int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;
    namespace om = obi::math;

    bmp::uint1024_t n = 40;
    bmp::uint1024_t k = 20;

    auto fn = om::factorial(n);
    auto fk = om::factorial(k);
    auto fnk = om::factorial(n-k);

    auto result = fn / (fk * fnk);

    std::cout << "fn: " << fn << std::endl;
    std::cout << "fk: " << fk << std::endl;
    std::cout << "result: " << result << std::endl;
    std::cout << "result: " << om::binomial_coefficient(n,k) << std::endl;

    return 0;
}
