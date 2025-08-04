#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node* root) {
    if (!root) return {};

    // Map to store the first node at each horizontal distance
    map<int, int> topNode;
    // Queue for level order traversal: stores pair of node and its horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // If this horizontal distance is being seen for the first time
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = node->data;
        }

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    // Extract top view from the map (sorted by horizontal distance)
    vector<int> result;
    for (auto& it : topNode) {
        result.push_back(it.second);
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

    vector<int> top = topView(root);

    cout << "Top View: ";
    for (int x : top) cout << x << " ";
    cout << endl;

    return 0;
}
