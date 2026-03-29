#pragma once
#include <string>

class Complex {
public:
    Complex(double realPart = 0.0, double imaginaryPart = 0.0) : m_realPart{ realPart }, m_imaginaryPart{ imaginaryPart } {};
    double getRealPart() const;
    double getImaginaryPart() const;
    void add(const Complex& another);
    void subtract(const Complex& another);
    std::string toString() const;
private:
    double m_realPart{ 0.0 };
    double m_imaginaryPart{ 0.0 };
};