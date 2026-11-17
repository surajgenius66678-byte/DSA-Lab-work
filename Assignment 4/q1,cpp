
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos)
    {
        if(pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if(pos == 1)
        {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(int pos)
    {
        if(head == NULL || pos < 1)
        {
            cout << "Invalid operation" << endl;
            return;
        }

        if(pos == 1)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    ~LinkedList()
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
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original Linked List: ";
    list.display();

    list.insertAtBeginning(100);

    cout << "After insertion at beginning: ";
    list.display();

    list.insertAtEnd(200);

    cout << "After insertion at end: ";
    list.display();

    list.insertAtPosition(300, 4);

    cout << "After insertion at position 4: ";
    list.display();

    list.deleteAtPosition(1);

    cout << "After deletion at beginning: ";
    list.display();

    list.deleteAtPosition(4);

    cout << "After deletion at middle: ";
    list.display();

    list.deleteAtPosition(5);

    cout << "After deletion at end: ";
    list.display();

    return 0;
}
