#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();

                if (prev) {
                    prev->next = curr;
                }
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // The last node in each level should point to nullptr
            prev->next = nullptr;
        }

        return root;
    }
};

// Helper function to print tree level order with next pointers
void printWithNext(Node* root) {
    Node* levelStart = root;
    while (levelStart) {
        Node* curr = levelStart;
        levelStart = nullptr;

        while (curr) {
            cout << curr->val << " -> ";
            if (!levelStart) {
                if (curr->left) levelStart = curr->left;
                else if (curr->right) levelStart = curr->right;
            }
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    // Build sample tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    root = sol.connect(root);

    // Print tree with next pointers
    printWithNext(root);

    // Cleanup memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
