#include <format>
#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std::string_literals;

namespace roman_numerals {
    std::string convert(int number)
    {

        int thousands = number / 1000;
        int hundreds = (number % 1000) / 100;
        int tens = (number % 100) / 10;
        int singles = number % 10;
        std::cout << std::format("{}, {}, {}, {}\n", thousands, hundreds, tens, singles);

        std::string r{};
        for (size_t i{ 0 }; i < thousands; ++i) {
            r += "M";
        }

        if (hundreds > 3) {
            if (hundreds < 5) {
                r += "CD";
            }
            else {
                if (hundreds == 5) {
                    r += "D";
                }
                else {
                    int d = hundreds - 5;
                    if (d < 4) {
                        r += "D";
                        for (size_t i{ 0 }; i < d; ++i) {
                            r += "C";
                        }
                    }
                    else {
                        for (size_t i{ 0 }; i < 5 - d; ++i) {
                            r += "C";
                        }
                        r += "M";
                    }
                }
            }
        }
        else {
            for (size_t i{ 0 }; i < hundreds; ++i) {
                r += "C";
            }
        }

        if (tens > 3) {
            if (tens < 5) {
                r += "XL";
            }
            else {
                if (tens == 5) {
                    r += "L";
                }
                else {
                    int d = tens - 5;
                    if (d < 4) {
                        r += "L";
                        for (size_t i{ 0 }; i < d; ++i) {
                            r += "X";
                        }
                    }
                    else {
                        for (size_t i{ 0 }; i < 5 - d; ++i) {
                            r += "X";
                        }
                        r += "C";
                    }
                }
            }
        }
        else {
            for (size_t i{ 0 }; i < tens; ++i) {
                r += "X";
            }
        }

        if (singles > 3) {
            if (singles < 5) {
                r += "IV";
            }
            else {
                if (singles == 5) {
                    r += "V";
                }
                else {
                    int d = singles - 5;
                    if (d < 4) {
                        r += "V";
                        for (size_t i{ 0 }; i < d; ++i) {
                            r += "I";
                        }
                    }
                    else {
                        for (size_t i{ 0 }; i < 5 - d; ++i) {
                            r += "I";
                        }
                        r += "X";
                    }
                }
            }
        }
        else {
            for (size_t i{ 0 }; i < singles; ++i) {
                r += "I";
            }
        }

        std::cout << std::format("{} -> {}\n", number, r);
        return r;
    }
}  // namespace roman_numerals

int main() {
    //roman_numerals::convert(3485); // MMMCDLXXXV
    //roman_numerals::convert(485); // CDLXXXV
    //roman_numerals::convert(1);
    //roman_numerals::convert(2);
    //roman_numerals::convert(3);
    //roman_numerals::convert(4);
    //roman_numerals::convert(5);
    //roman_numerals::convert(6);
    //roman_numerals::convert(7);
    //roman_numerals::convert(8);
    //roman_numerals::convert(9);
    //roman_numerals::convert(10);
    roman_numerals::convert(300);
    roman_numerals::convert(405);
    roman_numerals::convert(525);
    roman_numerals::convert(725);
    roman_numerals::convert(925);
    return 0;
}