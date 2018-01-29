#include "catch.hpp"
#include "etl-98/Pow2.h"

TEST_CASE("Pow2", "[pow][pow2]")
{
  SECTION("Pow2 calculations are correct")
  {
    int result = Pow2<0>::value;
    REQUIRE(1 == result);
    result = Pow2<1>::value;
    REQUIRE(2 == result);
    result = Pow2<2>::value;
    REQUIRE(4 == result);
    result = Pow2<3>::value;
    REQUIRE(8 == result);
    result = Pow2<4>::value;
    REQUIRE(16 == result);
   }
}

