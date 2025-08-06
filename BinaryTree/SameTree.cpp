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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Example usage
int main() {
    /*
        Tree 1:
            1
           / \
          2   3

        Tree 2:
            1
           / \
          2   3
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    if (solution.isSameTree(p, q)) {
        cout << "Both trees are the same." << endl;
    } else {
        cout << "Trees are different." << endl;
    }

    // Clean up
    delete p->left;
    delete p->right;
    delete p;

    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
