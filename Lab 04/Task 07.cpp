#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		Node * prev;
		
		Node(int d){
			data = d;
			next = NULL;
			prev = NULL;
		}
};

class DoublyLinkedList{
		
	public:
		Node* head;
		Node* tail;
		DoublyLinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		void InsertInLinkedList(int val){
			if(head == NULL){
				Node * newNode = new Node(val);
				head = tail = newNode;
			}
			else{
				Node * newNode = new Node(val);
				newNode->next = head;
				head->prev = newNode;
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


void avoidDuplicate(DoublyLinkedList &ll){

    Node* temp = ll.head;

    while(temp != NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if(toDelete->next != NULL){
                toDelete->next->prev = temp;
            }
            
            else{
                ll.tail = temp;
            }

            delete toDelete;
        }
        
        else{
            temp = temp->next;
        }
    }
}
		


int main(){
	
	DoublyLinkedList ll;
	ll.InsertInLinkedList(4 );
	ll.InsertInLinkedList(3 );
	ll.InsertInLinkedList(3);
	ll.InsertInLinkedList(3);
	ll.InsertInLinkedList(2);
	ll.InsertInLinkedList(1);
	ll.InsertInLinkedList(1);
	ll.display();
	avoidDuplicate(ll);
	ll.display();
	
	
	return 0;
		
}

