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

namespace {
    const std::map<int, std::string> dtw{
        {1, "one"s}, {2, "two"s}, {3, "three"s}, {4, "four"s}, {5, "five"s}, {6, "six"s},
        {7, "seven"s}, {8, "eight"s}, {9, "nine"s}, {10, "ten"s}, {11, "eleven"s}, {12, "twelve"s},
        {13, "thirteen"s}, {14, "fourteen"s}, {15, "fifteen"s}, {16, "sixteen"s}, {17, "seventeen"s},
        {18, "eighteen"s}, {19, "nineteen"s}, {20, "twenty"s}, {30, "thirty"s}, {40, "forty"s},
        {50, "fifty"s}, {60, "sixty"s}, {70, "seventy"s}, {80, "eighty"s}, {90, "ninety"s},
    };

    void prependSpaceAppend(std::string& target, const std::string& addition) {
        if (target.size() > 0) {
            target.append(" "s);
        }
        target.append(addition);
    }

    std::string threeDigitsToWords(int d) {
        std::string r{};
        if (d == 0) return r;

        int hundreds = d / 100;
        if (hundreds > 0) {
            r.append(dtw.at(hundreds) + " hundred"s);
        }

        int tenths = (d / 10) % 10;
        int singles = d % 10;
        if (tenths > 0) {
            int twoDigits = d % 100;
            if (auto it = dtw.find(twoDigits); it != dtw.end()) {
                prependSpaceAppend(r, it->second);
            }
            else {
                prependSpaceAppend(r, dtw.at(tenths * 10) + "-"s + dtw.at(singles));
            }
        }
        else {
            if (singles > 0) {
                prependSpaceAppend(r, dtw.at(singles));
            }
        }

        return r;
    }
}

namespace say {
    std::string in_english(long long n) {
        if (n < 0 || n > 999'999'999'999) {
            throw std::domain_error("n is not in domain");
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
            auto words = threeDigitsToWords(v);
            prependSpaceAppend(r, words + suffix);
        } 

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