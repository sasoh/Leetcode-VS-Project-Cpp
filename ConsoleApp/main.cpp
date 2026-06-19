#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <ios>
#include <cctype>

namespace hexadecimal {
    static int convert(const std::string& input) {
        int r{};

        int count = static_cast<int>(input.size());
        for (int i = count - 1; i >= 0; --i) {
            auto substring = input.substr(count - i - 1, 1);
            auto c = std::tolower(substring[0]);
            if (c < '0' || c > 'f') return 0;
            int value = std::stoi(input.substr(count - i - 1, 1), nullptr, 16);
            r += value * std::pow(16, i);
        }

        return r;
    }
}  // namespace hexadecimal

int main() {
    //std::cout << std::hex;

    //std::cout << hexadecimal::convert("1") << '\n';
    //std::cout << hexadecimal::convert("c") << '\n';
    //std::cout << hexadecimal::convert("10") << '\n';
    //std::cout << hexadecimal::convert("af") << '\n';
    //std::cout << hexadecimal::convert("100") << '\n';
    //std::cout << hexadecimal::convert("19ace") << '\n';
    std::cout << hexadecimal::convert("carrot") << '\n';
    return 0;
}