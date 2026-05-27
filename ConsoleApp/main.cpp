#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <utility>
#include <deque>
#include <format>
#include <numeric>
using std::cout;
using std::endl;
using std::format;

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
    int minDepth(TreeNode* root) {
        int min{ 0 };
        if (root == nullptr) return min;

        int init{ 999999 };
        min = init;

        std::deque<std::pair<TreeNode*, int>> possible{ {root, 1} };
        while (possible.size() > 0) {
            auto [current, level] = possible.front();
            possible.pop_front();

            if (current->left != nullptr) {
                possible.push_back({ current->left, level + 1 });
            }
            if (current->right != nullptr) {
                possible.push_back({ current->right, level + 1 });
            }
            if (current->left == nullptr && current->right == nullptr) {
                if (min > level) {
                    min = level;
                }
            }
        }
        if (min == init) return 0;

        return min;
    }
};

int main() {
    return 0;
}