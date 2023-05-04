#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Denominator cant be zero") {
    CHECK_THROWS(Fraction(1, 0));
}

TEST_CASE("Default value is zero") {
    Fraction a;
    Fraction b(0, 1);
    CHECK(a == b);
}

TEST_CASE("Denominator doesnt affect equality if numerator is zero") {
    Fraction a(0, 1);
    Fraction b(0, 2);
    CHECK(a == b);
}

TEST_CASE("Fraction equals itself") {
    Fraction a(1, 1);
    CHECK(a == a);
}

TEST_CASE("Fraction inequality") {
    Fraction a(1, 1);
    Fraction b(1, 2);
    Fraction c(2, 2);
    
    CHECK(a != b);
    CHECK(a != 2);
    CHECK(!(a != c));
}

TEST_CASE("Construct from float") {
    Fraction a(1, 2);
    Fraction b(0.5);
    CHECK(a == b);
}

TEST_CASE("Construct from float other fraction") {
    Fraction a(1, 1);
    Fraction b(a);
    CHECK(a == b);
}

TEST_CASE("Negative sign location doesnt matter") {
    Fraction a(-1, 1);
    Fraction b(1, -1);
    CHECK(a == b);
}

TEST_CASE("Fraction equals its float value") {
    Fraction a(1, 1);
    CHECK(a == 1);
}

TEST_CASE("Fraction equals its reduced value") {
    Fraction a(1, 1);
    Fraction b(2, 2);
    CHECK(a == b);
}

TEST_CASE("Fraction addition works") {
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction c(5, 6);
    Fraction d(3, 2);

    CHECK(a + b == c);
    CHECK(a + 1 == d);
    CHECK(1 + a == d);
}

TEST_CASE("Fraction subtraction works") {
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction c(1, 6);
    Fraction d(-1, 2);

    CHECK(a - b == c);
    CHECK(a - 1 == d);
    CHECK(1 - a == a);
}

TEST_CASE("Fraction multiplication works") {
    Fraction a(2, 1);
    Fraction b(1, 3);

    Fraction c(2, 3);
    Fraction d(4, 1);

    CHECK(a * b == c);
    CHECK(a * 2 == d);
    CHECK(2 * a == d);
}

TEST_CASE("Fraction division works") {
    Fraction a(1, 2);

    Fraction b(1, 1);
    Fraction c(1, 4);
    Fraction d(4, 1);

    CHECK(a / a == b);
    CHECK(a / 2 == c);
    CHECK(2 / a == d);
}

TEST_CASE("Prefix increment and decrement operators") {
    Fraction a(1, 2);

    CHECK(a++ == 0.5);
    CHECK(a == 1.5);

    CHECK(a-- == 1.5);
    CHECK(a == 0.5);
}

TEST_CASE("Postfix increment and decrement operators") {
    Fraction a(1, 2);

    CHECK(++a == 1.5);
    CHECK(a == 1.5);

    CHECK(--a == 0.5);
    CHECK(a == 0.5);
}

TEST_CASE("Input and output operators")
{
    Fraction a(1, 2);
    CHECK_NOTHROW(cout << a << "\n");
}

TEST_CASE("Greater than")
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    CHECK(a > b);
    CHECK(a > 0);
    CHECK(1 > a);
}

TEST_CASE("Lesser than")
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    CHECK(b < a);
    CHECK(0 < a);
    CHECK(a < 1);
}

TEST_CASE("Greater or equal to")
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    CHECK(a >= b);
    CHECK(a >= 0);
    CHECK(1 >= a);

    CHECK(a >= a);
}

TEST_CASE("Lesser or equal to")
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    CHECK(b <= a);
    CHECK(0 <= a);
    CHECK(a <= 1);

    CHECK(a <= a);
}