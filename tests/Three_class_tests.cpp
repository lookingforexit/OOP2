#include <gtest/gtest.h>
#include "Three.h"

TEST(ThreeClassTest, DefaultConstructor)
{
    Three number;
    EXPECT_EQ(number.toString(), "");
};

TEST(ThreeClassTest, SizeValueConstructor)
{
    Three first_number(5, '1');
    EXPECT_EQ(first_number.toString(), "11111");

    Three second_number(3, '0');
    EXPECT_EQ(second_number.toString(), "0");

    Three third_number(5);
    EXPECT_EQ(third_number.toString(), "0");

    EXPECT_THROW(Three(3, '3'), std::invalid_argument);
};

TEST(ThreeClassTest, InitializerListConstructor)
{
    Three first_number{'1', '1', '1'};
    EXPECT_EQ(first_number.toString(), "111");

    Three second_number{'0', '0', '0'};
    EXPECT_EQ(second_number.toString(), "0");

    EXPECT_THROW(Three{'3'}, std::invalid_argument);
};

TEST(ThreeClassTest, StringConstructor)
{
    Three first_number{"111"};
    EXPECT_EQ(first_number.toString(), "111");

    Three second_number{"000"};
    EXPECT_EQ(second_number.toString(), "0");

    EXPECT_THROW(Three{""}, std::invalid_argument);
    EXPECT_THROW(Three{"333"}, std::invalid_argument);
};

TEST(ThreeClassTest, CopyConstructor)
{
    Three first_number{'1', '1', '1'};
    Three second_number = first_number;
    EXPECT_EQ(second_number.toString(), first_number.toString());
};

TEST(ThreeClassTest, MoveConstructor)
{
    Three first_number{'1', '1', '1'};
    Three second_number(std::move(first_number));
    EXPECT_EQ(first_number.toString(), "");
    EXPECT_EQ(second_number.toString(), "111");
};

TEST(ThreeClassTest, GetSize)
{
    Three first_number{'1', '1', '1'};
    EXPECT_EQ(first_number.getSize(), 3);

    Three second_number{"0"};
    EXPECT_EQ(second_number.getSize(), 1);
};

TEST(ThreeClassTest, AddOperation)
{
    Three first_number{'1', '1', '1'};
    Three second_number{'1', '1', '1'};
    Three res = first_number.add(second_number);
    EXPECT_EQ(res.toString(), "222");

    Three third_number{"222"};
    Three res2 = first_number.add(third_number);
    EXPECT_EQ(res2.toString(), "1110");
};

TEST(ThreeClassTest, SubtractOperation)
{
    Three first_number{'1', '1', '1'};
    Three second_number{'1', '1', '1'};
    Three res = first_number.subtract(second_number);
    EXPECT_EQ(res.toString(), "0");

    Three third_number{"11"};
    Three res2 = first_number.subtract(third_number);
    EXPECT_EQ(res2.toString(), "100");

    Three fourh_number{"222"};
    EXPECT_THROW(first_number.subtract(fourh_number), std::logic_error);
};

TEST(ThreeClassTest, CopyOperation)
{
    Three first_number{'1', '1', '1'};
    Three second_number = first_number.copy();
    EXPECT_EQ(second_number.toString(), first_number.toString());

    Three third_number{"000"};
    Three fourth_number = third_number.copy();
    EXPECT_EQ(third_number.toString(), fourth_number.toString());
};

TEST(ThreeClassTest, ComparisionOperations)
{
    Three first_number{'1', '1', '1'};
    Three second_number{'1', '1', '1'};
    Three third_number{"000"};

    EXPECT_TRUE(first_number.isEqualTo(second_number));
    EXPECT_FALSE(first_number.isEqualTo(third_number));

    EXPECT_TRUE(third_number.isLessThan(first_number));
    EXPECT_FALSE(first_number.isLessThan(second_number));

    EXPECT_TRUE(first_number.isGreaterThan(third_number));
    EXPECT_FALSE(first_number.isGreaterThan(second_number));
};

TEST(ThreeClassTest, RemoveLeadingZeroes)
{
    Three first_number{"000001"};
    EXPECT_EQ(first_number.toString(), "1");

    Three second_number{"00000000000"};
    EXPECT_EQ(second_number.toString(), "0");
};