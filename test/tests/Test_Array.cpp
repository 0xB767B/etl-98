#include "catch.hpp"
#include "etl-98/Array.h"

TEST_CASE("Array", "[array]")
{
  SECTION("Array initialization works")
  {
    Array<int, 5> a = { 0, 1, 2, 3, 4 };
    REQUIRE(0 == a[0]);
    REQUIRE(1 == a[1]);
    REQUIRE(2 == a[2]);
    REQUIRE(3 == a[3]);
    REQUIRE(4 == a[4]);
  }
}

