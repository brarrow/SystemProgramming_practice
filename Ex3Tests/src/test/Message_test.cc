#include <gtest/gtest.h>
#include <sstream>
#include "../Ex3Tests/Message.hh"

TEST(Message, badsize)
{
    EXPECT_FALSE(message(std::cout, "% + % = %", "a", 2));
}

TEST(Message, goodstring)
{
    std::stringstream strStreamActual;

    std::string strExpected = "a + 2 = 3";

    message(strStreamActual, "% + % = %", "a", 2, 3.0);
    std::string strActual = strStreamActual.str();

    EXPECT_EQ(strActual, strExpected);
}