#include <algorithm>
#include <cctype>
#include <map>
#include <string>

namespace isogram {
    bool is_isogram(const std::string& input) {
        std::string temp{ input };
        temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());
        temp.erase(std::remove_if(temp.begin(), temp.end(), isspace), temp.end());

        std::map<char, int> frequency{};
        for (auto c : temp) {
            auto cl = std::tolower(c);
            frequency[cl]++;
            if (frequency[cl] > 1) return false;
        }

        return true;
    }
}  // namespace isogram

int main() {
    const bool actual = isogram::is_isogram("");
    return 0;
}