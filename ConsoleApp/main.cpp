#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    int linearElementAt(int index, vector<vector<int>>& matrix) {
        if (matrix.size() == 1) {
            return matrix[0][index];
        }
        auto columnCount = matrix.back().size();
        if (columnCount == 1) {
            return matrix[index][0];
        }
        auto i = index / columnCount;
        auto j = index % columnCount;
        return matrix[i][j];
    }
    int linearSize(vector<vector<int>>& matrix) {
        auto rowCount = matrix.size();
        auto columnCount = matrix.back().size();
        return rowCount * columnCount;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        printf("Matrix is %dx%d\n", matrix.size(), matrix[0].size());

        // binary search in flattened matrix
        auto start = 0;
        auto end = linearSize(matrix);

        while (start < end) {
            auto middle = (start + end) / 2;
            auto middleElement = linearElementAt(middle, matrix);
            if (middleElement == target) {
                return true;
            }
            if (middleElement < target) {
                start = middle + 1;    
            }
            else {
                end = middle;
            }
        }

        return false;
    }
};

static void test1() {
    vector<vector<int>> m{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    auto t = 3;

    Solution s;
    cout << "Test result = " << s.searchMatrix(m, t) << endl;
}

static void test2() {
    vector<vector<int>> m{
        {1},
    };
    auto t = 0;

    Solution s;
    cout << "Test result = " << s.searchMatrix(m, t) << endl;
}

static void test3() {
    vector<vector<int>> m{
        {1},
        {3}
    };
    auto t = 0;

    Solution s;
    cout << "Test result = " << s.searchMatrix(m, t) << endl;
}

static void test4() {
    vector<vector<int>> m{
        {1, 3, 5}
    };
    auto t = 0;

    Solution s;
    cout << "Test result = " << s.searchMatrix(m, t) << endl;
}

static void test5() {
    vector<vector<int>> m{
        {1, 1},
        {2, 2}
    };
    auto t = 0;

    Solution s;
    cout << "Test result = " << s.searchMatrix(m, t) << endl;
}

static void test6() {
    vector<vector<int>> m{
        { 1, 3, 5, 7 },
        { 10,11,16,20 },
        { 23,30,34,60 }
    };
    auto t = 0;

    Solution s;
    cout << "Test result = " << s.searchMatrix(m, t) << endl;
}

static void runTests() {
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
}

int main() {
    runTests();
    return 0;
}