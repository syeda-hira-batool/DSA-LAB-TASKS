#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int maxValue(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int getHeight(Node* root) {
    if (root == NULL)
        return 0;

    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxValue(getHeight(y->left),getHeight(y->right));

    x->height = 1 + maxValue(getHeight(x->left),getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + maxValue(getHeight(x->left),getHeight(x->right));

    y->height = 1 + maxValue(getHeight(y->left),getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value) {

    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        return root;
    }

    root->height = 1 + maxValue(getHeight(root->left),getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

    if (balance > 1 && value > root->left->data) {

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->data) {

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteTree(Node* root) {

    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {

    Node* root = NULL;

    int arr[] = {13, 10, 11};

    cout << "Inserting: 13 10 11" << endl;

    for (int i = 0; i < 3; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout <<endl;

    cout << "Final Root: " << root->data << endl;

    cout << "Root Balance Factor: "<< getBalance(root) << endl;

    deleteTree(root);

    return 0;
}

