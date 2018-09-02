//#include <cstdio>
//#include <cstring>
//#include <cmath>
///#include <algorithm>
//#include <vector>
//using namespace std;
//
//#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
//#define SZ(c) ((int)(c).size())
//typedef long long LL;
//
//const int N = 1000005;
//int stack[N], top=0;
//int left[N], right[N];
//int a[N], n;
//vector<int> r[N];
//int bit[N];
//
//void add(int x, int v) {
//  while(x<=n) { bit[x] += v; x += (x&-x); }
//}
//int ask(int x) {
//  int ret=0;
//  while(x) { ret += bit[x]; x -= (x&-x); }
//  return ret;
//}
//
//int main(void) {
//  scanf("%d", &n);
//  for(int i=1;i<=n;i++) scanf("%d", &a[i]);
//  for(int i=1;i<=n;i++) {
//    while(top>0 && a[i] > a[stack[top-1]]) --top;
//    left[i] = top? stack[top-1] : 0;
//    stack[top++] = i;
//  }
//  top = 0;
//  for(int i=n;i>=1;i--) {
//    while(top>0 && a[i] < a[stack[top-1]]) --top;
//    right[i] = top? stack[top-1] : n+1;
//    stack[top++] = i;
//  }
//  LL ans = 0;
//  for(int L=n;L>=1;L--) {
//    FOR(it, r[L]) add(*it, -1);
//    add(L, 1);
//    r[left[L]].push_back(L);
//    ans += ask(right[L]-1);
//  }
//  printf("%lld\n", ans);
//  return 0;
//}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <stack>

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

template<typename Cont>
void print_cont(Cont cont){
    print_range(std::begin(cont)
               ,std::end(cont)
               );
    std::cout << std::endl;
}


namespace obi { namespace structures {
    namespace detail {
        //remove least set significant bit
        template <typename T>
        inline T remove_lsb(T& number) {
            number -= (number & -number);
            return number;
        }

        //get index of next node
        template <typename T>
        inline T increase_lsb(T& number) {
            //requires 2 complement
            if(number == T(0)){
                number = T(1);
            }
            number += (number & -number);
            return number;
        }
    }

    template <typename T, typename Iterator, typename Index>
    inline void bit_add(Iterator begin, Iterator end, Index index, T value) {
        if(index == Index(0)){
            *begin = value;
            return;
        }
        auto size = std::distance(begin,end);
        do {
            *(begin+index) += value;
            detail::increase_lsb(index);
        } while(index < Index(size));
        //return value; // is there something we can return
    }

    template <typename T, typename Iterator, typename Index>
    inline T bit_get(Iterator begin, Iterator /*end*/, Index index) {
        auto sum = *begin;
        while(index > 0){
            sum += *(begin+index);
            detail::remove_lsb(index);
        }
        return sum;
    }
}}



int main(int argc, const char *argv[]) {
    bool debug = true;
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
        print_cont(vec);
    }

    std::vector<num> left(vec.size());
    std::vector<num> right(vec.size());
    std::vector<num> stack_data(vec.size());
    std::stack<num, std::vector<num>> stack(stack_data);

    std::size_t top = 0;


    for(int i=1;i<=n;i++) {
      while(!stack.empty() && vec[i] > vec[stack.top()])
          stack.pop();
      left[i] = stack.empty() ? 0 : stack.top();
      stack.push(i);
    }

    print_cont(left);
    print_cont(stack_data);

    while(!stack.empty())
        stack.pop();

	for(int i=n;i>=1;i--) {
		while(!stack.empty() && a[i] < a[stack.top()])
			stack.pop();
			right[i] = stack.empty() ? n+1 : stack.top();
		stack.push(i);
	}

	vector<int> r[N];
	std::vector<num> tree(vec.size());
	long long ans = 0;
	for(int L=n;L>=1;L--) {
		for(auto& it : r[L])
			bit_add(tree.begin()
				   ,
                   tree.end(), it, -1);
		add(L, 1);
		r[left[L]].push_back(L);
		ans += ask(right[L]-1);
	}
	printf("%lld\n", ans);
	return 0;


    //unsigned range_num = 0;
    //std::vector<pair> ranges;
    //for(auto start = vec.begin(); start != vec.end(); ++start){
    //    ++range_num; //single element is a range
    //    if(debug)
    //        ranges.emplace_back(start, start);
    //    num biggest = *start;
    //    for(auto current = std::next(start); current != vec.end(); ++current){
    //        if(*current <= *start)
    //            break;
    //        if(*current > biggest){
    //            biggest = *current;
    //            ++range_num;
    //            if(debug)
    //                ranges.emplace_back(start, current); //for debugging
    //        }
    //    }
    //}

    //if(debug){
    //    for(auto& p : ranges){
    //        print_range(p.first,p.second);
    //    }
    //    std::cout << "\nresult: " << range_num << std::endl;
    //} else {
    //    std::cout << range_num;
    //}
    //return 0;
}
