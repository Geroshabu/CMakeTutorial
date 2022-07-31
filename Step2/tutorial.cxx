#include <iostream>
#include <cmath>

#include <TutorialConfig.hpp>

#ifdef USE_MYMATH
#include <MyMethods.hpp>
#endif

using namespace std;

int main(){
    cout << "Hello World!" << endl;

#ifdef USE_MYMATH
    cout << pow(2, 10) << endl;
#else
    cout << std::pow(2, 10) << endl;
#endif
}
