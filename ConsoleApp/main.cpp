#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <utility>
#include <deque>
using std::cout;
using std::endl;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int maxDepth(TreeNode* root) {
        // dfs
        int max{ 0 };
        std::deque<std::pair<TreeNode*, int>> possible{ {root, 1} };
        while (possible.size() > 0) {
            auto [current, level] = possible.front();
            possible.pop_front();
            if (level > max) {
                max = level;
            }

            if (current->left != nullptr) {
                // +1 depth from level
                possible.push_back({ current->left, level + 1 });
            }
            if (current->right != nullptr) {
                // +1 depth from level
                possible.push_back({ current->right, level + 1 });
            }
        }

        return max;
    }
};

void t1() {
    //  Input: root = [3, 9, 20, null, null, 15, 7]
    TreeNode n3(3);
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);
    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;
    
    Solution s;
    int d = s.maxDepth(&n3);

    //  Output : 3
    cout << d << " expected to be " << 3 << endl;
}

void t2() {
    //  Input : root = [1, null, 2]
    TreeNode n1(1);
    TreeNode n2(2);
    n1.right = &n2;

    Solution s;
    int d = s.maxDepth(&n1);

    //  Output : 2
    cout << d << " expected to be " << 2 << endl;
}

int main() {
    t1();
    t2();
    return 0;
}