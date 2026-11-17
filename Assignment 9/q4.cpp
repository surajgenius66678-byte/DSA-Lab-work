#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int best = 0;

int solve(Node* root, int &mn, int &mx, int &sum) {
    if (!root) {
        mn = INT_MAX;
        mx = INT_MIN;
        sum = 0;
        return 1;
    }

    int lmn, lmx, lsum;
    int rmn, rmx, rsum;

    int lok = solve(root->left, lmn, lmx, lsum);
    int rok = solve(root->right, rmn, rmx, rsum);

    if (lok && rok &&
        root->data > lmx &&
        root->data < rmn) {

        sum = lsum + rsum + root->data;

        mn = min(lmn, root->data);
        mx = max(rmx, root->data);

        if (sum > best)
            best = sum;

        return 1;
    }

    return 0;
}

int maxBSTSum(Node* root) {
    int mn, mx, sum;

    best = 0;

    solve(root, mn, mx, sum);

    return best;
}

int main() {
    Node* root = new Node(5);

    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(3);
    root->left->right = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << "Maximum BST subtree sum = "
         << maxBSTSum(root) << endl;

    return 0;
}