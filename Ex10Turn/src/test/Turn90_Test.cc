#include <gtest/gtest.h>
#include <vector>
#include "../Ex10Turn/Turn90.hh"

TEST(TURN90, TOOMANYARGS){
    std::vector<int> vec = {1,2,3};
    EXPECT_FALSE(turn90(vec, 90));
}

TEST(TURN90, BADANGLE){
    std::vector<int> vec = {1,2};
    EXPECT_FALSE(turn90(vec, 100));
}

TEST(TURN90, CW_90_DEG){
    std::vector<int> vec = {2,6};
    turn90(vec, 90);
    EXPECT_EQ(6, vec[0]);
    EXPECT_EQ(-2, vec[1]);
}

TEST(TURN90, CCW_90_DEG){
    std::vector<int> vec = {1,3};
    turn90(vec, -90);
    EXPECT_EQ(-3, vec[0]);
    EXPECT_EQ(1, vec[1]);
}