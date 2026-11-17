
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

class Stack
{
private:
    Node* head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int x)
    {
        Node* newNode = new Node(x);

        newNode->next = head;
        head = newNode;
    }

    int top()
    {
        if(isEmpty())
            return -1;

        return head->val;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int popped = head->val;

        Node* deletedNode = head;
        head = head->next;

        delete deletedNode;

        return popped;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    ~Stack()
    {
        while(head != NULL)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
