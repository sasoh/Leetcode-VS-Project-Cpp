#include <iostream>
#include <vector>

using namespace std;

class Solution {
    size_t findRotation(vector<int>& nums) {
        int least = INT_MAX;
        int leastIndex = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < least) {
                least = nums[i];
                leastIndex = i;
            }
        }

        return leastIndex;
    }

    size_t rotatedIndex(size_t i, int offset, size_t size) {
        return (i + offset) % size;
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) return 0;
        size_t offset = findRotation(nums);

        size_t first = 0;
        size_t last = nums.size() - 1;
        while (first < last) {
            size_t firstRotated = rotatedIndex(first, offset, nums.size());
            if (nums[firstRotated] == target) {
                return static_cast<int>(firstRotated);
            }
            size_t lastRotated = rotatedIndex(last, offset, nums.size());
            if (nums[lastRotated] == target) {
                return static_cast<int>(lastRotated);
            }
            size_t middle = (first + last) / 2;
            size_t middleRotated = rotatedIndex(middle, offset, nums.size());
            if (nums[middleRotated] == target) {
                return static_cast<int>(middleRotated);
            }
            else if (nums[middleRotated] < target) {
                first = middle + 1;
            }
            else {
                last = middle;
            }
        }

        return -1;
    }
};

static void test1() {
    vector<int> nums{ 4, 5, 6, 7, 0, 1, 2 };
    int target = 1;
    Solution s;
    cout << "Result = " << s.search(nums, target) << endl;
}

static void test2() {
    vector<int> nums{ 3, 5, 1 };
    int target = 3;
    Solution s;
    cout << "Result = " << s.search(nums, target) << endl;
}


static void runTests() {
    test1();
    //test2();
}

int main() {
    runTests();
    return 0;
}