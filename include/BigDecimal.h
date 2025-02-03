#pragma once
#ifndef LONGARITHEMTIC_H
#define LONGARITHEMTIC_H
#define PRECISION 20

#include <algorithm>
#include <vector>

class InvalidChar : public std::exception {
    public:
    const char* what() const throw() {}
};

class BigDecimal{
    private:
    int _left;
    int _right;
    std::vector<char> _dataLeft;
    std::vector<char> _dataRight;
    BigDecimal expand(int x, int y) const;
    void Convert(std::string &s1, std::string &s2, int n);
    
    std::string divideByTwo(const std::string &number);
    std::string multiplyByTwo(const std::string& num);
    std::string decimalStringToBinary(std::string &number);
    std::string decimalFractionToBinary(const std::string &fraction, int precision);
    
    std::string powerOfTwo(int exponent);
    std::string addBinary(const std::string& num1, const std::string& num2);
    std::string binaryFractionToDecimal(const std::string& fractionalPart);
    std::string binaryIntegerToDecimal(const std::string& integerPart);
    
    public:

    std::string binaryToDecimal(const std::string &binary);
    
    BigDecimal() = delete;
    BigDecimal(int left, int right);
    BigDecimal(const std::string& s, int n);
    BigDecimal(const std::string& s) : BigDecimal(s, PRECISION) {};
    ~BigDecimal() = default;
    BigDecimal(const BigDecimal& other);
    BigDecimal(const std::vector<char> &left, const std::vector<char> &right);
    
    BigDecimal& operator=(const BigDecimal& other);
    BigDecimal operator+(const BigDecimal& other);
    BigDecimal operator-(const BigDecimal& other);
    BigDecimal operator*(const BigDecimal& other);
    BigDecimal operator/(const BigDecimal& other);

    bool operator==(const BigDecimal& other);
    bool operator!=(const BigDecimal& other);
    bool operator<(const BigDecimal& other);
    bool operator>(const BigDecimal& other);
    
    friend std::ostream& operator << (std::ostream &os, const BigDecimal &bd);
};

BigDecimal operator""_longnum(long double number);


#endif //LONGARITHEMTIC_H
