#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void writeNodes(Node* root, string &out) {
    if (!root) {
        out += "#,";
        return;
    }

    out += to_string(root->data) + ",";

    writeNodes(root->left, out);
    writeNodes(root->right, out);
}

string serialize(Node* root) {
    string out;

    writeNodes(root, out);

    if (!out.empty())
        out.pop_back();

    return out;
}

Node* build(stringstream &ss) {
    string value;

    if (!getline(ss, value, ','))
        return NULL;

    if (value == "#")
        return NULL;

    Node* node = new Node(stoi(value));

    node->left = build(ss);
    node->right = build(ss);

    return node;
}

Node* deserialize(string data) {
    stringstream ss(data);

    return build(ss);
}

void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void test(Node* root, string name) {
    string s = serialize(root);

    Node* copy = deserialize(s);

    string s2 = serialize(copy);

    cout << name << endl;

    cout << "serialized : " << s << endl;

    cout << "inorder : ";
    inorder(copy);

    cout << endl;

    cout << "round trip : "
         << (s == s2 ? "match" : "MISMATCH")
         << endl << endl;
}

int main() {
    Node* t1 = new Node(1);

    t1->left = new Node(2);
    t1->right = new Node(3);

    t1->right->left = new Node(4);
    t1->right->right = new Node(5);

    test(t1, "Example tree");

    test(NULL, "Empty tree");

    Node* t3 = new Node(-7);

    t3->right = new Node(12);
    t3->right->left = new Node(-300);

    test(t3, "Negative values / missing children");

    return 0;
}