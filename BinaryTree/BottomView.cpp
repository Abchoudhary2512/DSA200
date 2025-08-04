#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(Node* root) {
    if (!root) return {};

    // Map to store the bottommost node at each horizontal distance
    map<int, int> bottomNode;
    // Queue for level order traversal: stores pair of node and its horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Update the node at horizontal distance every time (last one at this HD stays)
        bottomNode[hd] = node->data;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    // Extract bottom view from the map (sorted by horizontal distance)
    vector<int> result;
    for (auto& it : bottomNode) {
        result.push_back(it.second);
    }
    return result;
}

int main() {
    // Same tree as before:
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

    vector<int> bottom = bottomView(root);

    cout << "Bottom View: ";
    for (int x : bottom) cout << x << " ";
