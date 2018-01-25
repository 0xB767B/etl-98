#include "etl-98/Typelist.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(Typelist)
{
  void setup()
  {
  }

  void teardown()
  {
  }
};

typedef etl98::TypelistOps::MakeTypelist<int>::Result ListOfIntOfLength1;
typedef etl98::TypelistOps::MakeTypelist<int, int>::Result ListOfIntOfLength2;
typedef etl98::TypelistOps::MakeTypelist<int, int, int>::Result ListOfIntOfLength3;
typedef etl98::TypelistOps::MakeTypelist<char, short, int>::Result ListOfIntegers;

TEST(Typelist, LengthIsCorrect)
{
  int length = etl98::TypelistOps::Length<ListOfIntOfLength1>::value;
  CHECK_EQUAL(length, 1);
  length = etl98::TypelistOps::Length<ListOfIntOfLength2>::value;
  CHECK_EQUAL(length, 2);
  length = etl98::TypelistOps::Length<ListOfIntOfLength3>::value;
  CHECK_EQUAL(length, 3);
}

TEST(Typelist, ContainsIsCorrectForAllTypesInList)
{
  bool contains = etl98::TypelistOps::Contains<ListOfIntegers, char>::value;
  CHECK_EQUAL(contains, true);
  contains = etl98::TypelistOps::Contains<ListOfIntegers, short>::value;
  CHECK_EQUAL(contains, true);
  contains = etl98::TypelistOps::Contains<ListOfIntegers, int>::value;
  CHECK_EQUAL(contains, true);
}

TEST(Typelist, ContainsIsCorrectForTypeNotInList)
{
  bool contains = etl98::TypelistOps::Contains<ListOfIntegers, float>::value;
  CHECK_EQUAL(contains, false);
}

TEST(Typelist, ContainsReturnsFalseForNullType)
{
  bool contains = etl98::TypelistOps::Contains<ListOfIntegers, etl98::NullType>::value;
  CHECK_EQUAL(false, contains);
}

