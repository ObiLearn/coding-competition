#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <iterator>

using num    = std::int64_t;
using pair   = std::pair<num,num>;
using tuplle = std::tuple<num,num,num>;

int main(int argc, const char *argv[]) {
    std::ios::sync_with_stdio(false);

    //input
    std::size_t n;
    std::cin >> n;

    auto vec = std::vector<pair>(n);
    for(std::size_t i = 0; i < n; i++ ){
        num x, y;
        std::cin >> x >> y;
        //vec.emplace_back(x,y);
    }

    //calc
    std::sort(vec.begin()
             ,vec.end()
             //, [](const pair&  x, const pair& y ){ return x.first > y.first; }
             //, [](const tuple& x, const tuple& y){ return std::get<0>(x) > std::get<0>(y); }
             );

    //print
    auto result = 1337;
    std::cout << result << std::endl;

    return 0;
}
