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


void Inorderhelper(Node* root,vector<int>&ans){
    
}

vector<int>inOrderTraversal(Node* root){
    vector<int>ans;
    Inorderhelper(root,ans);
    return ans;
}


int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
}