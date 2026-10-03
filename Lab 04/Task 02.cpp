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
		
		Node* middleNode(){
			Node* fast = head;
			Node* slow = head;
			
			while(fast!=NULL && fast->next!= NULL){
				slow = slow->next;
				fast = fast->next->next;
			}
			
			return slow;
		}
		
};

int main(){
	
	LinkedList ll;
	ll.InsertInLinkedList(5);
	ll.InsertInLinkedList(4);
	ll.InsertInLinkedList(3);
	ll.InsertInLinkedList(2);
	ll.InsertInLinkedList(1);
	ll.display();
	cout << "Middle Node for LinkedList1 is " <<  ll.middleNode()->data << endl;
	
	LinkedList ll2;
	ll2.InsertInLinkedList(6);
	ll2.InsertInLinkedList(5);
	ll2.InsertInLinkedList(4);
	ll2.InsertInLinkedList(3);
	ll2.InsertInLinkedList(2);
	ll2.InsertInLinkedList(1);
	ll2.display();
	cout << "Middle Node for LinkedList2 is " <<  ll2.middleNode()->data<< endl;
	
	return 0;
	
}

