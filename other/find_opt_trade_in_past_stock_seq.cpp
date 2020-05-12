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


// TODO use std::minmax element instead (C++11) -- returns the last biggest element as done below
std::pair<std::size_t, std::size_t> min_max(std::vector<int> const& in , std::size_t begin, std::size_t end) {
    assert(end <= in.size());

    std::size_t min_pos = begin;
    std::size_t max_pos = begin;

    for(std::size_t i = begin; i < end ; ++i) {
        if(in[i] >= in[max_pos]) { // make sure we take the last in order to advance as far as possible
            max_pos = i;
        }

        if(in[i] < in[min_pos]) { // take the first here. Otherwise we could find
                                  // the same value past the max element.
            min_pos = i;
        }
    }

    return {min_pos, max_pos};
};


//When first and second in the pair are equal we do not buy or sell anything. Otherwise
//we buy at the index of the first and sell at the index of the second value of the pair.
std::pair<std::size_t, std::size_t> find_buy_sell(std::vector<int> const& in, std::size_t begin,
                                                  int best, std::size_t min_pos, std::size_t max_pos) {

    auto [new_min_pos, new_max_pos] = min_max(in, begin, in.size());

    // global solution
    if(new_min_pos < new_max_pos && in[new_max_pos] - in[new_min_pos] > best) {
        return {new_min_pos, new_max_pos};
    }

    // we can not improve
    if(in[new_min_pos] == in[new_max_pos]) {
        return {min_pos, max_pos};
    }

    //find min index in the first part update and continue past the max
    // TODO use std::min_element (C++17)
    auto [local_min_pos, not_required_local_max_pos] = min_max(in, begin, new_max_pos);
    int local_best = in[new_max_pos] - in[local_min_pos];
    if(local_best > best) {
        // update with local_best and continue with the rest of the array
        return find_buy_sell(in, new_max_pos+1, local_best, local_min_pos, new_max_pos);
    } else {
        // keep best and continue with the 2nd part of the array
        return find_buy_sell(in, new_max_pos+1, best, min_pos, max_pos);
    }
}


int main() {
    auto test = std::vector<std::vector<int>>{};
    auto expect = std::vector<std::pair<std::size_t, std::size_t>>{};

    test.push_back(std::vector<int>{6, 3, 40, 23, 1 , 39}); // example at blog
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

    assert(test.size() == expect.size());

    for (std::size_t i = 0; i < test.size(); ++i) {
        auto result = find_buy_sell(test[i], 0 /*begin*/, 0 /*best*/, 0 /*min_pos*/, 0 /*max_pos*/);
        if( result == expect[i]) {
            std::cout << "good\n";
        } else {
            std::cout << "\n\nbad";

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>\n";
            std::cout << "[";
            for(auto i : test[i]) {
                std::cout << i << " ";
            }
            std::cout << "]\n";

            assert(result.first  < test[i].size());
            assert(result.second < test[i].size());

            std::cout << result.first  << "(" << test[i][result.first] << ") "
                      << result.second << "(" << test[i][result.second] << ")" << std::endl << std::endl;

            std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<\n";
        }
    }

    return 0;
};


// keep comments for revisit

/*
std::pair<std::size_t, std::size_t> find_buy_sell(std::vector<int> const& in, std::size_t begin,
                                                  int best, std::size_t min_pos, std::size_t max_pos) {

    std::cout << " start:"   << begin
              << " best:"    << best
              << " min_pos:" << min_pos
              << " max_pos:" << max_pos << std::endl;

    auto [new_min_pos, new_max_pos] = min_max(in, begin, in.size());

    std::cout << "new min " << new_min_pos << " " << in[new_min_pos] << std::endl;
    std::cout << "new max " << new_max_pos << " " << in[new_max_pos] << std::endl;

    // global solution
    if(new_min_pos < new_max_pos && in[new_max_pos] - in[new_min_pos] > best) {
        std::cout << "global solution" << std::endl;
        return {new_min_pos, new_max_pos};
    }

    // we can not improve
    if(in[new_min_pos] == in[new_max_pos]) {
        std::cout << "no improvement possible" << std::endl;
        return {min_pos, max_pos};
    }

    std::cout << "find min index in the first part";
    auto [local_min_pos, local_max_pos] = min_max(in, begin, new_max_pos);

    int local_best = in[new_max_pos] - in[local_min_pos];
    std::cout << "best " << best << std::endl;
    std::cout << "local_best " << local_best << std::endl;

    if(local_best > best) {
        std::cout << "found local best in first part" << std::endl;
        return find_buy_sell(in, new_max_pos+1, local_best, local_min_pos, new_max_pos);
    } else {
        std::cout << "could not improve in frist part" << std::endl;
        return find_buy_sell(in, new_max_pos+1, best, min_pos, max_pos);
    }
}
*/
