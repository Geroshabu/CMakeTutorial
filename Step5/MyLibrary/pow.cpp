#include <iostream>
#include <cmath>

int pow(int x, int y){
#if defined(HAVE_POW)
    int ret = (int)std::pow(x, y);
    std::cout << "Using std::pow" << std::endl;
#else
    int ret = 1;
    for (int i = 0; i < y; i++){
        ret *= x;
    }
#endif
    return ret;
}
