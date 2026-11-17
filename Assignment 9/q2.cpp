#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node *first = NULL, *second = NULL, *pre = NULL;

void find(Node* root) {
    if (root == NULL)
        return;

    find(root->left);

    if (pre != NULL && pre->val > root->val) {
        if (first == NULL) {
            first = pre;
            second = root;
        }
        else {
            second = root;
        }
    }

    pre = root;

    find(root->right);
}

void recoverTree(Node* root) {
    first = second = pre = NULL;

    find(root);

    if (first && second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}

void display(Node* root) {
    if (root == NULL)
        return;

    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main() {
    Node* root = new Node(6);

    root->left = new Node(3);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->right = new Node(7);

    root->right->left = new Node(4);
    root->right->right = new Node(9);

    cout << "Before: ";
    display(root);

    cout << endl;

    recoverTree(root);

    cout << "After: ";
    display(root);

    cout << endl;

    return 0;
}