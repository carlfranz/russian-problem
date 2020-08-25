#include "gtest/gtest.h"
#include "Backtrack.h"

TEST(choiches, testGeneration) {

    Problem p {{1,2},1};
    auto c = choiches(p,{},0,{});
    
    EXPECT_EQ (c.size(),2);
    auto first = c.at(0);
    EXPECT_EQ(first.size(),1);
    EXPECT_EQ(first.at(0),1);
    auto second = c.at(1);
    EXPECT_EQ(second.size(),1);
    EXPECT_EQ(second.at(0),2);
}