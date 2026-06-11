#include <format>
#include <string>
#include <set>
#include <map>
#include <initializer_list>
#include <cctype>
#include <algorithm>
#include <iterator>
using namespace std::string_literals;

namespace {
    std::map<char, int> frequency(const std::string& word) {
        std::map<char, int> r{};
        for (const char c : word) {
            r[std::tolower(c)] += 1;
        }
        return r;
    }

    std::string tolower(const std::string& word) {
        std::string r{};
        std::transform(word.begin(), word.end(), std::back_inserter(r), [](const char c) { return std::tolower(c); });
        return r;
    }
}

namespace anagram {
    class anagram {
    public:
        anagram(const std::string& word);
        std::set<std::string> matches(const std::initializer_list<std::string>& list) const;
    private:
        std::string m_word{};
        std::map<char, int> m_frequency{};
    };

    anagram::anagram(const std::string& word) : m_word{ tolower(word) }, m_frequency{ frequency(word) } {}

    std::set<std::string> anagram::matches(const std::initializer_list<std::string>& list) const
    {
        std::set<std::string> r{};
        for (const auto& w : list) {
            if (tolower(w) == m_word) continue;
            auto f = frequency(w);
            if (f != m_frequency) continue;
            r.insert(w);
        }
        return r;
    }

}  // namespace anagram

int main() {
    auto subject = anagram::anagram("solemn");
    auto matches = subject.matches({ "cherry", "melons", "lemons" });
    return 0;
}