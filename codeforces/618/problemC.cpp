#include <iostream>
#include <cstdio>
#include <cstdint>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <tuple>

using num = std::int64_t;
using tuple = std::tuple<num,num,num>;

struct point{
    std::size_t id;
    num x;
    num y;
    point() = default;
    point(std::size_t id, num x, num y) : id(id), x(x), y(y) {}
};


bool is_collinear(point const& a, point const& b, point const& c){
    point w(0, a.x - c.x, a.y - c.y);
    point d(0, b.x - c.x, b.y - c.y);
    return ! static_cast<bool>(w.x * d.y - w.y * d.x);
}

int main(int argc, const char *argv[]) {
    std::ios::sync_with_stdio(false);

    std::size_t n;
    std::cin >> n;
    int x, y;
    auto vec = std::vector<point>(n);
    for(unsigned i = 0; i < n; i++ ){
        std::cin >> x >> y;
        vec[i]=point(i+1,x,y);
    }

    std::sort(vec.begin()
             ,vec.end()
             , [](const point& a, const point& b){ return a.x != b.x
                                                        ? a.x < b.x
                                                        : a.y < b.y;
                                                 }
             );

    std::size_t i;
    bool has_result = false;
    for(i = 2; i <vec.size(); i++){
        if( !is_collinear(vec[i-2],vec[i-1],vec[i]) ){
            has_result = true;
            break;
        }
    }


    std::cout //<< std::boolalpha << has_result << " "
              << vec[i-2].id << " "
              << vec[i-1].id << " "
              << vec[i-0].id << " "
              << std::endl;

    return 0;
}
