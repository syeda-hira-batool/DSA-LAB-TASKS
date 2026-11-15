#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int v){
            val = v;
            left = NULL;
            right = NULL;
        }
};

class BST{
    private:
        Node* root;

        Node* insert(Node* root, int key){
            if(root == NULL){
                return new Node(key);
            }

            if(key < root->val){
                root->left = insert(root->left, key);
            }
            else if(key > root->val){
                root->right = insert(root->right, key);
            }

            return root;
        }


        void inOrder(Node* root){
            if(root == NULL){
                return;
            }

            inOrder(root->left);
            cout << root->val << " ";
            inOrder(root->right);
        }

    public:
        BST(){
            root = NULL;
        }

        void insert(int key){
            root = insert(root, key);
        }

};

int main(){
    BST tree;

    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = 6;

    for(int i = 0; i < n; i++){
        tree.insert(arr[i]);
    }

    cout << "Inorder traversal: ";
    tree.display();
    

    return 0;
}
