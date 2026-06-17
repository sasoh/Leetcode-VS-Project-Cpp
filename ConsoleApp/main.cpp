#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cctype>

namespace binary {
    int convert(const std::string& input) {
        for (auto i{input.begin()}; i != input.end(); ++i) {
            if (!isdigit(*i)) return false;
        }

        int number{};
        int size = static_cast<int>(input.size());
        for (int i{ size - 1 }; i >= 0; --i) {
            auto c = input.substr(i, 1);
            auto p = std::pow(2, size - i - 1);
            auto d = std::stoi(c, nullptr);
            number += p * d;
        }

        return number;
    }
}  // namespace binary


int main() {
    std::cout << binary::convert("10") << '\n';
    std::cout << binary::convert("110a") << '\n';
    return 0;
}