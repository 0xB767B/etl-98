#include "CppUTest/TestHarness.h"

TEST_GROUP(Dummy)
{
  void setup()
  {
  }

  void teardown()
  {
  }
};

TEST(Dummy, FailingTest)
{
  CHECK_EQUAL(0, 0);
}

