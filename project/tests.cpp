#include <doctest.h>
#include "funcs.h"

TEST_CASE("doctest works"){
    REQUIRE(true);
}

TEST_CASE("summ") {
    int a = 1, b = -2;
    REQUIRE(Summ(a, b) == -1);
}

TEST_CASE("difference") {
    int a = 1, b = -3;
    REQUIRE(Diff(a, b) == 4);
}

TEST_CASE("multiplication") {
    int a = 3, b = -5;
    REQUIRE(Mult(a, b) == -15);
}

TEST_CASE("square") {
    int a = 3;
    REQUIRE(Square(a) == 9);
}

TEST_CASE("log") {
    int a = 9, b = 2;
    REQUIRE(Loga_b(a, b) == 3);
}

TEST_CASE("from 10 to 2") {
    int n = 17;
    REQUIRE(from10to2(n) == 10001);
}

TEST_CASE("from 10 to 4") {
    int n = 17;
    REQUIRE(from10to4(n) == 101);
}

TEST_CASE("from 10 to 8") {
    int n = 17;
    REQUIRE(from10to8(n) == 21);
}

TEST_CASE("from 10 to custom") {
    int n = 17, b = 3;
    REQUIRE(from10toyour(n, b) == 122);
}

TEST_CASE("Percent") {
    int n = 200, p = 40;
    REQUIRE(Percent(n, p) == 80);
}
