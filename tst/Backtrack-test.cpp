#include "Backtrack.h"
#include "gtest/gtest.h"

TEST(choiches, testGeneration)
{

    Problem p{{1, 2}, 1};
    auto c = choiches(p, {}, 0, {});

    EXPECT_EQ(c.size(), 2);
    auto first = c.at(0);
    EXPECT_EQ(first.size(), 1);
    EXPECT_EQ(first.at(0), 1);
    auto second = c.at(1);
    EXPECT_EQ(second.size(), 1);
    EXPECT_EQ(second.at(0), 2);
}

TEST(ConstraintC, Positive)
{
    Problem p{{}, 8};
    auto result = constraintC(p, {}, 3, {1, 5, 10});
    EXPECT_EQ(result, false);
}

TEST(ConstraintC, Negative)
{
    Problem p{{}, 8};
    auto result = constraintC(p, {}, 3, {1, 5, 11});
    EXPECT_EQ(result, true);
}

TEST(ConstraintA, Positive)
{
    Problem p{{}, 8};
    auto result = constraintA(p, {}, 8, {1, 1, 1, 1, 1, 3, 2, 6});
    EXPECT_EQ(result, false);
}

TEST(ConstraintA, Negative)
{
    Problem p{{}, 8};
    auto result = constraintA(p, {}, 8, {1, 1, 1, 1, 1, 3, 2, 7});
    EXPECT_EQ(result, true);
}

TEST(ConstraintB, Negative)
{
    Problem p{{}, 8};
    auto result = constraintA(p, {}, 8, {1, 1, 1, 1, 1, 3, 2, 7});
    EXPECT_EQ(result, true);
}

TEST(ConstraintB, Positive)
{
    Problem p{{}, 8};
    auto result = constraintA(p, {}, 8, {1, 1, 1, 1, 1, 3, 2, 7});
    EXPECT_EQ(result, true);
}