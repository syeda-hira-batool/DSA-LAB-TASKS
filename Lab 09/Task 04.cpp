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

class QueueNode {
public:
    Node* data;
    QueueNode* next;

    QueueNode(Node* val) {
        data = val;
        next = NULL;
    }
};

class Queue {
	public:
	    QueueNode* front;
	    QueueNode* rear;
	    int count;
	
	    Queue() {
	        front = NULL;
	        rear = NULL;
	        count = 0;
	    }
	
	    bool isEmpty() {
	        return front == NULL;
	    }
	
	    void enqueue(Node* val) {
	        QueueNode* newNode = new QueueNode(val);
	
	        if (isEmpty()) {
	            front = newNode;
	            rear = newNode;
	        }
	        else {
	            rear->next = newNode;
	            rear = newNode;
	        }
	
	        count++;
	    }
	
	    Node* dequeue() {
	        if (isEmpty()) {
	            return NULL;
	        }
	
	        QueueNode* temp = front;
	        Node* value = temp->data;
	
	        front = front->next;
	
	        if (front == NULL) {
	            rear = NULL;
	        }
	
	        delete temp;
	        count--;
	
	        return value;
	    }
	
	    int size() {
	        return count;
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

    Node* current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int value) {

    if (root == NULL) {
        return root;
    }

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

            root->right = deleteNode(root->right,temp->data);
        }
    }

    root->height = 1 + maxValue(getHeight(root->left),getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printLevelOrder(Node* root) {

    if (root == NULL) {
        cout << "Tree is empty";
        return;
    }

    Queue q;

    q.enqueue(root);

    int level = 0;

    while (!q.isEmpty()) {

        int nodes = q.size();

        cout << "Level " << level << ": ";

        for (int i = 0; i < nodes; i++) {

            Node* current = q.dequeue();

            cout << current->data << "(BF=" << getBalance(current) << ") ";

            if (current->left != NULL) {
                q.enqueue(current->left);
            }

            if (current->right != NULL) {
                q.enqueue(current->right);
            }
        }

        cout << endl;
        level++;
    }
}

bool isAVL(Node* root) {

    if (root == NULL)
        return true;

    int balance = getBalance(root);

    if (balance > 1 || balance < -1)
        return false;

    return isAVL(root->left) && isAVL(root->right);
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

    int arr[] = {30, 20, 40, 10, 25};

    cout << "INSERTING FIVE NODES" << endl;

    for (int i = 0; i < 5; i++) {
        root = insert(root, arr[i]);
    }

    cout << "\nAfter insertion:" << endl;
    printLevelOrder(root);

    root = deleteNode(root, 40);
    root = deleteNode(root, 10);

    cout << "\nFINAL LEVEL ORDER TRAVERSAL" << endl;

    printLevelOrder(root);

    cout << "\nFinal Root: " << root->data << endl;

    cout << "Tree Height: " << getHeight(root) << endl;

    if (isAVL(root)) {
        cout << "AVL Balance: VALID" << endl;
    }
    
    else {
        cout << "AVL Balance: INVALID" << endl;
    }

    deleteTree(root);

    return 0;
}

