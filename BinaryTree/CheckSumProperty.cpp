#include <iostream>
using namespace std;

// Definition for binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int isSumProperty(Node* root) {
        // Base case: null or leaf node
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 1;
        }

        int left_sum = 0, right_sum = 0;

        if (root->left != nullptr) {
            left_sum = root->left->data;
        }

        if (root->right != nullptr) {
            right_sum = root->right->data;
        }

        // Check current node and recursively check left and right subtrees
        if ((root->data == left_sum + right_sum) &&
            isSumProperty(root->left) &&
            isSumProperty(root->right)) {
            return 1;
        } else {
            return 0;
        }
    }
};

// Example usage
int main() {
    /*
        Tree:
              10
             /  \
            8    2
           / \
          3   5

        This satisfies the children sum property.
    */

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    Solution sol;
    if (sol.isSumProperty(root)) {
        cout << "The tree satisfies the children sum property." << endl;
    } else {
        cout << "The tree does NOT satisfy the children sum property." << endl;
    }

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
