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

    return root;
}

void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void display(Node* root, int space = 0) {  //display the tree structure

    if (root == NULL)
        return;

    space += 5;

    display(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    display(root->left, space);
}

void deleteTree(Node* root) {

    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;

    int arr1[] = {30, 35, 45};

    cout << "RIGHT-RIGHT CASE" << endl;

    for (int i = 0; i < 3; i++) {
        root1 = insert(root1, arr1[i]);
    }

    cout << "Inorder: "<<endl;
    inorder(root1);

    cout << "Balanced Tree:" << endl;
    display(root1);

    cout << "Root: " << root1->data << endl;
    
    int arr2[] = {13, 10, 5};

    cout << "\nLEFT-LEFT CASE" << endl;

    for (int i = 0; i < 3; i++) {
        root2 = insert(root2, arr2[i]);
    }

    cout << "Inorder: "<<endl;
    inorder(root2);

    cout << "Balanced Tree:" << endl;
    display(root2);

    cout << "Root: " << root2->data << endl;

    deleteTree(root1);
    deleteTree(root2);

    return 0;
}

