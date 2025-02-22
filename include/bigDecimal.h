#pragma once
#ifndef LONGARITHEMTIC_H
#define LONGARITHEMTIC_H
#define PRECISION 20

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <deque>


class InvalidChar : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Invalid character";
    }
};

class BigDecimal{
    private:
    bool _sign;
    int _left;
    int _right;
    std::vector<int> _dataLeft;
    std::vector<int> _dataRight;
    BigDecimal expand(int x, int y) const;
    void Convert(std::string &s1, std::string &s2, int n);
    void changeSign();
    
    static std::string divideByTwo(const std::string &number);
    static std::string multiplyByTwo(const std::string& num);
    static std::string decimalFractionToBinary(const std::string &fraction, int precision);
    static std::string divideByTwoDecimal(const std::string& number);
    
    static std::string addBinary(const std::string& num1, const std::string& num2);
    static std::string binaryFractionToDecimal(const std::string& fractionalPart);
    static std::string binaryIntegerToDecimal(const std::string& integerPart);
    static std::string addBinaryLeft(const std::string& num1, const std::string& num2);
    
    static std::string binaryToDecimal(const std::string &binary);
    static std::string decimalToBinary(std::string &number);

    void erazeZeros();
    void reduceOverflow();

public:
    
    BigDecimal() = delete;
    BigDecimal(int left, int right);
    BigDecimal(const std::string& s, int n);
    BigDecimal(const std::string& s) : BigDecimal(s, PRECISION) {};
    ~BigDecimal() = default;
    BigDecimal(const BigDecimal& other);
    BigDecimal(const std::vector<int> &left, const std::vector<int> &right);
    BigDecimal& operator=(const BigDecimal& other);
    
    BigDecimal operator+(const BigDecimal& other) const;
    BigDecimal operator-(const BigDecimal& other) const;
    BigDecimal operator*(const BigDecimal& other) const;
    BigDecimal operator/(const BigDecimal& other) const;

    bool operator==(const BigDecimal& other) const;
    bool operator!=(const BigDecimal& other) const;
    bool operator<(const BigDecimal& other) const;
    bool operator>(const BigDecimal& other) const;
    
    friend std::ostream& operator << (std::ostream &os, const BigDecimal &bd);

    static BigDecimal generatePiDigits(int n);
};

BigDecimal operator""_longnum(long double number);


#endif //LONGARITHEMTIC_H
