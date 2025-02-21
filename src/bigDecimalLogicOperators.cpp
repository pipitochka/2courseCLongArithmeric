#include "../include/bigDecimal.h"

bool BigDecimal::operator==(const BigDecimal &other) const{
    
    if (this->_left != other._left || this->_right != other._right) {
        return false;
    }
    for (int i = 0; i < this->_left; i++) {
        if (this->_dataLeft[i] != other._dataLeft[i]) {
            return false;
        }
    }
    for (int i = 0; i < this->_right; i++) {
        if (this->_dataRight[i] != other._dataRight[i]) {
            return false;
        }
    }

    return true;
}

bool BigDecimal::operator!=(const BigDecimal &other) const {
    return !(*this == other);
}

bool BigDecimal::operator>(const BigDecimal &other) const {
    if (this->_sign > other._sign) {
        return true;
    }
    if (this->_sign < other._sign) {
        return false;
    }
    
    if (this->_left > other._left) {
        return true * this->_sign;
    }
    if (this->_left < other._left) {
        return false * this->_sign;
    }
    
    if (this->_left != 0) {
        for (int i = this->_left - 1; i < this->_left; i++) {
            if (this->_dataLeft[i] != other._dataLeft[i]) {
                return (this->_dataLeft[i] > other._dataLeft[i]) * this->_sign;
            }
        }
    }
    for (int i = 0; i < std::min(this->_right, other._right); i++) {
        if (this->_dataRight[i] != other._dataRight[i]) {
            return (this->_dataRight[i] > other._dataRight[i]) * this->_sign;
        }
    }
    if (this->_right > other._right) {
        return true * this->_sign;
    }
    return false * this->_sign;
    
}

bool BigDecimal::operator<(const BigDecimal &other) const {
    return !(*this > other || *this == other);
}