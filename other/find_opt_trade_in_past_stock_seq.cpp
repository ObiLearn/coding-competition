// Task
//
// You are given a vector of past stock prices (one per day).
// You must find out when an investor could have made the
// biggest profit.
//
// Return a pair where the first element holds the index of the
// day where he should have bought and the second the day he should
// have sold. If first and second are equal no action is taken.
// You are not allowed to take your pants off (short selling forbidden)!


// TODO find link at competition page and compare algorithm


#include <utility>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>


//When first and second in the pair are equal we do not buy or sell anything.
//Otherwise we buy at first and sell second.
template<typename Container, typename Iter=typename Container::const_iterator >
std::pair<Iter,Iter> find_buy_sell( Container const& in, Iter begin, int best, Iter min, Iter max)  {

    auto [new_min, new_max] = std::minmax_element(begin, in.end()); // Note: max is the last max element!
                                                                    // This can result in larger ranges

    // global solution for inspected part
    if(new_min < new_max && (*new_max - *new_min) > best) {
        return {new_min, new_max};
    }

    // we can not improve.
    if(*new_min == *new_max) {
        return {min, max};
    }

    // Find minimum in the first part.
    auto local_min = std::min_element(begin, new_max);
    int local_best = *new_max - *local_min;


    if(local_best > best) {
        // update with local_best and continue with the rest of the array.
        return find_buy_sell(in, std::next(new_max), local_best, local_min, new_max);
    } else {
        // we can not improve - keep values as they are and continue with the rest of the array.
        return find_buy_sell(in, std::next(new_max), best, min, max);
    }
}


int main() {
    auto test = std::vector<std::vector<int>>{};
    auto expect = std::vector<std::pair<std::size_t, std::size_t>>{};

    test.push_back(std::vector<int>{6, 3, 40, 23, 1 , 39}); // example from blog
    expect.push_back({4,5});

    test.push_back(std::vector<int>{32}); // one element
    expect.push_back({0,0});

    test.push_back(std::vector<int>{3, 3}); // 2 equal
    expect.push_back({0,0});

    test.push_back(std::vector<int>{3, 4}); // 2 in good order
    expect.push_back({0,1});

    test.push_back(std::vector<int>{7, 3}); // 2 in bad order
    expect.push_back({0,0});

    test.push_back(std::vector<int>{9, 8, 7, 6, 5, 3, 2 ,1}); // nothing to do
    expect.push_back({0,0});

    test.push_back(std::vector<int>{9, 8, 7, 10}); // last element is the biggest
    expect.push_back({2,3});

    test.push_back(std::vector<int>{10, 3, 9, 1}); // smallest at the end
    expect.push_back({1,2});

    test.push_back(std::vector<int>{90, 8, 7, 10, 3, 9, 1}); // biggest in the front
    expect.push_back({4,5});

    test.push_back(std::vector<int>{79, 80, 68, 70, 55, 60}); // more than one recursion
    expect.push_back({4,5});

    test.push_back(std::vector<int>{9, 8, 7, 10, 3, 3, 3, 3, 3, 9, 1}); // some equal
    expect.push_back({4,9});

    test.push_back(std::vector<int>{3, 6, 6, 1, 3, 1, 5});
    expect.push_back({3,6});

    test.push_back(std::vector<int>{6, 8, 6, 8, 6, 8, 2, 5});
    expect.push_back({6,7});

    assert(test.size() == expect.size());

    for (std::size_t i = 0; i < test.size(); ++i) {
        auto const& in = test[i];

        auto result = find_buy_sell(in, in.begin() /*begin*/, 0 /*best*/, in.begin(), in.begin());
        auto transformed_result = std::pair<std::size_t, std::size_t>{ std::distance(in.begin(), result.first), std::distance(in.begin(),result.second)};
        if( transformed_result == expect[i]) {
            std::cout << "good\n";
        } else {
            std::cout << "\n\nbad";

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>\n";
            std::cout << "[";
            for(auto i : in) {
                std::cout << i << " ";
            }
            std::cout << "]\n";

            std::cout << transformed_result.first  << "(" << *result.first << ") "
                      << transformed_result.second << "(" << *result.second << ")" << std::endl << std::endl;

            std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<\n";
        }
    }

    return 0;
};
