#include <iostream>
#include <obi/math/basic_functions.hpp>
#include <boost/multiprecision/cpp_int.hpp>

template <typename T>
void num_out(T x, T base = T(10)) {
    std::cout << std::boolalpha << x << ": " << obi::math::is_palindrome_number(x,base) << std::endl;
}

int main(int argc, const char *argv[]) {
    namespace bmp = boost::multiprecision;
    //bmp::uint1024_t x = 600851475143ULL;
    //bmp::uint1024_t n = 13ULL;
    num_out(1234);
    num_out(123321);
    num_out(1234321);

    num_out(110011);

    unsigned int biggest = 0;

    for(unsigned int i = 999; i >= 100; i--){
        for(unsigned int j = 999; j >= 100; j--){
            unsigned product = i * j;
            if(obi::math::is_palindrome_number(product) && (product > biggest)) {
                biggest = product;
                std::cout << i << " * " << j << " = " << product << std::endl;
            }
        }
    }

    std::cout << std::endl;
    return 0;
}
