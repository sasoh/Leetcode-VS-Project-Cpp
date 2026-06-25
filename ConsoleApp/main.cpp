#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <algorithm>

namespace isbn_verifier {
    //isbn_verifier::is_valid("3-598-21508-8"));
    bool is_valid(const std::string& input) {
        std::vector<int> digits{};
        for (const auto& c : input) {
            if (!isdigit(c)) {
                if (c != '-') return false;
                continue;
            }
            digits.push_back(c - '0');
        }

        if (digits.size() == 9 && input[input.size() - 1] == 'X') {
            digits.push_back(10);
        }

        if (digits.size() != 10) return false;
        int sum{};
        for (int i = 1, limit = digits.size(); i <= limit; ++i) {
            sum += digits[limit - i] * i;
        }
        return (sum % 11 == 0);
    }

}  // namespace isbn_verifier


int main() {
    std::cout << std::format("{}\n", isbn_verifier::is_valid("3-598-21508-8"));
    std::cout << std::format("{}\n", isbn_verifier::is_valid("3-598-21508-9"));
    std::cout << std::format("{}\n", isbn_verifier::is_valid("3598P215088"));
    return 0;
}