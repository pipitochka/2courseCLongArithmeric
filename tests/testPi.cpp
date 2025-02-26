#include "../include/bigDecimal.h"
#include <cassert>
#include <iostream>

void testPi1() {
    std::cout << BigDecimal::generatePiDigits(10) << std::endl;
}

void testPi2() {
    std::cout << BigDecimal::generatePiDigits(100) << std::endl;
}

int main() {
    //testPi1();
    testPi2();
}