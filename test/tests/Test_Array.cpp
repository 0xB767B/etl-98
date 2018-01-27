#include "catch.hpp"
#include "etl-98/Array.h"

TEST_CASE("Array", "[array]")
{
  SECTION("Array initialization works")
  {
    Array<int, 5> a = { 0, 1, 2, 3, 4 };
    for(int i = 0; i < 5; i++) {
      REQUIRE(i == a[i]);
    }
  }
}

