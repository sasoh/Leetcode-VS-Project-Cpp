#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <format>
using namespace std;

static vector<string> split(const string& s) {
    auto r = vector<string>{};
    auto inputCopy{ s };
    constexpr auto delimiter = ' ';
    size_t pos = 0;
    while ((pos = inputCopy.find(delimiter)) != string::npos) {
        r.emplace_back(inputCopy.substr(0, pos));
        inputCopy.erase(0, pos + 1); // + 1 for the delimiter
    }
    r.push_back(inputCopy);
    return r;
}

int main() {
    string input = "this is sample text with several words this is more sample text with some different words";
    auto s = split(input);
    auto m = map<string, int>{};
    for (const auto& w : s) {
        m[w] += 1;
    }

    cout << format("{:<15}{:<10}\n", "WORD", "COUNT");
    for (const auto& p : m) {
        cout << format("{:<15}{:<10}\n", p.first, p.second);
    }
    cout << format("Number of unique words: {}\n", m.size());

    return 0;
}