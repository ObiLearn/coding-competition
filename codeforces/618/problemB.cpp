#include <iostream>
#include <cstdio>
#include <cstdint>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

int main(int argc, const char *argv[]) {
    std::ios::sync_with_stdio(false);

    std::size_t n;
    std::cin >> n;

    std::vector<int> vec(n*n);
    for(std::size_t i = 0; i < n*n; i++){
        std::cin >> vec.data()[i];
    }

    auto pos = std::find(vec.begin(), vec.end(), n-1);
    auto index = std::distance(vec.begin(), pos);
    auto line  = index / n;

    for(std::size_t i = line * n; i < (line+1) * n; ++i){
        if(vec[i] == 0){
            std::cout << n << " ";
        } else {
            std::cout << vec[i] << " ";
        }
    }

    return 0;
}
