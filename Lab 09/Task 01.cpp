#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int v) {
        data = v;
        next = NULL;
    }
};

Node* insertBST(Node* root, int value) {

    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->val) {
        root->left = insertBST(root->left, value);
    }
    else {
        root->right = insertBST(root->right, value);
    }

    return root;
}

void inorderToList(Node* root, ListNode*& head, ListNode*& tail) {

    if (root == NULL) {
        return;
    }

    inorderToList(root->left, head, tail);

    ListNode* newNode = new ListNode(root->val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    inorderToList(root->right, head, tail);
}

int countNodes(ListNode* head) {

    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

Node* buildBalancedTree(ListNode*& head, int n) {

    if (n <= 0) {
        return NULL;
    }

    Node* leftSubtree = buildBalancedTree(head, n / 2);

    Node* root = new Node(head->data);
    root->left = leftSubtree;

    head = head->next;

    root->right = buildBalancedTree(head, n - n / 2 - 1);

    return root;
}

void deleteList(ListNode* head);

Node* balanceExistingBST(Node* root) {

    ListNode* head = NULL;
    ListNode* tail = NULL;

    inorderToList(root, head, tail);

    int n = countNodes(head);

    ListNode* listToDelete = head;

    Node* balancedRoot = buildBalancedTree(head, n);

    deleteList(listToDelete);

    return balancedRoot;
}

int height(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void deleteTree(Node* root) {

    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

void deleteList(ListNode* head) {

    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    Node* root = NULL;

    root = insertBST(root, 10);
    root = insertBST(root, 20);
    root = insertBST(root, 30);
    root = insertBST(root, 40);
    root = insertBST(root, 50);
    root = insertBST(root, 60);
    root = insertBST(root, 70);

    cout << "Original BST Inorder: ";
    inorder(root);

    cout << "\nOriginal BST Height: " << height(root) << endl;

    Node* balancedRoot = balanceExistingBST(root);

    cout << "\nBalanced BST Inorder: ";
    inorder(balancedRoot);

    cout << "\nBalanced BST Height: " << height(balancedRoot) << endl;

    deleteTree(root);
    deleteTree(balancedRoot);

    return 0;
}

