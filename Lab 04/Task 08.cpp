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
		
		
		
};

int main(){
	
	LinkedList ll;
	ll.InsertInLinkedList(1);
	ll.InsertInLinkedList(2);
	ll.InsertInLinkedList(3);
	ll.InsertInLinkedList(2);
	ll.InsertInLinkedList(1);
	ll.display();	
	return 0;
		
}

