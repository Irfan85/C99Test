//
// Created by irfan on 11/28/23.
//
#define CATCH_CONFIG_MAIN
#include<iostream>
#include "catch.hpp"


extern "C" {
#include "../calculator/Calculator.h"
};

class CalculatorTestsFixture {
private:
public:
    CalculatorTestsFixture(){
        std::cout << "Beginning tests." << std::endl;
    }

    virtual ~CalculatorTestsFixture() {
        std::cout << "Tests complete." << std::endl;
    }
};

TEST_CASE_METHOD(CalculatorTestsFixture, "Adding two integers") {
    SECTION("Both positive numbers") {
        std::cout << "In test: Adding two integers (Both Positive)" << std::endl;
        REQUIRE(addInteger(2, 3) == 5);
    }

    SECTION("One positive and one negative numbers") {
        std::cout << "In test: Adding two integers (One positive and one negative)" << std::endl;
        REQUIRE(addInteger(-2, 3) == 1);
    }
}

TEST_CASE("This is a test", "[summation][positive]"){
    std::cout << "In a standalone test case." << std::endl;
    REQUIRE(addInteger(10, 9) == 19);
}
