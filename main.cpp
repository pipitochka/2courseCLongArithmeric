#include <iostream>
#include "include/BigDecimal.h"

int main()
{
    BigDecimal bg = BigDecimal("123.123");
    std::cout << bg << std::endl;
    std::cout << bg.binaryToDecimal("1111011.00011111011111001110");
    return 0;
}
