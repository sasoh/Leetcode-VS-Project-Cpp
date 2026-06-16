#include <algorithm>
#include <cctype>
#include <format>
#include <string>

namespace acronym {
    //acronym::acronym("Portable Network Graphics")
    std::string acronym(const std::string& input) {
        // Punctuation is handled as follows: hyphens are word separators(like whitespace); 
        // all other punctuation can be removed from the input.

        std::string temp{ input };
        for (size_t i{ 0 }, limit = temp.size(); i < limit; ++i) {
            if (temp[i] == '-') {
                temp[i] = ' ';
            }
        }
        temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());

        // trimmed & ready for abbreviation
        // first + every other after a space
        std::string r{};

        bool shouldIncludeNext{ false };
        for (size_t i{ 0 }, limit = temp.size(); i < limit; ++i) {
            auto &c = temp[i];
            if (i == 0 || shouldIncludeNext) {
                if (isspace(c)) continue;
                shouldIncludeNext = false;
                r.push_back(std::toupper(c));
            }
            if (isspace(c)) {
                shouldIncludeNext = true;
            }
        }

        return r;
    }
}  // namespace acronym

int main() {
    const std::string actual = acronym::acronym("Portable Network Graphics");

    return 0;
}