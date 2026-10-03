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

void detectBreakCycle(LinkedList &ll){
	
	Node* fast = ll.head;
	Node* slow = ll.head;
	bool isCycle = false;
	
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast){
			isCycle = true;
			break;
		}
	}
		if(!isCycle){
			cout << "No Cycle detected";
			return;
		}
		slow = ll.head;
		Node* prev = NULL;
			while(slow!=fast){
				slow = slow->next;
				prev = fast;
				fast = fast->next;
			}
			prev->next = NULL;		
}
		

int main(){

    LinkedList ll;

    ll.InsertInLinkedList(6);
    ll.InsertInLinkedList(5);
    ll.InsertInLinkedList(4);
    ll.InsertInLinkedList(3);
    ll.InsertInLinkedList(2);
    ll.InsertInLinkedList(1);
    
    //cycle made
    Node* temp = ll.head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ll.head->next->next;
    
    detectBreakCycle(ll);

    ll.display();

    return 0;
}

