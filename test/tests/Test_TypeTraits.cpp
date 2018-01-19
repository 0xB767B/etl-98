#include "etl-98/TypeTraits.h"

#include "CppUTest/TestHarness.h"

class ClassA
{
};

class ClassB
{
};

TEST_GROUP(TypeTraits)
{
  void setup()
  {
  }

  void teardown()
  {
  }
};

TEST(TypeTraits, IsSame_char_int)
{
  bool result = etl98::IsSame<char, int>::value;
  CHECK_EQUAL(result, false);
}
TEST(TypeTraits, IsSame_char_char)
{
  bool result = etl98::IsSame<char, char>::value;
  CHECK_EQUAL(result, true);
}

TEST(TypeTraits, IsSame_char_class)
{
  bool result = etl98::IsSame<char, ClassA>::value;
  CHECK_EQUAL(result, false);
}

TEST(TypeTraits, IsSame_class_other_class)
{
  bool result = etl98::IsSame<ClassA, ClassB>::value;
  CHECK_EQUAL(result, false);
}

TEST(TypeTraits, IsSame_class_same_class)
{
  bool result = etl98::IsSame<ClassA, ClassA>::value;
  CHECK_EQUAL(result, true);
}

