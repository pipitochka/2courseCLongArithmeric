#include <iostream>
#include "include/BigDecimal.h"

int main()
{
    BigDecimal bg1 = BigDecimal("1.23");
    BigDecimal bg2 = BigDecimal("1.23", 5);
    BigDecimal bg3 = 1.23_longnum;
    BigDecimal bg4 = bg2 - bg1; 
    BigDecimal bg5 = bg2 * bg1;
    std::cout << bg5;
}
