/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){}
		virtual ~tappityTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, sameLength)
{
  std::string reference = "abcd";
	std::string input = "efgh";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(0, myTappity.length_difference());
}

TEST(tappityTest, longerRef)
{
  std::string reference = "abcdefgh";
	std::string input = "abcd";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(4, myTappity.length_difference());
}

TEST(tappityTest, longerInput)
{
  std::string reference = "abcd";
	std::string input = "abcdefgh";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(4, myTappity.length_difference());
}

TEST(tappityTest, emptyStrings)
{
  std::string reference = "";
	std::string input = "";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(0, myTappity.length_difference());
}

TEST(tappityTest, perfectAccuracy)
{
  std::string reference = "abcdefg";
	std::string input = "abcdefg";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(100, myTappity.accuracy());
}

TEST(tappityTest, noAccuracy)
{
  std::string reference = "abcdefg";
	std::string input = "";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(0, myTappity.accuracy());
}

TEST(tappityTest, fiftyAccuracyLongerInput)
{
  std::string reference = "abcd";
	std::string input = "abcdefgh";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(50, myTappity.accuracy());
}

TEST(tappityTest, fiftyAccuracyLongerRef)
{
  std::string reference = "abcdefgh";
	std::string input = "abcd";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(50, myTappity.accuracy());
}

TEST(tappityTest, decimalAccuracy)
{
  std::string reference = "abcdefgh";
	std::string input = "a";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(12.5, myTappity.accuracy());
}

TEST(tappityTest, sameLengthMisspelled)
{
  std::string reference = "I want to ride my bicycle, I want to ride my bike.";
	std::string input = "I vant to ride me bicycle, I want to ride my bike.";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(96, myTappity.accuracy());
}

TEST(tappityTest, missedSpace)
{
  std::string reference = "I like cat";
	std::string input = "Ilikecat";
	tappity myTappity(reference);
	myTappity.entry(input);
	ASSERT_EQ(10, myTappity.accuracy());
}
