#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void kClosest(Node* root, int x, int k) {
    stack<Node*> pred, succ;

    Node* cur = root;

    while (cur) {
        if (cur->data <= x) {
            pred.push(cur);
            cur = cur->right;
        }
        else {
            succ.push(cur);
            cur = cur->left;
        }
    }

    for (int i = 0; i < k && (!pred.empty() || !succ.empty()); i++) {

        if (!pred.empty() &&
            (succ.empty() ||
             x - pred.top()->data <= succ.top()->data - x)) {

            Node* node = pred.top();
            pred.pop();

            cout << node->data << " ";

            cur = node->left;

            while (cur) {
                pred.push(cur);
                cur = cur->right;
            }
        }
        else {
            Node* node = succ.top();
            succ.pop();

            cout << node->data << " ";

            cur = node->right;

            while (cur) {
                succ.push(cur);
                cur = cur->left;
            }
        }
    }

    cout << endl;
}

int main() {
    int a[] = {10, 5, 15, 2, 7, 12, 20, 6, 8};

    Node* root = NULL;

    for (int i = 0; i < 9; i++)
        root = insert(root, a[i]);

    kClosest(root, 9, 4);
    kClosest(root, 0, 3);
    kClosest(root, 100, 3);

    return 0;
}