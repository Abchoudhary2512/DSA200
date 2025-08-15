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

//iterative
// bool isSymmetric(TreeNode* root) {
//         if (!root) return true;

//         queue<pair<TreeNode*, TreeNode*>> q;
//         q.push({root->left, root->right});

//         while (!q.empty()) {
//             TreeNode* t1 = q.front().first;
//             TreeNode* t2 = q.front().second;
//             q.pop();

//             if (!t1 && !t2) continue;
//             if (!t1 || !t2) return false;
//             if (t1->val != t2->val) return false;

//             q.push({t1->left, t2->right});
//             q.push({t1->right, t2->left});
//         }

//         return true;
//     }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;
        return (n1->val == n2->val) &&
               isMirror(n1->left, n2->right) &&
               isMirror(n1->right, n2->left);
    }
};

// Example usage
int main() {
    /*
        Symmetric Tree:
              1
             / \
            2   2
           / \ / \
          3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    Solution sol;
    bool result = sol.isSymmetric(root);

    if (result) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is NOT symmetric." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
