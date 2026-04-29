#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//  Input
//  Line 1: the width L of a letter represented in ASCII art.All letters are the same width.
//  Line 2 : the height H of a letter represented in ASCII art.All letters are the same height.
//  Line 3 : The line of text T, composed of N ASCII characters.
//
//  Following lines : the string of characters ABCDEFGHIJKLMNOPQRSTUVWXYZ? Represented in ASCII art.
//
//  Output
//  The text T in ASCII art.
//  The characters a to z are shown in ASCII art by their equivalent in upper case.
//  The characters that are not in the intervals [a - z] or [A - Z] will be shown as a question mark in ASCII art.
//
//  Constraints
//  0 < L < 30
//  0 < H < 30
//  0 < N < 200

int main()
{
    int l{ 4 };
    int h{ 5 };
    string t{ "exp@" };

    vector<string> asciiLetters{
        " #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### "s,
        "# # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   # "s,
        "### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ## "s,
        "# # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #       "s,
        "# # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #  "s
    };

    using Letter = vector<string>;
    string possibleCharacters{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ?" };
    map<char, Letter> letters{};
    for (int i{ 0 }; i < possibleCharacters.size(); ++i) {
        Letter currentLetter(h, {});
        int offsetH{ i * l };
        for (int m{ 0 }; m < h; ++m) {
            for (int n{ 0 }; n < l; ++n) {
                currentLetter[m].push_back(asciiLetters[m][n + offsetH]);
            }
        }
        letters.insert({ toupper(possibleCharacters[i]), currentLetter });
    }

    for (int i{ 0 }; i < h; ++i) {
        string line{};
        for (int j{ 0 }; j < t.size(); ++j) {
            auto character = toupper(t[j]);
            if (possibleCharacters.find(character) == string::npos) {
                character = '?';
            }
            auto letter = letters[character];
            line.append(letter[i]);
        }
        cout << line << endl;
    }
}