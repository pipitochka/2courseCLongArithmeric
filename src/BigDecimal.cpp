//
// Created by Артем Акулов on 29.01.2025.
//

#include "../include/BigDecimal.h"

BigDecimal::BigDecimal(int left, int right) : _left(left), _right(right) {
    _dataLeft.resize(_left);
    _dataRight.resize(_right);
    std::fill(_dataLeft.begin(), _dataLeft.end(), false);
    std::fill(_dataRight.begin(), _dataRight.end(), false);
};

BigDecimal::BigDecimal(const BigDecimal &other) {
    _left = other._left;
    _right = other._right;
    _dataLeft.resize(_left);
    _dataRight.resize(_right);
    std::copy(other._dataLeft.begin(), other._dataLeft.end(), _dataLeft.begin());
    std::copy(other._dataRight.begin(), other._dataRight.end(), _dataRight.begin());
}

BigDecimal &BigDecimal::operator=(const BigDecimal &other) {
    _left = other._left;
    _right = other._right;
    _dataLeft.resize(_left);
    _dataRight.resize(_right);
    std::copy(other._dataLeft.begin(), other._dataLeft.end(), _dataLeft.begin());
    std::copy(other._dataRight.begin(), other._dataRight.end(), _dataRight.begin());
    return *this;
}
