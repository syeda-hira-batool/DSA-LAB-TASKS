#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		
		Node(int d){
			data = d;
			next = NULL;
		}
};

class LinkedList{
		
	public:
		Node* head;
		LinkedList(){
			head = NULL;
		}
		
		void InsertInLinkedList(int val){
			if(head == NULL){
				Node * newNode = new Node(val);
				head = newNode;
			}
			else{
				Node * newNode = new Node(val);
				newNode->next = head;
				head = newNode;
			}
		}
		
		void display(){
			Node* temp = head;
			while(temp!=NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		
		
		
		
};

Node* mergeTwoLinkedList(Node* h1, Node* h2){
	if(h1 == NULL){
		return h2;
	}
	if(h2 == NULL){
		return h1;
	}
	if(h1->data <= h2->data){
		h1->next = mergeTwoLinkedList(h1->next, h2);
		return h1;
	}
	else{
		h2->next = mergeTwoLinkedList(h1, h2->next);
		return h2;
	}
}

int main(){
	
	LinkedList ll;
	ll.InsertInLinkedList(7);
	ll.InsertInLinkedList(5);
	ll.InsertInLinkedList(3);
	ll.InsertInLinkedList(1);
	ll.display();
	LinkedList ll2;
	ll2.InsertInLinkedList(8);
	ll2.InsertInLinkedList(6);
	ll2.InsertInLinkedList(4);
	ll2.InsertInLinkedList(2);
	ll2.display();
	mergeTwoLinkedList(ll.head , ll2.head);
	ll.display();
	
	
		
	return 0;
		
}

