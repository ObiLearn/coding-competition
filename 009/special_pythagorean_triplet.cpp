// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <obi/util/scoped_timer.hpp>

int main(int argc, const char *argv[]) {

    obi::util::scoped_timer timer;

    for(std::size_t a = 0; a <= 1000 ; ++a){
        for(std::size_t b = a+1; a+b <= 1000 ; ++b){
            std::size_t c=1000-(a+b);
            if( a*a + b*b == c*c){

                if (b==c) continue;
                timer.add_step("soulution found");
                std::cout << "solution found - a: " << a
                          << " b: " << b << " c: " << c
                          << " - result " << a*b*c << std::endl;
                break;
            }
        }
    }

    return 0;
}
