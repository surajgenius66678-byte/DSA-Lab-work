
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    void reversingCLL(Node* &head)
    {
        if(head == NULL || head->next == head)
            return;

        Node* prev = head;
        Node* curr = head->next;
        Node* next = NULL;

        while(curr != head)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = prev;
        head = prev;
    }
};

void printCircularLL(Node* head)
{
    if(head == NULL)
        return;

    Node* temp = head;

    do
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = head;

    int nums[5] = {3, 7, 9, 6, 2};

    for(int i = 0; i < 5; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    temp->next = head;

    Solution s;

    cout << "Original Circular Linked List: ";
    printCircularLL(head);

    s.reversingCLL(head);

    cout << "Reversed Circular Linked List: ";
    printCircularLL(head);

    return 0;
}
