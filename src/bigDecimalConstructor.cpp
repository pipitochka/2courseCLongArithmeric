#include "../include/bigDecimal.h"

BigDecimal BigDecimal::expand(int x, int y) const {
    std::vector<int> left(x);
    std::fill(left.begin(), left.end(), 0);
    std::vector<int> right(y);
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

std::string BigDecimal::decimalToBinary(std::string &number) {
    std::string binary;

    while (number != "0") {
        int lastDigit = number.back() - '0';
        binary += (lastDigit % 2 == 0) ? '0' : '1'; // Записываем остаток
        number = divideByTwo(number); // Делим число на 2
    }

    //std::reverse(binary.begin(), binary.end()); // Разворачиваем строку

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
    std::string two = "1";
    std::string copy = integerPart;
    for (int i = 0; i < copy.size(); i++) {
        if (copy[i] == '1') {
            result = addBinary(result, two);
        }
        two = addBinary(two, two);
    }
    return result;
}

std::string BigDecimal::divideByTwoDecimal(const std::string& number) {
    std::string result;
    int carry = 0;

    for (char digit : number) {
        int current = carry * 10 + (digit - '0'); 
        result += (current / 2) + '0'; 
        carry = current % 2; 
    }
    
    if (carry != 0) {
        result += '5';
    }
    return result;
}

std::string BigDecimal::binaryFractionToDecimal(const std::string& fractionalPart) {
    std::string result = "0";
    std::string two = "5";
    for (int i = 0; i < fractionalPart.size(); i++) {
        if (fractionalPart[i] == '1') {
             result = addBinaryLeft(result, two);
             }
        two = divideByTwoDecimal(two);
    }
    return result;
}

std::string BigDecimal::addBinaryLeft(const std::string& num1, const std::string& num2) {
    std::string copy1 = num1;
    std::string copy2 = num2;
    while (copy1.size() < copy2.size()) {
        copy1.push_back('0');
    }
    while (copy2.size() < copy1.size()) {
        copy2.push_back('0');
    }
    return addBinary(copy1, copy2);
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
    _sign = true;;
    _dataLeft.resize(_left);
    _dataRight.resize(_right);
    std::fill(_dataLeft.begin(), _dataLeft.end(), false);
    std::fill(_dataRight.begin(), _dataRight.end(), false);
};

BigDecimal::BigDecimal(const BigDecimal &other) {
    _sign = other._sign;
    _left = other._left;
    _right = other._right;
    _dataLeft.resize(_left);
    _dataRight.resize(_right);
    std::copy(other._dataLeft.begin(), other._dataLeft.end(), _dataLeft.begin());
    std::copy(other._dataRight.begin(), other._dataRight.end(), _dataRight.begin());
}

BigDecimal::BigDecimal(const std::vector<int> &left , const std::vector<int> &right ) {
    _sign = true;
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
    _sign = other._sign;
    return *this;
}

BigDecimal operator ""_longnum(long double number) {
    std::string numberAsString = std::to_string(number);
    BigDecimal result(numberAsString);
    return result;
}

BigDecimal::BigDecimal(const std::string& ss, int n) {
    std::string s;
    if (ss[0] == '-') {
        _sign = false;
        s = ss.substr(1, s.size() - 1);
    }
    else {
        _sign = true;
        s = ss;
    }
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
    this->erazeZeros();
};

void BigDecimal::Convert(std::string &s1, std::string &s2, int n) {
    std::string left = decimalToBinary(s1);
    std::string right = decimalFractionToBinary(s2, n);
    std::vector<int> leftData, rightData;
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

std::ostream & operator<<(std::ostream &os, const BigDecimal &bd) {
    std::string ss;
    if (!bd._sign) {
        os << '-';
    }
    for (int i = 0; i < bd._dataLeft.size(); i++) {
        ss += bd._dataLeft[i] + '0';
    }
    if (bd._dataRight.size() == 0) {
        ss += '0';
    }
    if (bd._dataRight.size() > 0) {
        ss += '.';
        for (int i = 0; i < bd._dataRight.size(); i++) {
            ss += bd._dataRight[i] + '0';
        }
    }
    ss = BigDecimal::binaryToDecimal(ss);
    os << ss;
    return os;
}

void BigDecimal::changeSign() {
    this->_sign *= false;
}

void BigDecimal::erazeZeros() {
    int zeros = 0;
    while ((this->_left - 1 - zeros) >= 0 && this->_dataLeft[this->_left - 1 - zeros] == 0) {
        zeros++;
    }
    this->_left -= zeros;
    this->_dataLeft.resize(this->_left);
}

void BigDecimal::reduceOverflow() {
    int overflow = 0;
    for (int i = this->_right - 1; i >= 0; i--) {
        this->_dataRight[i] += overflow;
        overflow = this->_dataRight[i] / 2;
        this->_dataRight[i] = this->_dataRight[i] % 2;
    }

    for (int i = 0; i < this->_left; i++) {
        this->_dataLeft[i] += overflow;
        overflow = this->_dataLeft[i] / 2;
        this->_dataLeft[i] = this->_dataLeft[i] % 2;
    }

    while (overflow) {
        this->_left++;
        this->_dataLeft.push_back(overflow % 2);
        overflow /= 2;
    }
}
