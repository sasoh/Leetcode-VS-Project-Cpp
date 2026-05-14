//  Given a number, your task is to express it in English words exactly as your friend should say it out loud.Yaʻqūb expects to use numbers from 0 up to 999, 999, 999, 999.
//  Examples:
//  0 → zero
//  1 → one
//  12 → twelve
//  123 → one hundred twenty - three
//  1, 234 → one thousand two hundred thirty - four

#include <stdexcept>
#include <string>
#include <iostream>
#include <format>
#include <map>
using namespace std;


namespace say {
    static const std::map<int, std::string> dtw{
        {1, "one"s}, {2, "two"s}, {3, "three"s}, {4, "four"s}, {5, "five"s},
        {6, "six"s}, {7, "seven"s}, {8, "eight"s}, {9, "nine"s},
        {10, "ten"s}, {11, "eleven"s}, {12, "twelve"s}, {13, "thirteen"s}, {14, "fourteen"s},
        {15, "fifteen"s}, {16, "sixteen"s}, {17, "seventeen"s}, {18, "eighteen"s}, {19, "nineteen"s},
        {20, "twenty"s}, {30, "thirty"s}, {40, "forty"s}, {50, "fifty"s}, {60, "sixty"s},
        {70, "seventy"s}, {80, "eighty"s}, {90, "ninety"s},
    };


    std::string digitToWord(int d) {
        std::string r{};
        if (d == 0) return r;

        // hundreds
        int hundreds = d / 100;
        if (hundreds > 0) {
            r.append(dtw.at(hundreds) + " hundred"s);
        }

        // tenths
        int tenths = (d / 10) % 10;
        int singles = d % 10;
        if (tenths > 0) {
            // check for whole two-digit number
            int twoDigits = d % 100;
            if (dtw.find(twoDigits) != dtw.end()) {
                if (r.size() > 0) {
                    r.append(" "s);
                }
                r.append(dtw.at(twoDigits));
            }
            else {
                if (r.size() > 0) {
                    r.append(" "s);
                }
                r.append(dtw.at(tenths * 10) + "-" + dtw.at(singles));
            }
        }
        else {
            if (singles > 0) {
                if (r.size() > 0) {
                    r.append(" "s);
                }
                r.append(dtw.at(singles));
            }
        }

        return r;
    }

    std::string in_english(long long n) {
        if (n > 999'999'999'999) {
            throw std::domain_error("N should be smaller");
        }
        if (n == 0) {
            return "zero"s;
        }

        std::string r{};
        auto p = {
            std::make_pair((n / 1'000'000'000) % 1000, " billion"),
            std::make_pair((n / 1'000'000) % 1000, " million"),
            std::make_pair((n / 1000) % 1000, " thousand"),
            std::make_pair(n % 1000, ""),
        };
        for (const auto& [v, suffix] : p) {
            if (v < 1) continue;
            auto words = digitToWord(v);
            if (r.size() > 0) {
                r.append(" "s);
            }
            r += words + suffix;
        } 

        //int billions = (n / 1'000'000'000) % 1000;
        //if (billions > 0) {
        //    auto words = digitToWord(billions);
        //    r += words + " billion";
        //}
        //int millions = (n / 1'000'000) % 1000;
        //if (millions > 0) {
        //    auto words = digitToWord(millions);
        //    if (r.size() > 0) {
        //        r.append(" "s);
        //    }
        //    r += words + " million";
        //}
        //int thousands = (n / 1000) % 1000;
        //if (thousands > 0) {
        //    auto words = digitToWord(thousands);
        //    if (r.size() > 0) {
        //        r.append(" "s);
        //    }
        //    r += words + " thousand";
        //}
        //int hundreds = n % 1000;
        //if (hundreds > 0) {
        //    auto words = digitToWord(hundreds);
        //    if (r.size() > 0) {
        //        r.append(" "s);
        //    }
        //    r += words;
        //}
        return r;
    }
}  // namespace say

int main() {
    std::cout << std::format("'{}'\n", say::in_english(100));
    //std::cout << say::in_english(14) << std::endl;
    //std::cout << say::in_english(3) << std::endl;
    //std::cout << say::in_english(31) << std::endl;
    //std::cout << say::in_english(99) << std::endl;
    //std::cout << say::in_english(643) << std::endl;
    //std::cout << say::in_english(4'643) << std::endl;
    //std::cout << say::in_english(24'643) << std::endl;
    //std::cout << say::in_english(742'235) << std::endl;
    //std::cout << say::in_english(5'742'235) << std::endl;
    //std::cout << say::in_english(25'742'235) << std::endl;
    //std::cout << say::in_english(725'742'235) << std::endl;
    //std::cout << say::in_english(1'344'674'965) << std::endl;
    //std::cout << say::in_english(21'344'674'965) << std::endl;
    //std::cout << say::in_english(821'344'674'965) << std::endl;
    return 0;
}