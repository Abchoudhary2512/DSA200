#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrderTraversal(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();
            currentLevel.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel);
    }

    return result;
}

int main() {
    // Example Tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<vector<int>> levels = levelOrderTraversal(root);

    cout << "Level Order Traversal:\n";
    for (const auto& level : levels) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
