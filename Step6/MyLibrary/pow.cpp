#include <File.hpp>
#include <iostream>

int pow(int x, int y){
    if (x >= 0 && x < 10 && y == 2){
        std::cout << "Use the table to help find an answer." << std::endl;
        return table[x];
    }

    int ret = 1;
    for (int i = 0; i < y; i++){
        ret *= x;
    }
    return ret;
}
