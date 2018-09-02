#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using num = long long;
num distance(int& x1,int& y1,int& x2,int& y2){
    num dx = x1 - x2;
    num dy = y1 - y2;
    return dx * dx  + dy * dy;
}

int main(int argc, const char *argv[]) {
    std::ios::sync_with_stdio(false);
    using pair = std::pair<num,num>;

    std::size_t n;
    int x1, y1, x2 ,y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;

    auto distance_vec = std::vector<pair>(n);
    int x, y;

    for(unsigned i = 0; i < n; i++ ){
        std::cin >> x >> y;
        distance_vec.emplace_back(distance(x1,y1,x,y)
                                 ,distance(x2,y2,x,y)
                                 );
    }

    std::sort(distance_vec.begin()
             ,distance_vec.end()
             , [](const pair& x, const pair& y){ return x.first > y.first; }
             );

    num size1 = distance_vec.front().first;
    num size2 = 0;
    num result = size1;
    auto end = distance_vec.end();
    for(auto begin = distance_vec.begin(); begin != end; ++begin){
        if (size2 <= begin->second)
            size2 = begin->second;
        auto next = std::next(begin);
        if ( next != end){
            size1 = std::next(begin)->first;
        } else {
            size1 = 0;
        }
        result = std::min(result, size1 + size2);
    }
    std::cout << result << std::endl;

    return 0;
}
