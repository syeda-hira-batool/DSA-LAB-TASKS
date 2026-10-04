#include <iostream>
using namespace std;

int const n = 8;
string queue[n];


class Queue{
	public:
		int rear;
		int front;
		
		Queue(){
			rear = -1;
			front = -1;
			for(int i=0; i<n; i++){
				queue[i] = '0';
			}
		}
		
		bool isEmpty(){
			if(rear == -1){
				cout << "Queue is Empty" <<endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isFull(){
			if(front == n){
				cout << "Queue is Full" <<endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		void enqeue(string data){
			if(isFull()){
				return;
			}
			else{
				rear++;
				queue[rear] = data;
			}
		}
		
		void display(){
			for(int i=0; i<=rear; i++){
				cout << queue[i] << " ";
			}
			cout << endl;
		}
		
};


void reverseFirstK(Queue &q, int k){

    int const n = 8;
    string stack[n]; 
    int top = -1;

    int i = 0;
    
    while(i != k){
        top++;
        stack[top] = queue[i];
        i++;
    }
    
    i = 0;

    while(top >= 0){
        queue[i] = stack[top];
        top--;
        i++;
    }
}	
	
			

int main(){
	
	Queue q1;
	q1.enqeue("J1");
	q1.enqeue("J2");
	q1.enqeue("J3");
	q1.enqeue("J4");
	q1.enqeue("J5");
	q1.enqeue("J6");
	q1.enqeue("J7");
	q1.display();
	reverseFirstK(q1, 3);
	q1.display();
	
	return 0;
}



