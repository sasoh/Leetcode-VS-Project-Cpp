#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // find possible starting positions
        vector<int> startingPositions{};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                startingPositions.push_back(i);
            }
        }

        int selections = 0;
        // for each starting position
        for (int i = 0; i < startingPositions.size(); i++) {
            // check going left

            // check going right
            
        }

        return selections;
    }
};

static void test1() {
    vector<int> a{ 1,0,2,0,3 };
    Solution s;
    auto result = s.countValidSelections(a);
    printf("Result = %d\n", result);
}

static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}