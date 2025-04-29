#include <iostream>
#include <cmath>
#include "../Code/bmi.cpp"

void test_ounces2pounds() {
    std::cout << "\nTesting ounces2pounds():\n";
    // Normal tests
    std::cout << (ounces2pounds(16) == 1 ? "PASS 16oz -> 1lb\n" : "FAIL 16oz\n");
    std::cout << (ounces2pounds(8) == 0.5 ? "PASS 8oz -> 0.5lb\n" : "FAIL 8oz\n");
    // Edge case
    std::cout << (ounces2pounds(0) == 0 ? "PASS 0oz -> 0lb\n" : "FAIL 0oz\n");
}

void test_stones2pounds() {
    std::cout << "\nTesting stones2pounds():\n";
    // Normal tests
    std::cout << (stones2pounds(1) == 14 ? "PASS 1st -> 14lb\n" : "FAIL 1st\n");
    std::cout << (stones2pounds(2) == 28 ? "PASS 2st -> 28lb\n" : "FAIL 2st\n");
    // Edge case
    std::cout << (stones2pounds(0) == 0 ? "PASS 0st -> 0lb\n" : "FAIL 0st\n");
}

void test_weight2kg() {
    std::cout << "\nTesting weight2kg():\n";
    // Normal tests
    std::cout << (fabs(weight2kg(1,0,0) - 6.35) < 0.01 ? "PASS 1st -> ~6.35kg\n" : "FAIL 1st\n");
    std::cout << (fabs(weight2kg(0,2,8) - 1.19) < 0.01 ? "PASS 2lb8oz -> ~1.19kg\n" : "FAIL 2lb8oz\n");
    // Edge case
    std::cout << (weight2kg(0,0,0) == 0 ? "PASS 0 weight\n" : "FAIL 0 weight\n");
}

void test_height2metres() {
    std::cout << "\nTesting height2metres():\n";
    // Normal tests
    std::cout << (fabs(height2metres(5,9) - 1.75) < 0.01 ? "PASS 5'9\" -> ~1.75m\n" : "FAIL 5'9\"\n");
    std::cout << (fabs(height2metres(6,0) - 1.83) < 0.01 ? "PASS 6'0\" -> ~1.83m\n" : "FAIL 6'0\"\n");
    // Edge case
    std::cout << (height2metres(0,1) > 0 ? "PASS 1\" -> >0m\n" : "FAIL 1\"\n");
}

void test_categorise() {
    std::cout << "\nTesting categorise():\n";
    // Normal tests
    std::cout << (categorise(18.5, 1.7) == 'A' ? "PASS BMI 18.5 -> A\n" : "FAIL BMI 18.5\n");
    std::cout << (categorise(25.1, 1.7) == 'C' ? "PASS BMI 25.1 -> C\n" : "FAIL BMI 25.1\n");
    // Edge case
    std::cout << (categorise(19.0, 1.7) == 'B' ? "PASS exact threshold 19 -> B\n" : "FAIL threshold 19\n");
}

int main() {
    std::cout << "=== BMI Program Tests ===";
    test_ounces2pounds();
    test_stones2pounds();
    test_weight2kg();
    test_height2metres();
    test_categorise();
    return 0;
}
