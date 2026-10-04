#include<iostream>
using namespace std;

int const n = 8;
int stack[n]; //global scope array

class Stack{
	
	public:
		int top;
		
		Stack(){
			top = -1;
			for(int i=0; i<n; i++){
				stack[i] = 0;
			}
		}
		
		bool isEmpty(){
			if(top == -1){
				return true;
				cout << "The stack is empty" << endl;
			}
			else{
				return false;
			}
		}
		
		bool isFull(){
			if(top == n-1){
				cout << "Stack is full" << endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(int data){
			if(isFull()){
				cout << "Stack is Full!" << endl;
				return;
			}
			else{
				top++;
				stack[top] = data;
			}
		}
		
		void pop(){
			if(isEmpty()){
				cout << "Stack is Empty" << endl;
				return;
			}
			else{
				int val = stack[top];
				top--;
				cout << "The value popped is: " << val << endl;
			}
		}
		
		void display(){ //keeping filo format
			
			for(int i=top; i>=0; i--){
				cout << stack[i] << endl;
			}
		}
		
		void peek(){ //tells the current top operation
			if(isEmpty()){
				cout << "Stack is Empty" << endl;
				return;
			}
			else{
				cout << "The current top operation is " << stack[top] << endl;
			}
		}	
		
	
};


int main(){
	
	Stack s1;
	s1.push(12);
	s1.push(25);
	s1.push(17);
	s1.push(31);
	s1.push(44);
	s1.push(19);
	s1.display();
	// undo == pop
	s1.pop();
	s1.peek();
	s1.pop();
	s1.peek();
	s1.pop();
	s1.peek();
	s1.push(52);
	s1.peek();
	s1.display();
	
	return 0;
		
}
