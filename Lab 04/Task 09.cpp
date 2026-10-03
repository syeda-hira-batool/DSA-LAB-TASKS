#include<iostream>
using namespace std;

class Node{
	public:
	    int id;
	    int severity;
	
	    Node* next;
	    Node* prev;
	
	    Node(int i, int s){
	        id = i;
	        severity = s;
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
	
	    void InsertInLinkedList(int id, int severity){
	
	        Node* newNode = new Node(id, severity);
	
	        if(head == NULL){
	            head = newNode;
	            tail = newNode;
	        }
	        else{
	            newNode->next = head;
	            head->prev = newNode;
	            head = newNode;
	        }
	    }
	
	    void display(){
	
	        Node* temp = head;
	
	        while(temp != NULL){
	            cout << "[ID:" << temp->id << ", Sev:" << temp->severity << "]";
	
	            if(temp->next != NULL){
	                cout << " <-> ";
	            }
	
	            temp = temp->next;
	        }
	
	        cout << endl;
	    }
};

Node* getNode(DoublyLinkedList &ll, int position){

    Node* temp = ll.head;

    for(int i = 0; i < position; i++){
        temp = temp->next;
    }

    return temp;
}


void swapNodes(DoublyLinkedList &ll, Node* a, Node* b){

    if(a == b){
        return;
    }

    Node* temp = a;

    while(temp != NULL && temp != b){
        temp = temp->next;
    }

    if(temp == NULL){
        Node* t = a;
        a = b;
        b = t;
    }


    Node* aPrev = a->prev;
    Node* aNext = a->next;

    Node* bPrev = b->prev;
    Node* bNext = b->next;

    if(aNext == b){

        if(aPrev != NULL)
            aPrev->next = b;
        else
            ll.head = b;

        if(bNext != NULL)
            bNext->prev = a;
        else
            ll.tail = a;

        b->prev = aPrev;
        b->next = a;

        a->prev = b;
        a->next = bNext;
    }

    else{

        if(aPrev != NULL)
            aPrev->next = b;
        else
            ll.head = b;

        if(aNext != NULL)
            aNext->prev = b;

        if(bPrev != NULL)
            bPrev->next = a;
        else
            ll.head = a;

        if(bNext != NULL)
            bNext->prev = a;

        a->prev = bPrev;
        a->next = bNext;

        b->prev = aPrev;
        b->next = aNext;
    }
}

void shellSort(DoublyLinkedList &ll){

    int n = 0;
    Node* temp = ll.head;
    
    while(temp != NULL){
        n++;
        temp = temp->next;
    }

    for(int gap = n / 2; gap > 0; gap = gap / 2){
        for(int i = gap; i < n; i++){
            Node* current = getNode(ll, i);
            int j = i;
            
            while(j >= gap){
                Node* previous = getNode(ll, j - gap);
                if(previous->severity <= current->severity){
                    break;
                }
                swapNodes(ll, previous, current);
                j = j - gap;
            }
        }
    }
}


int main(){

    DoublyLinkedList ll;

    ll.InsertInLinkedList(106, 30);
    ll.InsertInLinkedList(105, 60);
    ll.InsertInLinkedList(104, 10);
    ll.InsertInLinkedList(103, 80);
    ll.InsertInLinkedList(102, 20);
    ll.InsertInLinkedList(101, 50);

    cout << "Before Sorting:" << endl;
    ll.display();
    shellSort(ll);
    cout << endl;
    cout << "After Sorting:" << endl;
    ll.display();


    return 0;
}
