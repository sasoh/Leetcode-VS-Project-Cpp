// The Atbash cipher is a simple substitution cipher that relies on transposing 
// all the letters in the alphabet such that the resulting alphabet is backwards.
// The first letter is replaced with the last letter, the second with the second - last, and so on.
// Ciphertext is written out in groups of fixed length, the traditional group size being 5 letters, 
// leaving numbers unchanged, and punctuation is excluded. This is to make it harder to guess things 
// based on word boundaries. All text will be encoded as lowercase letters.

#include <iostream>
#include <format>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cmath>
using std::format;
using std::cout;
using std::endl;
using namespace std::string_literals;

namespace atbash_cipher {
    namespace {
        char flipAlphabeticChar(char c) {
            return static_cast<char>('z' - std::abs(std::tolower(c) - 'a'));
        }
    }

    std::string encode(const std::string& input) {
        auto trimmed{ input };
        trimmed.erase(remove_if(trimmed.begin(), trimmed.end(), isspace), trimmed.end());
        trimmed.erase(remove_if(trimmed.begin(), trimmed.end(), ispunct), trimmed.end());
        std::stringstream r{};
        size_t totalLength = trimmed.size();
        for (size_t i{ 0 }; i < totalLength; i += 5) {
            for (size_t j{ i }; j < i + 5 && j < totalLength; j++) {
                auto currentCharacter = trimmed[j];
                if (isdigit(currentCharacter)) {
                    r << currentCharacter;
                }
                else {
                    r << flipAlphabeticChar(currentCharacter);
                }
            }
            if (i + 5 < totalLength) {
                r << " ";
            }
        }

        return r.str();
    }
    std::string decode(const std::string& input) {
        std::stringstream r{};
        auto trimmed{ input };
        trimmed.erase(remove_if(trimmed.begin(), trimmed.end(), isspace), trimmed.end());

        for (auto c: trimmed) {
            r << (isdigit(c) ? c : flipAlphabeticChar(c));
        }

        return r.str();
    }
}  // namespace atbash_cipher

int main() {
    // Encoding test gives gvhg
    // Encoding x123 yes gives c123b vh
    // Decoding gvhg gives test
    // Decoding gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt gives thequickbrownfoxjumpsoverthelazydog
    //cout << atbash_cipher::encode("test");
    //cout << atbash_cipher::encode("x123 yes");
    cout << atbash_cipher::decode("gvhg");
    //cout << atbash_cipher::encode("test1 test2 test3 te");
    //cout << atbash_cipher::encode("gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt");
    return 0;
}