#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> increased{};

        int carryOver = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int value = digits[i];
            if (i == digits.size() - 1) {
                value++;
            }
            value += carryOver;
            carryOver = 0;
            if (value >= 10) {
                value -= 10;
                carryOver = 1;
            }
            increased.insert(std::begin(increased), value);
        }

        if (carryOver == 1) {
            increased.insert(std::begin(increased), 1);
        }

        return increased;
    }
};

static void print(vector<int> digits) {
    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i] << " ";
    }
    cout << endl;
}

static void test1() {
    Solution s;
    vector<int> digits{1, 2, 3};
    print(digits);
    cout << "increasing...\n"; 
    auto increased = s.plusOne(digits);
    print(increased);
}

static void test2() {
    Solution s;
    vector<int> digits{ 9 };
    print(digits);
    cout << "increasing...\n";
    auto increased = s.plusOne(digits);
    print(increased);
}

static void runTests() {
    test1(); 
    test2();
}

int main() {
    runTests();
    return 0;
}