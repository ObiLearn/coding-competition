#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <obi/math/basic_functions.hpp>
#include <obi/math/primes.hpp>
#include <obi/util/show.hpp>
#include <obi/algorithm.hpp>

int main(int argc, const char *argv[]) {
    using obi::util::operator<<;
    namespace bmp = boost::multiprecision;
    std::vector<std::vector<int>> rv;

    std::map<int,int> factor_map;
    for(int i = 1; i <= 20; i++) {
        auto factor_vector = obi::math::prime_factors_naive(i);
        auto occurrence_map = obi::algorithm::count_occurrences(factor_vector);
        obi::algorithm::merge_maps(occurrence_map, factor_map, std::less<>());
    }

    bmp::uint1024_t result = 1;
    for(auto& mpair : factor_map) {
        result = result * bmp::uint1024_t(std::pow(mpair.first,mpair.second));
    }

    std::cout << factor_map << std::endl;
    std::cout << "result: " << result << std::endl;
    return 0;
}
