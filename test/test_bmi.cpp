#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Code/bmi.h"

TEST_CASE("ounces2pounds tests") {
    CHECK(ounces2pounds(32) == 2);
    CHECK(ounces2pounds(0) == 0);          // edge
    CHECK(ounces2pounds(15) == 0);         // edge
    CHECK(ounces2pounds(48) == 3);
}

TEST_CASE("stones2pounds tests") {
    CHECK(stones2pounds(5) == 70);
    CHECK(stones2pounds(0) == 0);          // edge
    CHECK(stones2pounds(-1) == -14);       // edge
    CHECK(stones2pounds(10) == 140);
}

TEST_CASE("weight2kg tests") {
    CHECK(weight2kg(0, 0, 0) == doctest::Approx(0.0));               // edge
    CHECK(weight2kg(0, 0, 22) == doctest::Approx(0.625));            // 22 oz = 1.375 lbs → 0.625 kg
    CHECK(weight2kg(1, 0, 0) == doctest::Approx(6.36).epsilon(0.01)); // 14 lbs / 2.2
    CHECK(weight2kg(2, 5, 8) == doctest::Approx(15.59).epsilon(0.01));
}

TEST_CASE("height2metres tests") {
    CHECK(height2metres(0, 0) == doctest::Approx(0.0));               // edge
    CHECK(height2metres(1, 0) == doctest::Approx(0.305).epsilon(0.01));
    CHECK(height2metres(0, 12) == doctest::Approx(0.305).epsilon(0.01));
    CHECK(height2metres(5, 6) == doctest::Approx(1.68).epsilon(0.01));
}

TEST_CASE("categorise tests") {
    CHECK(categorise(40, 1.7) == 'A'); // BMI ≈ 13.8
    CHECK(categorise(60, 1.7) == 'B'); // BMI ≈ 20.8
    CHECK(categorise(75, 1.7) == 'C'); // BMI ≈ 25.9
    CHECK(categorise(95, 1.7) == 'D'); // BMI ≈ 32.9
}

