#include <iostream>
#include <vector>
#include <format>
#include "Square.h"
using namespace std;

int main() {
    vector<Square> squares{
        Square{1}, Square{2}, Square{4}, Square{10}, Square{15}
    };

    for (const auto& s : squares) {
        cout << format(
            "Square with side = {:<4} area = {:<4} perimeter = {:<4} diagonal = {:<4.2f}\n",
            s.getSide(),
            s.getArea(),
            s.getPerimeter(),
            s.getDiagonal()
        );
    }

    return 0;
}