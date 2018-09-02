#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <iterator>

//using num    = std::int64_t;
using num    = int;
using vecit  = std::vector<num>::iterator;
using pair   = std::pair<vecit,vecit>;

template<typename Iter>
void print_range(Iter begin, Iter end){
    std::cout << "[";
    while(begin != end){
        std::cout << *begin << ",";
        std::advance(begin,1);
    }
    std::cout << *end << "]";
}

int main(int argc, const char *argv[]) {
    bool debug = false;
    std::ios::sync_with_stdio(false);

    //input
    std::size_t n;
    std::cin >> n;

    auto vec = std::vector<num>(n);
    for(std::size_t i = 0; i < n; i++ ){
        std::cin >> vec[i];
    }

    //print array
    if(debug){
        for(auto i : vec){
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }

    unsigned range_num = 0;
    std::vector<pair> ranges;
    for(auto start = vec.begin(); start != vec.end(); ++start){
        ++range_num; //single element is a range
        if(debug)
            ranges.emplace_back(start, start);
        num biggest = *start;
        for(auto current = std::next(start); current != vec.end(); ++current){
            if(*current <= *start)
                break;
            if(*current > biggest){
                biggest = *current;
                ++range_num;
                if(debug)
                    ranges.emplace_back(start, current); //for debugging
            }
        }
    }

    if(debug){
        for(auto& p : ranges){
            print_range(p.first,p.second);
        }
        std::cout << "\nresult: " << range_num << std::endl;
    } else {
        std::cout << range_num;
    }
    return 0;
}
