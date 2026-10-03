#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
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
				Node* newNode = new Node(val);
				head = newNode;
			}
			else{
				Node* newNode = new Node(val);
				newNode->next = head;
				head = newNode;
			}
		}
		
		void display(){
			Node* temp = head;
			
			while(temp != NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
			
			cout << endl;
		}
};

Node* getIntersectionNode(Node* hA, Node* hB){

	Node* p1 = hA;
	Node* p2 = hB;

	while(p1 != p2){

		if(p1 == NULL){
			p1 = hB;
		}
		else{
			p1 = p1->next;
		}	
		if(p2 == NULL){
			p2 = hA;
		}
		else{
			p2 = p2->next;
		}
			
	}

	return p1;
}

int main(){

	LinkedList llA;
	LinkedList llB;

	llA.InsertInLinkedList(1);
	llA.InsertInLinkedList(4);

	llB.InsertInLinkedList(1);
	llB.InsertInLinkedList(6);
	llB.InsertInLinkedList(5);

	LinkedList common;
	common.InsertInLinkedList(5);
	common.InsertInLinkedList(4);
	common.InsertInLinkedList(8);

	Node* temp = llA.head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = common.head;

	temp = llB.head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = common.head;

	cout << "Chain A: ";
	llA.display();

	cout << "Chain B: ";
	llB.display();


	Node* intersection = getIntersectionNode(llA.head, llB.head);

	if(intersection != NULL){
		cout << "Intersection point = [" << intersection->data << "]" << endl;
	}
	else{
		cout << "No intersection" << endl;
	}

	return 0;
}
