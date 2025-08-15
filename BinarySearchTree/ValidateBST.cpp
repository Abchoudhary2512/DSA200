#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *leftptr;
    Node *rightptr;
    Node(int x) : data(x), leftptr(nullptr), rightptr(nullptr) {}
};

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->leftptr);
    cout << root->data << " ";
    inorder(root->rightptr);
}

bool helper(Node* root,int mini,int maxi){
     if (!root) return true;

    if(root->data<mini || root->data > maxi ) return false;
    return helper(root->leftptr,mini,root->data) && helper(root->rightptr,root->data,maxi);
}

bool isValidBST(Node* root){

    return helper(root,LONG_MIN,LONG_MAX);
}

int main()
{
    Node *root = new Node(1);
    root->leftptr = new Node(2);
    root->rightptr = new Node(3);
    bool ans  = isValidBST(root);
    cout<<ans;

    // inorder(root);
    return 0;
}