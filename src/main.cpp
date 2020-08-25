#include "Backtrack.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "main v1.0.0" << std::endl;
    Problem p = {{5, 10, 16}, 2};
    std::vector<std::vector<int>> s;
    std::vector<int> r{};
    enumeration(p, s, 0, r);
    return 0;
}
