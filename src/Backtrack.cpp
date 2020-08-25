#include "Backtrack.h"
#include <iostream>
#include <numeric>

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

bool constraintB1(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r) {
    if(i == 6) {
        return !(r.at(5) * r.at(0) == r.at(3)) || r.at(0) > r.at(5);
    }
    return false;
}
bool constraintB2(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r) {
    if(i == 5) {
        return !(r.at(0) + r.at(4) == r.at(3));
    }
    return false;
}

bool constraintC(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    if (i == 3)
    {
        return !(r.at(2) % r.at(1) == 0);
    }
    else
        return false;
}

bool constraintD(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r) {
    if(i == 8) {
        return !(r.at(7) - r.at(5) == r.at(3));
    }
    return false;
}

bool constraintA(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    if (i == 8)
    {
        auto lambda = [&](int a, int b){return (b % 2 == 0) ? a+ b: a; };
        auto a1 = std::accumulate(r.begin(), r.end(), 0, lambda);
        auto a2 = std::accumulate(r.begin(), r.end(), 0);
        return (a2 - (a1 * 2) != 0);
    }
    return false;
}

bool reject(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    return constraintA(p,s,i,r) || 
            constraintC(p,s,i,r)  || constraintB1(p,s,i,r) || constraintB2(p,s,i,r) || constraintD(p,s,i,r);
}


void processSolution(Problem p, std::vector<std::vector<int>> s, int i, std::vector<int> r)
{
    std::cout << "";
    for (auto &&i : r)
    {
        std::cout << p.lut[i] << " ";
    }
    std::cout << "" << std::endl;
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
    if (reject(p, s, i, r))
    {
        return;
    }
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
