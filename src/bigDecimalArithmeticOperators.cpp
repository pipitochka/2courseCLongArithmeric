#include "../include/bigDecimal.h"
#include <iostream>

BigDecimal BigDecimal::operator+(const BigDecimal& other) const {
    if (this->_sign != other._sign) {
        
    }

    BigDecimal tmp(std::max(this->_left, other._left), std::max(this->_right, other._right));
    int overflow = 0;
    if (tmp._right != 0) {
        for (int i = tmp._right - 1; i >= 0; i--) {
            tmp._dataRight[i] += this->_right > i ? this->_dataRight[i] : 0;
            tmp._dataRight[i] += other._right > i ? other._dataRight[i] : 0;
            tmp._dataRight[i] += overflow;
            overflow = tmp._dataRight[i] / 2;
            tmp._dataRight[i] = tmp._dataRight[i] % 2;
        }
    }
    for (int i = 0; i < tmp._left; i++) {
        tmp._dataLeft[i] += this->_left > i ? this->_dataLeft[i] : 0;
        tmp._dataLeft[i] += other._left > i ? other._dataLeft[i] : 0;
        tmp._dataLeft[i] += overflow;
        overflow = tmp._dataLeft[i] / 2;
        tmp._dataLeft[i] = tmp._dataLeft[i] % 2;
    }

    while (overflow) {
        tmp._left++;
        tmp._dataLeft.push_back(overflow % 2);
        overflow /= 2;
    }
    
    return tmp;
}