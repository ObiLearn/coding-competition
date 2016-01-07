// Copyright - 2016 - Jan Christoph Uhde <Jan@UhdeJC.com>
#include <iostream>
#include <string>
#include <utility>
#include <obi/util/scoped_timer.hpp>
#include <obi/util/show.hpp>
#include <algorithm>

using Num = std::size_t;
using obi::util::operator<<;

template<typename T>
T& next_num(T& num, std::vector<T>& /*vec*/){
    if (num % 2 == 0){
        num /= T(2);
    } else {
        num *= T(3);
        num += T(1);
    }
    return num;
}

template<typename T>
auto collatz(T num, std::vector<T>& vec) {
    auto max_size = vec.size();
    T current = num;
    T len = 1;
    //std::cout << "c in: " << current << std::endl;
    while (current !=  T(1)){
        next_num(current,vec);

        if (current < max_size && vec[current]){
            //std::cout << num << "= " << vec[current] << "+" << len << " : " << vec[current] + len << std::endl;
            vec[num] = (vec[current]) + len;
            //std::cout << vec << std::endl;
            return std::make_pair(num, vec[num]);
        }
        len++;
    };
    vec[num] = len+T(1);
    std::cout << vec << std::endl;
    return std::make_pair(num, vec[num]);
}

int main(/*int argc, const char *argv[]*/) {
    obi::util::scoped_timer timer;

    Num max_num = 1000001;
    //max_num = 14;
    auto collatz_vec = std::vector<Num>(max_num, Num(0));
    collatz_vec[0] = Num(1);
    collatz_vec[1] = Num(1);
    timer.add_step("vars defined");

    for(Num i = 2ul; i < max_num; i++){
        collatz(i, collatz_vec);
    }
    auto result = std::distance(collatz_vec.begin(), std::max_element(collatz_vec.begin(), collatz_vec.end()));

    //for(auto i=0ul; i < max_num; i++){
    //    std::cout << i << "\t: " << collatz_vec[i] << std::endl;
    //}

    timer.add_step("solution found");
    std::cout << "result: " << result << std::endl;
    timer.add_step("result printed");

    return 0;
}
