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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: empty tree has depth 0
        }

        // Recursively find the depth of left and right subtrees
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // Return the greater of the two depths plus one for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};

// Example usage
int main() {
    // Construct the binary tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), nullptr);
    root->right = new TreeNode(3);

    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree is: " << depth << endl;

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
