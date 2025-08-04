#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> rightView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();

            // Last node of each level
            if (i == levelSize - 1) result.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}

int main() {
    // Example Tree:
    //      1
    //     / \
    //    2   3
    //     \
    //      4
    //       \
    //        5
    //         \
    //          6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    vector<int> right = rightView(root);

    cout << "Right View: ";
    for (int x : right) cout << x << " ";
    cout << endl;

    return 0;
}
