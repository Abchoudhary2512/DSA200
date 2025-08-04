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

// Inorder: Left -> Node -> Right
void inorderHelper(Node* root, vector<int>& ans) {
    if (!root) return;
    inorderHelper(root->left, ans);
    ans.push_back(root->data);
    inorderHelper(root->right, ans);
}

vector<int> inOrderTraversal(Node* root) {
    vector<int> ans;
    inorderHelper(root, ans);
    return ans;
}

// Preorder: Node -> Left -> Right
void preorderHelper(Node* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->data);
    preorderHelper(root->left, ans);
    preorderHelper(root->right, ans);
}

vector<int> preOrderTraversal(Node* root) {
    vector<int> ans;
    preorderHelper(root, ans);
    return ans;
}

// Postorder: Left -> Right -> Node
void postorderHelper(Node* root, vector<int>& ans) {
    if (!root) return;
    postorderHelper(root->left, ans);
    postorderHelper(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postOrderTraversal(Node* root) {
    vector<int> ans;
    postorderHelper(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> inorder = inOrderTraversal(root);
    vector<int> preorder = preOrderTraversal(root);
    vector<int> postorder = postOrderTraversal(root);

    cout << "Inorder: ";
    for (int x : inorder) cout << x << " ";
    cout << endl;

    cout << "Preorder: ";
    for (int x : preorder) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : postorder) cout << x << " ";
    cout << endl;

    return 0;
}
