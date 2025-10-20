#include <iostream>
#include <vector>

using namespace std;

static void print(const vector<int>& list) {
    cout << "[";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    vector<int> mergeSorted(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged{};
        int i1 = 0;
        int i2 = 0;
        for (int i = 0; i < nums1.size() + nums2.size(); i++) {
            int num1 = i1 < nums1.size() ? nums1[i1] : INT_MAX;
            int num2 = i2 < nums2.size() ? nums2[i2] : INT_MAX;
            if (num1 < num2) {
                merged.push_back(num1);
                i1++;
            }
            else {
                merged.push_back(num2);
                i2++;
            }
        }

        return merged;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;

        // merge arrays in a sorted way
        vector<int> merged = mergeSorted(nums1, nums2);
        if (merged.size() == 0) return 0.0;

        // get median
        int count = merged.size();
        int middle = count / 2;
        if (count % 2 == 0) {
            median = (double)(merged[middle] + merged[middle - 1]) / 2;
        }
        else {
            median = (double)merged[middle];
        }

        return median;
    }
};

static void test1() {
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    Solution s;
    double median = s.findMedianSortedArrays(nums1, nums2);
    cout << "Median for both = " << median << endl;
    printf("end\n");
}

static void test2() {
    vector<int> nums1{ 2, 2, 4, 4 };
    vector<int> nums2{ 2, 2, 2, 4, 4 };
    Solution s;
    double median = s.findMedianSortedArrays(nums1, nums2);
    cout << "Median for both = " << median << endl;
    printf("end\n");
}

static void runTests() {
    test1();
    test2();
}

int main() {
    runTests();
    return 0;
}