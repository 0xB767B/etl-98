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

TEST_CASE("Typetraits IsInteger gives correct results", "[typetraits][isintegral]")
{
  SECTION("Unsigned integers")
  {
    bool result = etl98::IsInteger<uint8_t>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<uint16_t>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<uint32_t>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<uint64_t>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<unsigned char>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<unsigned short>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<unsigned short int>::value;
    REQUIRE(1 == result);
    bool result = etl98::IsInteger<unsigned >::value;
    REQUIRE(1 == result);
  }
}

