#include <doctest.h>
#include "funcs.h"

TEST_CASE("doctest works"){
    REQUIRE(true);
}

TEST_CASE("summ") {
    int a = 1, b = 2;
    REQUIRE(Summ(1, 2) == 3);
}