#include <iostream>
#include <vector>
#include <format>
#include "Complex.h"
using namespace std;

int main() {
    vector<Complex> c{
        Complex{}, Complex{1, 1}, Complex{2, 4}, Complex{5, 5} 
    };

    //for (const auto& i : c) {
    //    cout << format("{}\n", i.toString());
    //}

    auto c1 = *(c.end() - 1);
    auto c2 = c[1];

    cout << format("{} - {} = ", c1.toString(), c2.toString());
    c1.subtract(c2);
    cout << format("{}\n", c1.toString());

    cout << format("{} + {} = ", c1.toString(), c2.toString());
    c1.add(c2);
    cout << format("{}\n", c1.toString());

    return 0;
}