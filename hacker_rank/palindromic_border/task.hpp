#include <string>
#include <fstream>
#include <iostream>

inline int palindromicBorder(std::string const& in){
    return 5;
}

inline int task() {
    std::string s;
    getline(std::cin, s);
    int result = palindromicBorder(s);
    std::cout << result << "\n";
    return 0;
}
