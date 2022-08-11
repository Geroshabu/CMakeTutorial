#include <iostream>
#include "MyMethod.hpp"
#include "print2.hpp"

namespace mymodule {
    void print() {
        std::cout << "This is print method." << std::endl;
        detail::print2();
    }
}
