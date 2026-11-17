
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
    void reversingLL(Node* &head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

void printLL(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = new Node(10);
    Node* temp = head;

    int nums[5] = {3, 7, 9, 6, 2};

    for(int i = 0; i < 5; i++)
    {
        temp->next = new Node(nums[i]);
        temp = temp->next;
    }

    Solution s;

    cout << "Original Linked List: ";
    printLL(head);

    s.reversingLL(head);

    cout << "Reversed Linked List: ";
    printLL(head);

    return 0;
}
