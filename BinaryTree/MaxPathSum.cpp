
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
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
    int maxi;

    int solve(TreeNode* root) {
        if (!root) return 0;

        // Recursively compute left and right path sums, ignoring negatives
        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        // Path through the current root node
        int curr_path_sum = l + r + root->val;

        // Update global maximum
        maxi = max(maxi, curr_path_sum);

        // Return maximum one-side path sum including current root
        return max(l, r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        solve(root);
        return maxi;
    }
};

// Sample usage
int main() {
    /*
        Tree:
             -10
             /  \
            9   20
               /  \
              15   7
        Maximum Path Sum = 15 + 20 + 7 = 42
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    // Cleanup
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
