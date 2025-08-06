#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function that returns height if balanced, else -1
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = checkHeight(root->left);
        if (lh == -1) return -1;

        int rh = checkHeight(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

// Example usage
int main() {
    /*
        Constructing the following tree:
              1
             / \
            2   3
           / \
          4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution solution;
    if (solution.isBalanced(root)) {
        cout << "The binary tree is height-balanced." << endl;
    } else {
        cout << "The binary tree is NOT height-balanced." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
