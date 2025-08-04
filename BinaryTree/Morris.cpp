#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Morris Inorder Traversal: O(n) time, O(1) space
vector<int> morrisInOrderTraversal(Node* root) {
    vector<int> ans;
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            ans.push_back(current->data);
            current = current->right;
        } else {
            Node* predecessor = current->left;
            // Find rightmost node in left subtree or a thread pointing to current
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Make a thread (temporary link)
                predecessor->right = current;
                current = current->left;
            } else {
                // Thread exists, restore tree and visit current
                predecessor->right = nullptr;
                ans.push_back(current->data);
                current = current->right;
            }
        }
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> inorder = morrisInOrderTraversal(root);

    cout << "Morris Inorder Traversal: ";
    for (int x : inorder) cout << x << " ";
    cout << endl;

    return 0;
}
