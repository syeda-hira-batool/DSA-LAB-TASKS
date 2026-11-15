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

    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + maxValue(getHeight(root->left),getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

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

Node* findMin(Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int value) {

    if (root == NULL)
        return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    else {
    	
        if (root->left == NULL || root->right == NULL) {

            Node* temp;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            if (temp == NULL) {
                delete root;
                return NULL;
            }

            else {
                Node* oldRoot = root;
                root = temp;
                delete oldRoot;
            }
        }

        else {

            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxValue(getHeight(root->left),getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0) {

        return rightRotate(root);
    }

    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0) {

        return leftRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) > 0) {

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

void display(Node* root) {

    if (root == NULL)
        return;

    cout << "Node: " << root->data
         << " Height: " << root->height
         << " Balance: " << getBalance(root)
         << endl;

    display(root->left);
    display(root->right);
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

    int arr[] = {30, 20, 40, 10, 25, 35, 50};

    for (int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Original AVL Tree:" << endl;
    inorder(root);

    cout << "\n\nNode Information:" << endl;
    display(root);

    cout << "\nDeleting 50..." << endl;

    root = deleteNode(root, 50);

    cout << "\nAfter Deletion:" << endl;
    inorder(root);

    cout << "\n\nUpdated Node Information:" << endl;
    display(root);

    deleteTree(root);

    return 0;
}

