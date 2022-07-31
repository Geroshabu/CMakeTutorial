#include <iostream>
#include <string>
#include <TutorialConfig.hpp>

using namespace std;

int main(int argc, char* argv[]){
	cout << Tutorial_VERSION_MAJOR << "."
	     << Tutorial_VERSION_MINOR << endl;
	cout << "Hello World!" << endl;

	const double inputValue = std::stod(argv[1]);
	cout << inputValue << endl;

	return 0;
}
