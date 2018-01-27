#include "catch.hpp"
#include "etl-98/Typelist.h"

TEST_CASE("Typelist Length is correct", "[typelist][length]")
{
  SECTION("Length is calculated correctly")
  {
    typedef etl98::TypelistOps::MakeTypelist<int>::Result ListOfIntOfLength1;
    typedef etl98::TypelistOps::MakeTypelist<int, int>::Result ListOfIntOfLength2;
    typedef etl98::TypelistOps::MakeTypelist<int, int, int>::Result ListOfIntOfLength3;

    int length = etl98::TypelistOps::Length<ListOfIntOfLength1>::value;
    REQUIRE(1 == length);
    length = etl98::TypelistOps::Length<ListOfIntOfLength2>::value;
    REQUIRE(2 == length);
    length = etl98::TypelistOps::Length<ListOfIntOfLength3>::value;
    REQUIRE(3 == length);
  }
}

TEST_CASE("Typelist Contains is correct", "[typelist][contains]")
{  
  typedef etl98::TypelistOps::MakeTypelist<char, short, int>::Result ListOfIntegers;

  SECTION("Contains is correct for All types in list")
  {
    bool contains = etl98::TypelistOps::Contains<ListOfIntegers, char>::value;
    REQUIRE(true == contains);
    contains = etl98::TypelistOps::Contains<ListOfIntegers, short>::value;
    REQUIRE(true == contains);
    contains = etl98::TypelistOps::Contains<ListOfIntegers, int>::value;
    REQUIRE(true == contains);
  }

  SECTION("Contains is correct for type not in list")
  {
    bool contains = etl98::TypelistOps::Contains<ListOfIntegers, float>::value;
    REQUIRE(false == contains);
  }

  SECTION("Contains is false for NullType")
  {
    bool contains = etl98::TypelistOps::Contains<ListOfIntegers, etl98::NullType>::value;
    REQUIRE(false == contains);
  }
}

