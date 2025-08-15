#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (val == root->val) return root;
        else if (val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};

// Helper function to print the subtree
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Build a sample BST:
    //        4
    //      /   \
    //     2     7
    //    / \
    //   1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    int searchVal = 2;
    TreeNode* result = sol.searchBST(root, searchVal);

    if (result) {
        cout << "Subtree rooted at " << searchVal << ": ";
        printTree(result);
        cout << endl;
    } else {
        cout << "Value " << searchVal << " not found in the BST." << endl;
    }

    // Cleanup memory
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
