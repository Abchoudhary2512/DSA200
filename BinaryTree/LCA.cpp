#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        // If root is one of p or q, return root
        if (root->val == p->val || root->val == q->val) return root;

        // Recurse on left and right subtree
        TreeNode* leftSub = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSub = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null, root is the LCA
        if (leftSub && rightSub) return root;

        // Else return the non-null side
        return leftSub ? leftSub : rightSub;
    }
};

// Example usage
int main() {
    /*
        Tree structure:
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    // Clean up dynamically allocated memory
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
