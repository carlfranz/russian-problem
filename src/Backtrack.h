#include <memory>
#include <vector>

#ifndef BACKTRACK_H

#define BACKTRACK_H

struct Solution
{
    // vettore della soluzione
    std::vector<int> solution;

    Solution(std::vector<int> vec) : solution{vec} {}
};


struct Problem
{
    std::vector<int> instance;
    int size;
};

void enumeration(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r);

std::vector<std::vector<int>> choiches(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r);

void processSolution(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r);

bool accept(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r);

std::ostream &operator<<(std::ostream &o, const Solution &s);

#endif