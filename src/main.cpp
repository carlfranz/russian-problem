#include "Backtrack.h"
#include <iostream>

char lut[90];

void initLut() {
    lut[5] = 'A';
    lut[45] = 'B';
    lut[12] = 'C';
    lut[60] = 'D';
    lut[32] = 'E';
    lut[71] = 'F';
    lut[54] = 'G';
    lut[9] = 'H';
    lut[36] = 'I';
    lut[6] = 'J';
    lut[3] = 'K';
    lut[42] = 'L';
    lut[11] = 'M';
    lut[33] = 'N';
    lut[23] = 'O';
    lut[64] = 'P';
    lut[62] = 'Q';
    lut[57] = 'R';
    lut[18] = 'S';
    lut[85] = 'T';
    lut[19] = 'U';
    lut[48] = 'V';
    lut[84] = 'W';
    lut[21] = 'X';
    lut[63] = 'Y';
    lut[69] = 'Z';
}

int main(int argc, char const *argv[])
{
    std::cout << "main v1.0.0" << std::endl;
    initLut();
    Problem p = {{5, 45, 12, 60, 32, 71, 54, 9, 36, 6, 3, 42, 11, 33, 23, 64, 62, 57, 18, 85, 19, 48, 84, 21, 63, 69}, 8,lut};
    std::vector<std::vector<int>> s;
    std::vector<int> r{};
    enumeration(p, s, 0, r);
    return 0;
}


