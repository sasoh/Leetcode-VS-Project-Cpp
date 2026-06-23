#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <format>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

namespace all_your_base {
    std::vector<unsigned int> convert(int inBase, std::vector<unsigned int> digits, int outBase) {
        if (inBase < 2 || outBase < 2) throw std::invalid_argument("Base can't be less than 2");

        std::vector<unsigned int> r{};
        int base10{};
        std::string digitsString{};
        for (size_t i{ 0 }; i < digits.size(); ++i) {
            auto d = digits[digits.size() - 1 - i];
            if (d >= inBase) throw std::invalid_argument("Invalid digit argument");
            digitsString.insert(digitsString.begin(), std::to_string(d)[0]);
            base10 += d * std::pow(inBase, i);
        }

        int base10copy{ base10 };
        int n = base10copy % outBase;
        while (base10copy > 0) {
            r.push_back(n);
            base10copy /= outBase;
            n = base10copy % outBase;
        }
        std::reverse(r.begin(), r.end());
        return r;
    }
}  // namespace all_your_base

int main() {
    std::vector<unsigned int> in_digits{ 1, 1, 0 };
    std::vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 2);
    return 0;
}