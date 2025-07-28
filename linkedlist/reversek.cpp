#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x) {}
};

Node *ReverseKGroup(Node *head, int k)
{
    // first step is check whether the k nodes exists or not
    int count = 0;
    Node *temp = head;

    while (count < k)
    {
        if (temp == nullptr)
            return head;
        temp = temp->next;
        count++;
    }

    // second step recursively reverse done to the rest of the linked list
    Node *newNode = ReverseKGroup(temp, k);

    // third step , now change the links and reverse the current grp
    temp = head;
    count = 0;
    while (count < k)
    {
        Node *nextNode = temp->next;
        temp->next = newNode;
        newNode = temp;
        temp = nextNode;

        count++;
    }
    return newNode;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        /* code */
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL";
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    int k = 3;
    Node *ans = ReverseKGroup(head, k);
    printLL(ans);

    return 0;
}