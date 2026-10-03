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
	private:
		Node* head;
	public:
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
		
		void reverseLinkedList(){
			Node* curr = head;
			Node* next = NULL;
			Node* prev = NULL;
			
			while(curr!= NULL){
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}
		
};

int main(){
	
	LinkedList ll;
	ll.InsertInLinkedList(50);
	ll.InsertInLinkedList(40);
	ll.InsertInLinkedList(30);
	ll.InsertInLinkedList(20);
	ll.InsertInLinkedList(10);
	ll.display();
	ll.reverseLinkedList();
	ll.display();
	
	return 0;
	
}










