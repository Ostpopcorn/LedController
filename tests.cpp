#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "include/Coordinate.h"

TEST_CASE("Testing coordinate")
{
    Coordinate a{1,1};
    Coordinate b{-1,1};
    REQUIRE(a.getX() == 1);
    REQUIRE(a.getY() == 1);
    REQUIRE(a.getR() == sqrtf(2));
    REQUIRE(b.getR() == sqrtf(2));

    Coordinate sum{a+b};
    Coordinate diff{a-b};

    REQUIRE(sum.getX() == 0);
    REQUIRE(sum.getY() == 2);
    REQUIRE(sum.getR() == 2);

    REQUIRE(diff.getX() == 2);
    REQUIRE(diff.getY() == 0);
    REQUIRE(diff.getR() == 2);

}