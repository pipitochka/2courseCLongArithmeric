#include "../include/bigDecimal.h"
#include <cassert>
#include <iostream>

void testLogic1() {
    BigDecimal bg1 = BigDecimal("6", 12);
    BigDecimal bg2 = BigDecimal("8", 12);

    assert(bg1 != bg2);
}

void testLogic2() {
    BigDecimal bg1 = BigDecimal("19", 12);
    BigDecimal bg2 = BigDecimal("19", 12);

    assert(bg1 == bg2);
}

void testLogic3() {
    BigDecimal bg1 = BigDecimal("320420342.2340242904", 12);
    BigDecimal bg2 = BigDecimal("320420342.2340242904", 12);

    assert(bg1 == bg2);
}

void testLogic4() {
    BigDecimal bg1 = BigDecimal("320420342.2360242904", 12);
    BigDecimal bg2 = BigDecimal("320420342.2340142904", 12);

    assert(bg1 > bg2);
}

void testLogic5() {
    BigDecimal bg1 = BigDecimal("3490824028.23482394", 12);
    BigDecimal bg2 = BigDecimal("3490829028.23482394", 12);

    assert(bg1 < bg2);
}

void testLogic6() {
    BigDecimal bg1 = BigDecimal("-239324.034242942", 12);
    BigDecimal bg2 = BigDecimal("248273482.24829482", 12);

    assert(bg1 < bg2);
}

void testLogic8() {
    BigDecimal bg1 = BigDecimal("239324.034242942", 12);
    BigDecimal bg2 = BigDecimal("-248273482.24829482", 12);

    assert(bg1 > bg2);
}

void testLogic9() {
    BigDecimal bg1 = BigDecimal("239324.034242942", 6);
    BigDecimal bg2 = BigDecimal("239324.034242942", 12);

    assert(bg1 < bg2);
}

int main() {
    testLogic1();
    testLogic2();
    testLogic3();
    testLogic4();
    testLogic5();
    testLogic6();
    testLogic8();
    testLogic9();
    return 0;
}