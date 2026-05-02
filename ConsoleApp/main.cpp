#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return { root->val };
        }
        
        vector<int> result{};

        if (root->left != nullptr) {
            auto left = inorderTraversal(root->left);
            result.insert(result.cend(), left.cbegin(), left.cend());
        }

        result.push_back(root->val);

        if (root->right != nullptr) {
            auto right = inorderTraversal(root->right);
            result.insert(result.cend(), right.cbegin(), right.cend());
        }

        return result;
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    n1.right = &n2;
    TreeNode n3(3);
    n2.left = &n3;

    Solution s;
    auto v = s.inorderTraversal(&n1);
    ostream_iterator<int> out{ cout, " " };
    std::copy(v.cbegin(), v.cend(), out);

    return 0;
}