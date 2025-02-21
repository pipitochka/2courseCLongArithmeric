#include "../include/bigDecimal.h"
#include <cassert>
#include <iostream>

void testMul1() {
    BigDecimal bg1 = BigDecimal("6", 12);
    BigDecimal bg2 = BigDecimal("8", 12);

    BigDecimal ans1 = BigDecimal("36", 12);
    BigDecimal ans2 = BigDecimal("64", 12);
    BigDecimal ans3 = BigDecimal("48", 12);
    
    assert((bg1 * bg1) == ans1);
    assert((bg2 * bg2) == ans2);
    assert((bg1 * bg2) == ans3);
    assert((bg2 * bg1) == ans3);
}

void testMul2() {
    BigDecimal bg1 = BigDecimal("11", 12);
    BigDecimal bg2 = BigDecimal("12", 12);

    BigDecimal ans1 = BigDecimal("121", 12);
    BigDecimal ans2 = BigDecimal("144", 12);
    BigDecimal ans3 = BigDecimal("132", 12);
    
    assert((bg1 * bg1) == ans1);
    assert((bg2 * bg2) == ans2);
    assert((bg1 * bg2) == ans3);
    assert((bg2 * bg1) == ans3);
}

void testMul3() {
    BigDecimal bg1 = BigDecimal("0.5", 12);
    BigDecimal bg2 = BigDecimal("0.25", 12);

    BigDecimal ans1 = BigDecimal("0.25", 12);
    BigDecimal ans2 = BigDecimal("0.0625", 12);
    BigDecimal ans3 = BigDecimal("0.125", 12);
    
    assert((bg1 * bg1) == ans1);
    assert((bg2 * bg2) == ans2);
    assert((bg1 * bg2) == ans3);
    assert((bg2 * bg1) == ans3);
}

void testMul4() {
    BigDecimal bg1 = BigDecimal("1.5", 12);
    BigDecimal bg2 = BigDecimal("2.25", 12);

    BigDecimal ans1 = BigDecimal("2.25", 12);
    BigDecimal ans2 = BigDecimal("5.0625", 12);
    BigDecimal ans3 = BigDecimal("3.375", 12);
    
    assert((bg1 * bg1) == ans1);
    assert((bg2 * bg2) == ans2);
    assert((bg1 * bg2) == ans3);
    assert((bg2 * bg1) == ans3);
}

void testMul5() {
    BigDecimal bg1 = BigDecimal("93.6015625", 20);
    BigDecimal bg2 = BigDecimal("43.671875", 20);

    BigDecimal ans1 = BigDecimal("8761.25250244140625", 20);
    BigDecimal ans2 = BigDecimal("1907.232666015625", 20);
    BigDecimal ans3 = BigDecimal("4087.7557373046875", 20);
    
    assert((bg1 * bg1) == ans1);
    assert((bg2 * bg2) == ans2);
    assert((bg1 * bg2) == ans3);
    assert((bg2 * bg1) == ans3);
}

int main() {
    testMul1();
    testMul2();
    testMul3();
    testMul4();
    testMul5();
}