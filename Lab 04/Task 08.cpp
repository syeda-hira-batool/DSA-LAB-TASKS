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

int countTriplets(DoublyLinkedList &ll, int X){
	
    int count = 0;
    Node* first = ll.head;

    while(first != NULL){
        Node* second = first->next;
        
        while(second != NULL){
            Node* third = second->next;

            while(third != NULL){
                if(first->data + second->data + third->data == X){
                    count++;
                }
                third = third->next;
            }
            second = second->next;
        }
        first = first->next;
    }
    return count;
}

int main(){
	
	DoublyLinkedList ll;
	ll.InsertInLinkedList(5);
	ll.InsertInLinkedList(4);
	ll.InsertInLinkedList(3);
	ll.InsertInLinkedList(2);
	ll.InsertInLinkedList(1);
	ll.display();
	int x = 6;
	cout << "COUNT: " << countTriplets(ll, x);	
	
	return 0;
		
}

