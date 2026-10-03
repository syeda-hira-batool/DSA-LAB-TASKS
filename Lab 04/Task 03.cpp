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
		
		bool isPalindrome(){
		    
		    Node* slow = head;
		    Node* fast = head;
		    while(fast != NULL && fast->next != NULL){
		        slow = slow->next;
		        fast = fast->next->next;
		    }
		
		    Node* prev = NULL;
		    Node* curr = slow;
		
		    while(curr != NULL){
		        Node* next = curr->next;
		        curr->next = prev;
		        prev = curr;
		        curr = next;
		    }
		
		    Node* h1 = head;
		    Node* h2 = prev;
		
		    while(h2 != NULL){
		        if(h1->data != h2->data){
		            return false;
		        }
		
		        h1 = h1->next;
		        h2 = h2->next;
		    }
		
		    return true;
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
	if(ll.isPalindrome()){
	    cout << "TRUE" << endl;
	}
	else{
	    cout << "FALSE" << endl;
	}
		
		return 0;
		
}

