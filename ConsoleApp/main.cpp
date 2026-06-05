#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <string>
using namespace std::string_literals;

namespace bob {
    static bool IsQuestion(const std::string& i) {
        constexpr char kQuestion = '?';
        return i.back() == kQuestion;
    }

    static bool IsShouting(const std::string& i) {
        bool hasLowercaseLetters{ false };
        bool hasCapitalLetters{ false };
        bool hasLetters{ false };
        for (auto c : i) {
            if (!isalpha(c)) continue;
            hasLowercaseLetters = hasLowercaseLetters || islower(c);
            hasCapitalLetters = hasCapitalLetters || isupper(c);
        }
        return hasCapitalLetters && !hasLowercaseLetters;
    }

    static bool IsNothing(const std::string& i) {
        return i.size() == 0;
    }

    std::string hey(const std::string& i)
    {
        std::string trimmed{ i };
        trimmed.erase(std::remove_if(trimmed.begin(), trimmed.end(), isspace), trimmed.end());
        if (IsNothing(trimmed)) {
            return "Fine. Be that way!"s;
        }
        if (IsShouting(trimmed)) {
            if (IsQuestion(trimmed)) {
                return "Calm down, I know what I'm doing!"s;
            }
            return "Whoa, chill out!"s;
        }
        if (IsQuestion(trimmed)) {
            return "Sure."s;
        }
        return "Whatever."s;
    }
}  // namespace bob

int main() {
    //std::cout << std::format("{}\n", bob::hey("FCECDFCAAB"));
    //std::cout << std::format("{}\n", bob::hey("Tom - ay - to, tom - aaaah - to."));
    std::cout << std::format("{}\n", bob::hey("Does this cryogenic chamber make me look fat?"));
    std::cout << std::format("{}\n", bob::hey("WHAT THE HELL WERE YOU THINKING?"));
    std::cout << std::format("{}\n", bob::hey("WHAT THE HELL WERE YOU THINKING? "));
    std::cout << std::format("{}\n", bob::hey("1, 2, 3 GO!"));
    std::cout << std::format("{}\n", bob::hey("1, 2, 3"));
    std::cout << std::format("{}\n", bob::hey(""));
    std::cout << std::format("{}\n", bob::hey("    "));
    return 0;
}