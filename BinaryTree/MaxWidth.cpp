#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int getMaxWidth(Node* root) {
    if (!root) return 0;

    int maxWidth = 0;
    queue<pair<Node*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int levelSize = q.size();
        unsigned long long left = q.front().second;
        unsigned long long right = q.back().second;
        maxWidth = max(maxWidth, (int)(right - left + 1));

        for (int i = 0; i < levelSize; ++i) {
            auto [node, index] = q.front();
            q.pop();
            // Normalize index to prevent overflow
            index -= left;

            if (node->left)
                q.push({node->left, 2 * index + 1});
            if (node->right)
                q.push({node->right, 2 * index + 2});
        }
    }

    return maxWidth;
}

int main() {
    // Example Tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    int width = getMaxWidth(root);
    cout << "Maximum Width of Binary Tree: " << width << endl;

    return 0;
}
