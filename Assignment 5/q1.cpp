
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

class CircularLinkedList
{
    Node* head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
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

        if(head == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;

            if(temp == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
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

            if(head->next == head)
            {
                head = NULL;
                delete temp;
                return;
            }

            Node* last = head;

            while(last->next != head)
            {
                last = last->next;
            }

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;

            if(temp == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }

        Node* del = temp->next;

        if(del == head)
        {
            cout << "Invalid position" << endl;
            return;
        }

        temp->next = del->next;
        delete del;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != head);

        cout << endl;
    }

    ~CircularLinkedList()
    {
        if(head == NULL)
            return;

        Node* temp = head->next;

        while(temp != head)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }

        delete head;
    }
};

int main()
{
    CircularLinkedList list;

    int n, val;

    cout << "Enter size of linked list: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element no " << i << ": ";
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Original List: ";
    list.display();

    cout << "Insert at begin: ";
    list.insertAtBeginning(100);
    list.display();

    cout << "Insert at end: ";
    list.insertAtEnd(200);
    list.display();

    cout << "Insert at pos: ";
    list.insertAtPosition(300, 2);
    list.display();

    cout << "Delete at begin: ";
    list.deleteAtPosition(1);
    list.display();

    cout << "Delete at pos: ";
    list.deleteAtPosition(3);
    list.display();

    return 0;
}
