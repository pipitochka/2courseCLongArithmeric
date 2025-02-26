#include <iostream>
#include "include/bigDecimal.h"

int main()
{
    BigDecimal bg1 = BigDecimal("6", 12);
    BigDecimal bg2 = BigDecimal("8", 12);
    std::cout << bg2 + bg1 << std::endl;
    std::cout << bg2 + bg2 << std::endl;
}
