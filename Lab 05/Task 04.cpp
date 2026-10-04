#include <iostream>
using namespace std;

int const n = 6;
int queue[n];

class Queue {
public:
    int rear;
    int front;

    Queue() {
        rear = -1;
        front = -1;

        for (int i = 0; i < n; i++) {
            queue[i] = 0;
        }
    }

    bool isEmpty() {
        if (rear == -1 && front == -1) {
            cout << "Queue is Empty" << endl;
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if ((rear + 1) % n == front) {
            cout << "Queue is Full" << endl;
            return true;
        }
        else {
            return false;
        }
    }

    void enqeue(int data) {

        if (isFull()) {
            return;
        }
        else if (isEmpty()) {
            front = 0;
            rear = 0;
            queue[rear] = data;
        }
        else {
            rear = (rear + 1) % n;
            queue[rear] = data;
        }
    }

    void dequeue() {

        int dequeueVal;

        if (isEmpty()) {
            return;
        }

        else if (rear == front) {
            dequeueVal = queue[front];
            rear = -1;
            front = -1;
            cout << "Dequeued Value: " << dequeueVal << endl;
        }

        else {
            dequeueVal = queue[front];
            queue[front] = 0;
            front = (front + 1) % n;
            cout << "Dequeued Value: " << dequeueVal << endl;
        }
    }

    void display() {
    	
        if (isEmpty()) {
            return;
        }
        int i = front;

        while (true) {
            cout << queue[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % n;
        }
        cout << endl;
    }
    
    void getFrontPos(){
    	cout << "Position of Front is: " << front << endl;
	}
	
	void getRearPos(){
    	cout << "Position of Rear is: " << rear << endl;
	}
};


int main() {

    Queue q1;

    q1.enqeue(101);
    q1.enqeue(102);
    q1.enqeue(103);
    q1.enqeue(104);
    q1.enqeue(105);
    q1.enqeue(106);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.enqeue(107);
    q1.enqeue(108);
    q1.enqeue(109);
    q1.dequeue();
    q1.dequeue();
    q1.enqeue(110);
    q1.dequeue();
    q1.enqeue(111);
    q1.enqeue(112);
    q1.display();
    q1.getFrontPos();
    q1.getRearPos();

    return 0;
}
