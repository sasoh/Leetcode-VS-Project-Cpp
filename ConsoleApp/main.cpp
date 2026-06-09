#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <map>
#include <format>
#include <vector>
#include <stdexcept>
#include <locale>
#include <cmath>
#include <iomanip>
#include <ios>
#include <stack>
using namespace std::string_literals;

namespace {
    bool isBracket(char c) {
        return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
    }

    bool isClosing(char o, char c) {
        return  (o == '(' && c == ')') || (o == '[' && c == ']') || (o == '{' && c == '}');
    }
}

namespace matching_brackets {    
    bool check(const std::string& input) {
        // find brackets & put in stack
        std::stack<char> brackets{};

        for (auto i{ input.begin() }; i != input.end(); ++i) {
            char current = *i;
            if (!isBracket(current)) continue;
            // if anything in stack, check for match
            if (!brackets.empty()) {
                auto top = brackets.top();
                if (isClosing(top, current)) {
                    brackets.pop();
                    continue;
                }
            }
            brackets.push(current);
        }

        return brackets.empty();
    }
}  // namespace matching_brackets

int main() {
    std::cout << std::boolalpha;
    std::cout << matching_brackets::check("");
    std::cout << matching_brackets::check("[]");
    std::cout << !matching_brackets::check("}{");
    std::cout << !matching_brackets::check("[[");
    std::cout << !matching_brackets::check("{]");
    std::cout << matching_brackets::check("{ }");
    std::cout << !matching_brackets::check("{[])");
    std::cout << matching_brackets::check("{}[]");
    std::cout << matching_brackets::check("([{}({}[])])");
    std::cout << !matching_brackets::check("{[)][]}");
    std::cout << !matching_brackets::check("([{])");
    std::cout << !matching_brackets::check("[({]})");
    std::cout << !matching_brackets::check("[({}])");
    return 0;
}