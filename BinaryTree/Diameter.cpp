#include <iostream>
#include <algorithm> // for std::max

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
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        // Update max diameter (number of edges in the longest path)
        maxDiameter = max(maxDiameter, lh + rh);

        return max(lh, rh) + 1; // Return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // This will update maxDiameter
        return maxDiameter;
    }
};

// Example usage
int main() {
    // Construct the binary tree:
    //        1
    //       / \
    //      2   3
    //     / \     
    //    4   5    

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
