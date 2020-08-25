#include "Backtrack.h"
#include <iostream>

std::ostream &operator<<(std::ostream &o, const Solution &s)
{
    for (auto &&c : s.solution)
    {
        o << c;
    }

    o << std::endl;
    return o;
}


bool accept(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    return r.size() == p.size;
}

void processSolution(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    std::cout << "( ";
    for (auto &&i : r)
    {
        std::cout << i << " ";
    }
    std::cout << ")" << std::endl;
}

std::vector<std::vector<int>> choiches(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    std::vector<std::vector<int>> set{};
    for (int val : p.instance)
    {
        std::vector<int> newVal = r;
        newVal.push_back(val);
        set.push_back(newVal);
    }
    return set;
}

void enumeration(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    // if (reject(p,s,i,r)) {
    //     return;
    // }
    if (accept(p, s, i, r))
    {
        processSolution(p, s, i, r);
    }
    else
    {
        auto c = choiches(p, s, i, r);
        for (std::vector<int> e : c)
        {
            s.push_back(e);
            enumeration(p, s, i + 1, e);
        }
    }
}
