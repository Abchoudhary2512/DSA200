#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& index, int bound) {
        if (index == preorder.size() || preorder[index] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left  = build(preorder, index, root->val);
        root->right = build(preorder, index, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MAX);
    }
};

// Inorder traversal to check correctness
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;
}
