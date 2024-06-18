#include "lab3.h"
#include "gtest/gtest.h"
#include <cmath>
#include <string>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(exercise0, Returns4) { EXPECT_EQ(exercise0(), 4); }

TEST(exercise1, Zeroes) {
  double distance = exercise1(0.0, 0.0, 0.0, 0.0);
  EXPECT_EQ(distance, 0.0);
  double expected = 0.0;
  double diff = fabs(distance - expected);
  EXPECT_LE(diff, 0.0001);
}

TEST(exercise1, Unit) {
  double distance = exercise1(0.0, 0.0, 1.0, 1.0);
  double expected = 1.414214;
  double diff = fabs(distance - expected);
  EXPECT_LE(diff, 0.0001);
}

TEST(exercise1, Negative) {
  double distance = exercise1(-1.0, -1.0, 1.0, 1.0);
  double expected = 2.828427;
  double diff = fabs(distance - expected);
  EXPECT_LE(diff, 0.0001);
}

TEST(exercise2, Test) {
  unsigned int count = exercise2("test");
  unsigned int expected = 1;
  EXPECT_EQ(count, expected);
}

TEST(exercise2, All) {
  unsigned int count = exercise2("aeiou");
  unsigned int expected = 5;
  EXPECT_EQ(count, expected);
}

TEST(exercise3, Five) {
  unsigned int count = exercise3(5);
  unsigned int expected = 15;
  EXPECT_EQ(count, expected);
}

TEST(exercise3, Negative) {
  unsigned int count = exercise3(-15);
  unsigned int expected = 0;
  EXPECT_EQ(count, expected);
}

TEST(exercise4, Empty) {
  std::string reversed = exercise4("");
  std::string expected = "";
  EXPECT_EQ(reversed, expected);
}

TEST(exercise4, Abba) {
  std::string reversed = exercise4("abba");
  std::string expected = "abba";
  EXPECT_EQ(reversed, expected);
}

TEST(exercise4, Foobar) {
  std::string reversed = exercise4("foobar");
  std::string expected = "raboof";
  EXPECT_EQ(reversed, expected);
}

TEST(exercise5, Foobar) {
  bool actual = exercise5("foobar");
  bool expected = false;
  EXPECT_EQ(actual, expected);
}

TEST(exercise5, Abb) {
  bool actual = exercise5("abba");
  bool expected = true;
  EXPECT_EQ(actual, expected);
}

TEST(exercise6, FF) {
  bool actual = exercise6(false, false);
  bool expected = false;
  EXPECT_EQ(actual, expected);
}

TEST(exercise6, FT) {
  bool actual = exercise6(false, true);
  bool expected = true;
  EXPECT_EQ(actual, expected);
}
TEST(exercise6, TF) {
  bool actual = exercise6(true, false);
  bool expected = true;
  EXPECT_EQ(actual, expected);
}
TEST(exercise6, TT) {
  bool actual = exercise6(true, true);
  bool expected = false;
  EXPECT_EQ(actual, expected);
}

TEST(exercise7, L33t) {
  std::string actual = exercise7("leet");
  std::string expected = "l33t";
  EXPECT_EQ(actual, expected);
}

TEST(exercise8, L33t) {
  std::string actual = exercise8("leet");
  std::string expected = "yrrg";
  EXPECT_EQ(actual, expected);
}

TEST(exercise9, L33t) {
  int actual = exercise9(3, 4, 5);
  int expected = 5;
  EXPECT_EQ(actual, expected);
}
