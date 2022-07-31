#include <iostream>
#include <string>
#include <MyMethods.hpp>

using namespace std;

int main(int argc, char* argv[]){
    cout << "Hello World!" << endl;

    cout << pow(stoi(argv[1]), stoi(argv[2])) << endl;
}
