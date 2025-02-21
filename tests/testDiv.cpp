#include "../include/bigDecimal.h"
#include <cassert>
#include <iostream>

void testDiv1() {
    BigDecimal bg1 = BigDecimal("4", 12);
    BigDecimal bg2 = BigDecimal("16", 12);

    BigDecimal ans1 = BigDecimal("1", 12);
    BigDecimal ans2 = BigDecimal("4", 12);
    
    assert((bg1 / bg1) == ans1);
    assert((bg2 / bg2) == ans1);
    assert((bg2 / bg1) == ans2);
}

void testDiv2() {
    BigDecimal bg1 = BigDecimal("9", 12);
    BigDecimal bg2 = BigDecimal("3", 12);

    BigDecimal ans1 = BigDecimal("1", 12);
    BigDecimal ans2 = BigDecimal("3", 12);
    
    assert((bg1 / bg1) == ans1);
    assert((bg2 / bg2) == ans1);
    assert((bg1 / bg2) == ans2);
}

void testDiv3() {
    BigDecimal bg1 = BigDecimal("9.5", 12);
    BigDecimal bg2 = BigDecimal("4.75", 12);

    BigDecimal ans1 = BigDecimal("1", 12);
    BigDecimal ans2 = BigDecimal("2", 12);
    
    assert((bg1 / bg1) == ans1);
    assert((bg2 / bg2) == ans1);
    assert((bg1 / bg2) == ans2);
}

void testDiv4() {
    BigDecimal bg1 = BigDecimal("97.0166015625", 12);
    BigDecimal bg2 = BigDecimal("17.34375", 12);

    BigDecimal ans1 = BigDecimal("1", 12);
    BigDecimal ans2 = BigDecimal("5.59375", 12);
    
    assert((bg1 / bg1) == ans1);
    assert((bg2 / bg2) == ans1);
    assert((bg1 / bg2) == ans2);
}

int main() {
    testDiv1();
    testDiv2();
    testDiv3();
    testDiv4();
}