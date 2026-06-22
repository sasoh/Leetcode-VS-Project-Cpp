#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <format>
#include <map>
#include <string>
#include <cctype>

namespace scrabble_score {
    static std::map<char, int> scores{
        {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'L', 1}, {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1},
        {'D', 2}, {'G', 2},
        {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
        {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
        {'K', 5},
        {'J', 8}, {'X', 8},
        {'Q', 10}, {'Z', 10}
    };

    int score(const std::string& input) {
        int r{};
        for (const auto& c : input) {
            auto cu = std::toupper(c);
            r += scores[cu];
        }
        return r;
    }
}  // namespace scrabble_score

int main() {
    return 0;
}