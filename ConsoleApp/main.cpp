#include <iostream>
#include <span>
#include <array>
#include <vector>
using namespace std;

//void spanCArrayFunction(int a[]) {
//    span<int, 4> b{a};
//}

void spanArrayFunction(array<int, 4> a) {
    span<int, 4> b{ a };
}

std::string smash(const vector<string>& words)
{
    string sentence{};
    for (auto i{ 0 }; i < words.size(); ++i) {
        sentence.append(words[i]);
        if (i < words.size() - 1) {
            sentence.append(" ");
        }
    }
    return sentence;
}

int main() {
    //int a[]{ 1, 2, 4, 6 };
    //span<int> b{a};

    array<int, 4> a{ 1, 2, 5, 12 };
    span<int> b{a};

    cout << b[2] << '\n';
    
    return 0;
}