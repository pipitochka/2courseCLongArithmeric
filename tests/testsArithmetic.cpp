#include "../include/bigDecimal.h"
#include <cassert>
#include <iostream>

void testAdd1() {
    BigDecimal bg1 = BigDecimal("6", 12);
    BigDecimal bg2 = BigDecimal("8", 12);

    BigDecimal ans1 = BigDecimal("12", 12);
    BigDecimal ans2 = BigDecimal("16", 12);
    BigDecimal ans3 = BigDecimal("14", 12);
    
    assert((bg1 + bg1) == ans1);
    assert((bg2 + bg2) == ans2);
    assert((bg1 + bg2) == ans3);
    assert((bg2 + bg1) == ans3);
}

void testAdd2() {
    BigDecimal bg1 = BigDecimal("431785934", 0);
    BigDecimal bg2 = BigDecimal("2402348202342", 0);

    BigDecimal ans1 = BigDecimal("863571868", 0);
    BigDecimal ans2 = BigDecimal("4804696404684", 0);
    BigDecimal ans3 = BigDecimal("2402779988276", 0);
    
    assert((bg1 + bg1) == ans1);
    assert((bg2 + bg2) == ans2);
    assert((bg1 + bg2) == ans3);
    assert((bg2 + bg1) == ans3);
}

void testAdd3() {
    BigDecimal bg1 = BigDecimal("3239483.24294209", 27);
    BigDecimal bg2 = BigDecimal("2424290.2394924923", 27);

    BigDecimal ans1 = BigDecimal("863571868", 27);
    BigDecimal ans2 = BigDecimal("4804696404684", 27);
    BigDecimal ans3 = BigDecimal("2402779988276", 27);

    BigDecimal myans1 = bg1 + bg1;
    BigDecimal myans2 = bg2 + bg2;
    BigDecimal myans3 = bg1 + bg2;
    BigDecimal myans4 = bg2 + bg2;
    
    std::cout << myans1 << std::endl;
    std::cout << myans2 << std::endl;
    std::cout << myans3 << std::endl;
    std::cout << myans4 << std::endl;
    
    
    // assert((bg1 + bg1) == ans1);
    // assert((bg2 + bg2) == ans2);
    // assert((bg1 + bg2) == ans3);
    // assert((bg2 + bg1) == ans3);
}

int main() {
    testAdd1();
    testAdd2();
    testAdd3();
}