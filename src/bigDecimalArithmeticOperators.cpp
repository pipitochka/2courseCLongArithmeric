#include "../include/bigDecimal.h"

BigDecimal BigDecimal::operator+(const BigDecimal& other) const {
    if (this->_sign != other._sign) {
        if (this > &other) {
            BigDecimal copy(other);
            copy._sign = this->_sign;
            return *this - copy;
        }
        else {
            BigDecimal copy(*this);
            copy._sign = this->_sign;
            return other - copy;
        }
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

BigDecimal BigDecimal::operator-(const BigDecimal& other) const {
    if (this->_sign != other._sign) {
        BigDecimal copy(other);
        copy._sign = this->_sign;
        return *this + copy;
    }
    if (this->_sign) {
        if (other > *this) {
            BigDecimal copy(other);
            copy = copy - *this;
            copy._sign *= false;
            return copy;
        }
    }
    if (!this->_sign) {
        if (other > *this) {
            BigDecimal copy(other);
            copy = copy - *this;
            copy._sign *= false;
            return copy;
        }
    }
    BigDecimal tmp(std::max(this->_left, other._left), std::max(this->_right, other._right));

    int overflow = 0;
    if (tmp._right != 0) {
        for (int i = tmp._right - 1; i >= 0; i--) {
            tmp._dataRight[i] += this->_right > i ? this->_dataRight[i] : 0;
            tmp._dataRight[i] -= other._right > i ? other._dataRight[i] : 0;
            tmp._dataRight[i] -= overflow;
            overflow = tmp._dataRight[i] < 0 ? 1 : 0;
            if (overflow) {
                tmp._dataRight[i] += 2;
            }
        }
    }
    for (int i = 0; i < tmp._left; i++) {
        tmp._dataLeft[i] += this->_left > i ? this->_dataLeft[i] : 0;
        tmp._dataLeft[i] -= other._left > i ? other._dataLeft[i] : 0;
        tmp._dataLeft[i] -= overflow;
        overflow = tmp._dataLeft[i] < 0 ? 1 : 0;
        if (overflow) {
            tmp._dataLeft[i] += 2;
        }
    }

    tmp.erazeZeros();
    
    return tmp;
}

BigDecimal BigDecimal::operator*(const BigDecimal& other) const {
    BigDecimal tmp(this->_left + other._left, this->_right + other._right);

    tmp._sign = this->_sign * other._sign;
    
    for (int i = 0; i < this->_left; i++) {
        for (int j = 0; j < other._left; j++) {
            tmp._dataLeft[i + j] += this->_dataLeft[i] * other._dataLeft[j];
        }
    }

    for (int i = 0; i < this->_right; i++) {
        for (int j = 0;  j < other._right; j++) {
            tmp._dataRight[i + j + 1] += this->_dataRight[i] * other._dataRight[j];
        }
    }

    for (int i = 0; i < this->_left; i++) {
        for (int j = 0; j < other._right; j++) {
            if (i > j) {
                tmp._dataLeft[i - j - 1] += this->_dataLeft[i] * other._dataRight[j];
            }
            else {
                tmp._dataRight[j - i] += this->_dataLeft[i] * other._dataRight[j];
            }
        }
    }

    for (int i = 0; i < other._left; i++) {
        for (int j = 0; j < this->_right; j++) {
            if (i > j) {
                tmp._dataLeft[i - j - 1] += other._dataLeft[i] * this->_dataRight[j];
            }
            else {
                tmp._dataRight[j - i] += other._dataLeft[i] * this->_dataRight[j];
            }
        }
    }
    
    tmp.reduceOverflow();
    tmp.erazeZeros();
    tmp._right = std::max(this->_right, other._right);
    tmp._dataRight.resize(tmp._right);
    return tmp;
}

bool isGreaterOrEqual(const std::deque<int>& a, const std::deque<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true; 
}

std::deque<int> subtract(const std::deque<int>& a, const std::deque<int>& b) {
    std::deque<int> result;
    int overflow = 0;
    for (int i = 0; i < a.size(); i++) {
        int tmp = a[a.size() - i - 1] - overflow;
        tmp -= i > b.size() - 1 ? 0 : b[b.size() - i - 1];
        overflow = tmp < 0 ? 1 : 0;
        if (overflow) {
            tmp += 2;
        }
        result.push_front(tmp);
    }
    
    while (result.size() > 1 && result[0] == 0) {
        result.pop_front();
    }
    
    return result;
}

std::pair<std::deque<int>, std::deque<int>> longDivision(
    const std::deque<int>& dividend, const std::deque<int>& divisor, int n) {

    std::deque<int> a;
    std::deque<int> b;

    for (size_t i = 0; i < dividend.size(); i++) {
        b.push_back(dividend[i]);

        while (b.size() > 1 && b[0] == 0) {
            b.pop_front();
        }
        
        if (isGreaterOrEqual(b, divisor)) {
            b = subtract(b, divisor);
            a.push_back(1);
        }
        else {
            a.push_back(0);
        }
    }

    while (a.size() > 1 && a[0] == 0) {
        a.erase(a.begin());
    }
    
    std::deque<int> c;
    for (size_t i = 0; i < n; i++) {
        b.push_back(0);

        while (b.size() > 1 && b[0] == 0) {
            b.pop_front();
        }
        
        if (isGreaterOrEqual(b, divisor)) {
            b = subtract(b, divisor);
            c.push_back(1);
        }
        else {
            c.push_back(0);
        }
    }

    return {a, c};
}

BigDecimal BigDecimal::operator/(const BigDecimal& other) const {
    if (other._left == 0 && other._dataLeft[0] == 0) {
        bool flag = true;
        for (int i = 0; i < other._right; i++) {
            if (other._dataLeft[i] != 0) {
                flag = false;
            }
        }
        if (flag) {
            throw std::invalid_argument("BigDecimal::operator/(other)");
        }
    }
    
    std::deque<int> a;
    std::deque<int> b;

    for (int i = this->_left - 1; i >= 0; i--) {
        a.push_back(this->_dataLeft[i]);
    }
    for (int i = other._left - 1; i >= 0; i--) {
        b.push_back(other._dataLeft[i]);
    }
    for (int i = 0; i < std::max(this->_right, other._right); i++) {
        b.push_back(i < other._right ? other._dataRight[i] : 0);
        a.push_back(i < this->_right ? this->_dataRight[i] : 0);
    }
    
    
    std::pair<std::deque<int>, std::deque<int>> result;
    result = longDivision(a, b, std::max(this->_right, other._right));

    BigDecimal tmp(result.first.size(), result.second.size());
    for (int i = 0; i < result.first.size(); i++) {
        tmp._dataLeft[i] = result.first[result.first.size() - i - 1];
    }
    for (int i = 0; i < result.second.size(); i++) {
        tmp._dataRight[i] = result.second[i];
    }

    tmp._sign = this->_sign * other._sign;
    tmp.erazeZeros();
    return tmp;
}


BigDecimal BigDecimal::generatePiDigits(int n) {
    n *= 7;
    n /= 2;
    BigDecimal sixteen("16", n);
    BigDecimal q("1", n);
    BigDecimal l("0", n);
    BigDecimal four("4", n);
    BigDecimal two("2", n);
    BigDecimal one("1", n);
    BigDecimal five("5", n);
    BigDecimal six("6", n);
    BigDecimal eight("8", n);
    BigDecimal result("0", n);
    BigDecimal zero("0", n);

    for (int i = 0; i < n; i++) {
        BigDecimal term1 = four / (l + one);
        BigDecimal term2 = two / (l + four);
        BigDecimal term3 = one / (l + five);
        BigDecimal term4 = one / (l + six);
        term1 = term1 - term2;
        term1 = term1 - term3;
        term1 = term1 - term4;
        result = result + q * term1;
        if (q * term1 == zero) {
            break;
        }
        l = l + eight;
        q = q / sixteen; 
    }

    return result;
}
