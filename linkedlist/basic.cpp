#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int x) : data(x) {}
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    return 0;
}