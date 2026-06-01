#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <vector>
using std::cout;
using std::endl;
using namespace std::string_literals;

namespace complex_numbers {
    class Complex {
    public:
        Complex(double real, double imag);
        bool operator=(const Complex& rhs) const;
        double real() const;
        double imag() const;
        Complex conj() const;
        double abs() const;
        Complex exp() const;
        friend Complex operator+(const Complex& lhs, const Complex& rhs);
        friend Complex operator+(const Complex& lhs, double rhs);
        friend Complex operator+(double lhs, const Complex& rhs);
        friend Complex operator-(const Complex& lhs, const Complex& rhs);
        friend Complex operator-(const Complex& lhs, double rhs);
        friend Complex operator-(double lhs, const Complex& rhs);
        friend Complex operator*(const Complex& lhs, const Complex& rhs);
        friend Complex operator*(const Complex& lhs, double rhs);
        friend Complex operator*(double lhs, const Complex& rhs);
        friend Complex operator/(const Complex& lhs, const Complex& rhs);
        friend Complex operator/(const Complex& lhs, double rhs);
        friend Complex operator/(double lhs, const Complex& rhs);
    private:
        double m_real{};
        double m_imag{};
    };

    Complex::Complex(double real, double imag) : m_real{ real }, m_imag{ imag } {}
    double Complex::real() const
    {
        return m_real;
    }
    double Complex::imag() const
    {
        return m_imag;
    }
    Complex Complex::conj() const
    {
        return { m_real, -m_imag };
    }
    double Complex::abs() const
    {
        return std::sqrt(m_real * m_real + m_imag * m_imag);
    }
    Complex Complex::exp() const
    {
        //e ^ (a + b * i) = e ^ a * e ^ (b * i)
        //    = e ^ a * (cos(b) + i * sin(b))
        auto ea = std::exp(m_real);
        return Complex{
            ea * std::cos(m_imag),
            ea * std::sin(m_imag)
        };
    }
    Complex operator+(const Complex& lhs, const Complex& rhs)
    {
        return { lhs.m_real + rhs.m_real, lhs.m_imag + rhs.m_imag };
    }
    Complex operator+(const Complex& lhs, double rhs)
    {
        return lhs + Complex{ rhs, 0 };
    }
    Complex operator+(double lhs, const Complex& rhs)
    {
        return operator+(rhs, lhs);
    }
    Complex operator-(const Complex& lhs, const Complex& rhs)
    {
        return { lhs.m_real - rhs.m_real, lhs.m_imag - rhs.m_imag };
    }
    Complex operator-(const Complex& lhs, double rhs)
    {
        return lhs - Complex{ rhs, 0 };
    }
    Complex operator-(double lhs, const Complex& rhs)
    {
        return Complex{ lhs, 0 } - rhs;
    }
    Complex operator*(const Complex& lhs, const Complex& rhs)
    {
        //z1* z2 = (a + b * i) * (c + d * i)
        //    = (a * c - b * d) + (b * c + a * d) * i
        return {
            lhs.m_real * rhs.m_real - lhs.m_imag * rhs.m_imag,
            lhs.m_imag * rhs.m_real + lhs.m_real * rhs.m_imag
        };
    }
    Complex operator*(const Complex& lhs, double rhs)
    {
        return lhs * Complex{ rhs, 0 };
    }
    Complex operator*(double lhs, const Complex& rhs)
    {
        return Complex{ lhs, 0 } * rhs;
    }
    Complex operator/(const Complex& lhs, const Complex& rhs)
    {
        //z1 / z2 = z1 * (1 / z2)
        //    = (a + b * i) / (c + d * i)
        //    = (a * c + b * d) / (c ^ 2 + d ^ 2) + (b * c - a * d) / (c ^ 2 + d ^ 2) * i
        return {
            (lhs.m_real * rhs.m_real + lhs.m_imag * rhs.m_imag) / (rhs.m_real * rhs.m_real + rhs.m_imag * rhs.m_imag),
            (lhs.m_imag * rhs.m_real - lhs.m_real * rhs.m_imag) / (rhs.m_real * rhs.m_real + rhs.m_imag * rhs.m_imag)
        };
    }
    Complex operator/(const Complex& lhs, double rhs)
    {
        return { lhs.m_real / rhs, lhs.m_imag / rhs };
    }
    Complex operator/(double lhs, const Complex& rhs)
    {
        return Complex{ lhs, 0 } / rhs;
    }
}  // namespace complex_numbers


int main() {
    return 0;
}