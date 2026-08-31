#include <catch.hpp>

#include "multiplication.h"

TEST_CASE("Simple") {
    REQUIRE(6 == Multiply(2, 3));
}

TEST_CASE("Advanced") {
    REQUIRE(246913575308642LL == Multiply(11111111, 22222222));
}
