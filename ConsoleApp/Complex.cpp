#include "Complex.h"
#include <format>
#include <string>

double Complex::getRealPart() const
{
    return m_realPart;
}

double Complex::getImaginaryPart() const
{
    return m_imaginaryPart;
}

void Complex::add(const Complex& another) {
    m_realPart += another.getRealPart();
    m_imaginaryPart += another.getImaginaryPart();
}

void Complex::subtract(const Complex& another)
{
    m_realPart -= another.getRealPart();
    m_imaginaryPart -= another.getImaginaryPart();
}

std::string Complex::toString() const
{
    return std::string{ std::format("({}, {})", m_realPart, m_imaginaryPart) };
}