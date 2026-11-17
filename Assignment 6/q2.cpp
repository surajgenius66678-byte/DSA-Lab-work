
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    void reversingDLL(Node* &head)
    {
        Node* temp = head;
        Node* next = NULL;

        while(temp != NULL)
        {
            next = temp->next;

            temp->next = temp->prev;
            temp->prev = next;

            if(next == NULL)
            {
                head = temp;
            }

            temp = next;
        }
    }
};

void printDoublyLL(Node* head)
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
        Node* newNode = new Node(nums[i]);

        temp->next = newNode;
        newNode->prev = temp;

        temp = temp->next;
    }

    Solution s;

    cout << "Original Doubly Linked List: ";
    printDoublyLL(head);

    s.reversingDLL(head);

    cout << "Reversed Doubly Linked List: ";
    printDoublyLL(head);

    return 0;
}
