#include "catch.hpp"
#include "etl-98/TypeTraits.h"

class ClassA
{
};

class ClassB
{
};

TEST_CASE("TypeTraits IsSame gives correct results", "[typetraits][issame]")
{
  bool result = etl98::IsSame<char, int>::value;
  REQUIRE(false == result);
  result = etl98::IsSame<char, char>::value;
  REQUIRE(true == result);
  result = etl98::IsSame<char, ClassA>::value;
  REQUIRE(false == result);
  result = etl98::IsSame<ClassA, ClassB>::value;
  REQUIRE(false == result);
  result = etl98::IsSame<ClassA, ClassA>::value;
  REQUIRE(true == result);
}

