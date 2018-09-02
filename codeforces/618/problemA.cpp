#include <iostream>

void doit(unsigned number){
    for(int i=31; i>=0; --i){
        if(number & (1 << i))
			std::cout << (i + 1) << " ";
    }
}

int main(){
    unsigned number = 0;
    std::cin >> number;
    doit(number);
    return 0;
}
