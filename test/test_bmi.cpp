#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Code/bmi.h"

TEST_CASE("ounces2pounds tests") {
    CHECK(ounces2pounds(32) == 2);
    CHECK(ounces2pounds(0) == 0);//edge case
    CHECK(ounces2pounds(15) == doctest::Approx(0.9375));//edge case
    CHECK(ounces2pounds(48) == 3);
    CHECK(ounces2pounds(1000000) == doctest::Approx(62500.0));//edge case
    CHECK(ounces2pounds(-1) == doctest::Approx(-0.0625));//edge case
}

TEST_CASE("stones2pounds tests") {
    CHECK(stones2pounds(5) == 70);
    CHECK(stones2pounds(0) == 0);//edge case
    CHECK(stones2pounds(-1) == -14);//edge case
    CHECK(stones2pounds(10) == 140);
    CHECK(stones2pounds(1000) == 14000);//edge case
    CHECK(stones2pounds(-100) == -1400);//edge case
}

TEST_CASE("weight2kg tests") {
    CHECK(weight2kg(0, 0, 0) == doctest::Approx(0.0));//edge case
    CHECK(weight2kg(0, 0, 22) == doctest::Approx(0.625));
    CHECK(weight2kg(1, 0, 0) == doctest::Approx(6.36).epsilon(0.01));
    CHECK(weight2kg(2, 5, 8) == doctest::Approx(15.23).epsilon(0.01));
    CHECK(weight2kg(0, 0, 10000) == doctest::Approx(284.5).epsilon(0.01));
    CHECK(weight2kg(0, -10, 100) == doctest::Approx(-1.7045).epsilon(0.01));
}

TEST_CASE("height2metres tests") {
    CHECK(height2metres(0, 0) == doctest::Approx(0.0));//edge case
    CHECK(height2metres(1, 0) == doctest::Approx(0.305).epsilon(0.01));
    CHECK(height2metres(0, 12) == doctest::Approx(0.305).epsilon(0.01));
    CHECK(height2metres(5, 6) == doctest::Approx(1.68).epsilon(0.01));
    CHECK(height2metres(100, 0) == doctest::Approx(30.49).epsilon(0.01));//edge case
    CHECK(height2metres(0, -12) == doctest::Approx(-0.3049).epsilon(0.01));//edge case
}

TEST_CASE("categorise tests") {
    CHECK(categorise(40, 1.7) == 'A'); // BMI roughly 13.8
    CHECK(categorise(60, 1.7) == 'B'); // BMI roughly 20.8
    CHECK(categorise(75, 1.7) == 'C'); // BMI roughly 25.9
    CHECK(categorise(95, 1.7) == 'D'); // BMI roughly 32.9
    CHECK(categorise(0, 1.7) == 'A'); //edge case
    CHECK(categorise(100000, 1.7) == 'D'); //edge case
}

