#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <map>
#include <format>
#include <vector>
using namespace std::string_literals;

namespace word_count {
    std::string trimmedWord(const std::string& input) {
        if (!std::any_of(input.begin(), input.end(), isalnum)) return ""s; 
    
        std::string word{ input };
        word.erase(std::remove_if(word.begin(), word.end(), isspace), word.end());
        if (word.size() == 0) return word;

        std::vector<size_t> indices{};
        for (size_t i{ 0 }; i < word.size(); ++i) {
            auto c = word[i];

            if (ispunct(c)) {
                if (i == 0 || i == word.size() - 1 || (!isalpha(word[i - 1]) || !isalpha(word[i + 1]))) {
                    indices.push_back(i);
                }                
            }
        }

        std::for_each(indices.rbegin(), indices.rend(), [&](int i) { word.erase(word.begin() + i); });

        for (auto i{word.begin()}; i != word.end(); ++i) {
            *i = std::tolower(*i);
        }

        return word;
    }

    std::map<std::string, int> words(const std::string& input) {
        std::map<std::string, int> r{};
        auto next = input.begin();
        auto last = next;
        while (next != input.end()) {
            last = next;
            next = std::find_if(next + 1, input.end(), [](const char c) { 
                return !isalnum(c) && c != '\'';
            }); 
            if (last == next) {
                break;
            }

            std::string word = trimmedWord({ last, next });
            if (word.size() > 0) {
                r[word]++;
            }
        }

        return r;
    }
}  // namespace word_count


int main() {
    //const std::map<std::string, int> expected{ {"word", 1} };
    //const std::map<std::string, int> expected{ {"Joe can't tell between app, apple and a.", 1} };
    //auto r = word_count::words("Joe can't tell between app, apple and a.");
    //auto r = word_count::words("can't cant,can't");
    auto r = word_count::words("'First: don't laugh. Then: don't cry. You're getting it.'");
    //auto r = word_count::words("");
    //auto r = word_count::words("one,two,three");
    //auto r = word_count::words(",\n,one,\n ,two \n 'three'");
    //auto r = word_count::words("can, can't, 'can't'");
    //REQUIRE(expected == word_count::words("word"));
     return 0;
}