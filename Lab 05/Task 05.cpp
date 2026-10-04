#include <iostream>
using namespace std;

int const n = 8;
char stack1[n];  //for enqueue
char stack2[n]; //for dequeue (reverse order)

class Queue{
	public:
		int top1;
		int top2;
		
		Queue(){
			top1 = -1;
			top2 = -1;
			for(int i=0; i<n; i++){
				stack1[i] = '0';
				stack2[i] = '0';
			}
		}
		
		bool isStack1Empty(){
			if(top1 == -1){
				cout << "Queue is Empty" <<endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isStack2Empty(){
			if(top2 == -1){
				cout << "Queue is Empty" <<endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isStack1Full(){
			if(top1 == n){
				cout << "Queue is Full" <<endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isStack2Full(){
			if(top2 == n){
				cout << "Queue is Full" <<endl;
				return true;
			}
			else{
				return false;
			}
		}
		
		void enqeue(char data){
			if(isStack1Full()){
				return;
			}
			else{
				top1++;
				stack1[top1] = data;
			}
		}
		
		void dequeue() {
			
	        if (isStack2Empty()) { //transfer everything
	
	            while (!isStack1Empty()) {
	                top2++;
	                stack2[top2] = stack1[top1];
	                top1--;
	            }
	        }
	        
	        if (isStack2Empty()) {
	            return;
	        }
	        else{
	        	char poppedVal = stack2[top2];
		        top2--;
		        cout << "Dequeued Value: " << poppedVal << endl;
			}
	        
	    }

		
};

int main(){
	
	Queue q1;
	q1.enqeue('A');
	q1.enqeue('B');
	q1.dequeue();
	q1.enqeue('C');
	q1.dequeue();
	q1.dequeue();
	
	return 0;
}
