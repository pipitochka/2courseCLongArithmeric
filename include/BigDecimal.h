#pragma once
#ifndef LONGARITHEMTIC_H
#define LONGARITHEMTIC_H

#include <algorithm>
#include <vector>

class BigDecimal{
    private:
    int _left;
    int _right;
    std::vector<bool> _dataLeft;
    std::vector<bool> _dataRight;

    public:
    BigDecimal() = delete;
    BigDecimal(int left, int right);
    BigDecimal(const std::string& s);
    ~BigDecimal() = default;
    BigDecimal(const BigDecimal& other);
    BigDecimal& operator=(const BigDecimal& other);

    BigDecimal operator+(const BigDecimal& other);
    BigDecimal operator-(const BigDecimal& other);
    BigDecimal operator*(const BigDecimal& other);
    BigDecimal operator/(const BigDecimal& other);

    bool operator==(const BigDecimal& other);
    bool operator!=(const BigDecimal& other);
    bool operator<(const BigDecimal& other);
    bool operator>(const BigDecimal& other);
};

BigDecimal operator""_longnum(long double number);

#endif //LONGARITHEMTIC_H
