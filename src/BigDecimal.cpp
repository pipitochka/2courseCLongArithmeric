//
// Created by Артем Акулов on 29.01.2025.
//
#include "../include/BigDecimal.h"
#include <iostream>

BigDecimal BigDecimal::expand(int x, int y) const {
    std::vector<char> left(x);
    std::fill(left.begin(), left.end(), 0);
    std::vector<char> right(y);
    std::fill(right.begin(), right.end(), 0);
    for (int i = x - _left; i < x; i++) {
        left[i] = _dataLeft[i - x + _left];
    }
    for (int i = 0; i < _right; i++) {
        right[i] = _dataRight[i];
    }
    return BigDecimal(left, right);
}


std::string BigDecimal::divideByTwo(const std::string& number) {
    std::string result;
    int carry = 0;

    for (char digit : number) {
        int current = carry * 10 + (digit - '0'); 
        result += (current / 2) + '0'; 
        carry = current % 2; 
    }
    
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}

std::string BigDecimal::multiplyByTwo(const std::string& num) {
    std::string result;
    int carry = 0;

    for (int i = num.size() - 1; i >= 0; i--) {
        int digit = (num[i] - '0') * 2 + carry;
        result += (digit % 10) + '0';
        carry = digit / 10;
    }
    
    if (carry) {
        result += (carry + '0');
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string BigDecimal::decimalStringToBinary(std::string &number) {
    std::string binary;

    while (number != "0") {
        int lastDigit = number.back() - '0';
        binary += (lastDigit % 2 == 0) ? '0' : '1'; // Записываем остаток
        number = divideByTwo(number); // Делим число на 2
    }

    std::reverse(binary.begin(), binary.end()); // Разворачиваем строку

    return binary;
}

std::string BigDecimal::decimalFractionToBinary(const std::string &fraction, int precision) {
    std::string binary, result;
    binary = "0" + fraction;
    
    for (int i = 0; i < precision; ++i) {
        binary = multiplyByTwo(binary);
        if (binary[0] == '1') {
            result += '1';  
            binary[0] = '0';
        } else {
            result += '0';
        }
    }
    return result;
}


std::string BigDecimal::binaryIntegerToDecimal(const std::string& integerPart) {
    std::string result = "0";
    for (int i = 0; i < integerPart.size(); i++) {
        if (integerPart[i] == '1') {
            result = addBinary(result, powerOfTwo(i));
        }
    }
    return result;
}

std::string BigDecimal::binaryFractionToDecimal(const std::string& fractionalPart) {
    std::string result = "0";
    for (int i = 0; i < fractionalPart.size(); i++) {
        if (fractionalPart[i] == '1') {
            result = addBinary(result, powerOfTwo(-i - 1));  
        }
    }
    return result;
}

std::string BigDecimal::addBinary(const std::string& num1, const std::string& num2) {
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    std::string result;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;

        i--;
        j--;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string BigDecimal::powerOfTwo(int exponent) {
    if (exponent < 0) {
        return "0";  
    }

    std::string result = "1";
    for (int i = 0; i < exponent; i++) {
        result = addBinary(result, result);
    }
    return result;
}

std::string BigDecimal::binaryToDecimal(const std::string& binary) {
    std::string integerPart, fractionalPart;
    bool isFractional = false;

    for (char c : binary) {
        if (c == '.') {
            isFractional = true;
            continue;
        }
        if (isFractional) {
            fractionalPart += c;
        } else {
            integerPart += c;
        }
    }

    std::string integerResult = binaryIntegerToDecimal(integerPart);

    std::string fractionalResult = binaryFractionToDecimal(fractionalPart);

    if (!fractionalResult.empty()) {
        return integerResult + "." + fractionalResult;
    } else {
        return integerResult;
    }
}


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

BigDecimal::BigDecimal(const std::vector<char> &left , const std::vector<char> &right ) {
    _dataLeft = left;
    _dataRight = right;
    _left = _dataLeft.size();
    _right = _dataRight.size();
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

BigDecimal operator ""_longnum(long double number) {
    std::string numberAsString = std::to_string(number);
    BigDecimal result(numberAsString);
    return result;
}

std::ostream & operator<<(std::ostream &os, const BigDecimal &bd) {
    for (int i = 0; i < bd._left; i++) {
        os << static_cast<char>(bd._dataLeft[i] + '0');
    }
    if (bd._right > 0) {
        os << '.';
        for (int i = 0; i < bd._right; i++) {
            os << static_cast<char>(bd._dataRight[i] + '0');
        }
    }
    return os;
}

BigDecimal::BigDecimal(const std::string& s, int n) {
    std::string left, right = "";
    left = s;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '.') {
            break;
        }
        if (!(s[i] >= '0' && s[i] <= '9')) {
            throw InvalidChar();
        }
        i++;
    }
    if (i == s.size()) {
        Convert(left, right, n);
    }
    else {
        left = s.substr(0, i);
        right = s.substr(i + 1, s.size() - i);
        Convert(left, right, n);
    }
};

void BigDecimal::Convert(std::string &s1, std::string &s2, int n) {
    std::string left = decimalStringToBinary(s1);
    std::string right = decimalFractionToBinary(s2, n);
    std::vector<char> leftData, rightData;
    for (int i = 0; i < left.size(); i++) {
        leftData.push_back(left[i] - '0');
    }
    for (int i = 0; i < right.size(); i++) {
        rightData.push_back(right[i] - '0');
    }
    _dataLeft = leftData;
    _dataRight = rightData;
    _left = _dataLeft.size();
    _right = _dataRight.size();
}

BigDecimal BigDecimal::operator+(const BigDecimal &other) {}