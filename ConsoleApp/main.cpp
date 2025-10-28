#include <iostream>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        
        auto weeks = n / 7 + 1;
        for (size_t i = 0; i < weeks; i++) {
            int mondayAmount = i + 1;
            if (i == weeks - 1) {
                // not full week
                auto days = n % 7;
                for (size_t j = 0; j < days; j++) {
                    total += mondayAmount + j;
                }
            }
            else {
                for (size_t j = 0; j < 7; j++) {
                    total += mondayAmount + j;
                }
            }
        }

        return total;
    }
};

static void test1() {
    constexpr auto n = 10;
    Solution s;
    cout << "For " << n << " days you get " << s.totalMoney(n) << endl;
}

static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}