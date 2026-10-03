#include <iostream>
using namespace std;

class Node {
	public:
	    int data;
	    Node* next;
	
	    Node(int d) {
	        data = d;
	        next = NULL;
	    }
};

class LinkedList {
	public:
	    Node* head;
	
	    LinkedList() {
	        head = NULL;
	    }
	
	    void InsertInLinkedList(int val) {
	        Node* newNode = new Node(val);
	        newNode->next = head;
	        head = newNode;
	    }
	
	    void display() const {
	        Node* temp = head;
	        while (temp != NULL) {
	            cout << temp->data << " ";
	            temp = temp->next;
	        }
	        cout << endl;
	    }
};

void arrange(LinkedList &ll) {
	
    if (ll.head == NULL || ll.head->next == NULL) return;

    Node oddDummy(0);
    Node evenDummy(0);

    Node* odd = &oddDummy;
    Node* even = &evenDummy;
    Node* temp = ll.head;

    while (temp != NULL) {
        if (temp->data % 2 != 0) { 
            odd->next = temp;
            odd = odd->next;
        } 
		else {                   
            even->next = temp;
            even = even->next;
        }
        temp = temp->next;
    }

    even->next = NULL;           
    odd->next = evenDummy.next;  
    ll.head = oddDummy.next;     
}

int main() {
    LinkedList ll;
    ll.InsertInLinkedList(7);
    ll.InsertInLinkedList(4);
    ll.InsertInLinkedList(6);
    ll.InsertInLinkedList(5);
    ll.InsertInLinkedList(3);
    ll.InsertInLinkedList(1);
    ll.InsertInLinkedList(2);
    ll.display();
    arrange(ll);
    ll.display();

    return 0;
}
