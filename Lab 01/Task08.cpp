#include <iostream>
using namespace std;

class Box {

	private:
	    int* value;
	
	public:
	    Box(int num) {
	        value = new int;
	        *value = num;
	        cout << "New memory allocated for value: "<< *value << endl;
	    }
	    /*
	        COPY ASSIGNMENT OPERATOR:
	
	        This performs a DEEP COPY.
	
	        It is called when both objects already exist:
	
	            box2 = box1;
	    */
	    Box& operator=(const Box& obj) {
	        /*
	            SELF-ASSIGNMENT CHECK:
	            
						if we write:
							box1 = box1;
							
		            	then &obj and this point to the SAME object, we must NOT delete our 
						memory and then try to copy from the deleted memory.
	        */
	
	        if (this != &obj) {
	            cout << "Releasing old memory: " << *value << endl;
	            delete value;
	            value = new int;
	            cout << "New memory allocated." << endl;
	            *value = *(obj.value);
				cout << "Copied value: "<< *value << endl;
	        }
	        else {
				cout << "Self-assignment seen so NO changes made." << endl;
	        }
	        return *this;
	    }
	    
	    void display() {
	
	        cout << "Box value: " << *value << endl;
	    }
	
	    ~Box() {
	        cout << "Destructor releasing memory: " << *value << endl;
	        delete value;
	    }
};


int main() {
	
    Box box1(100);
    Box box2(50); 
    
    /*
        NORMAL ASSIGNMENT:
	        Both objects already exist so, the COPY ASSIGNMENT OPERATOR is called.
	        box2 = box1;
    */
    
    cout << "\nNormal Assignment: box2 = box1" << endl;
    box2 = box1;
    cout << "\nAfter assignment:" << endl;
    cout << "box1 -> ";
    box1.display();
    cout << "box2 -> ";
    box2.display();
    /*
        SELF-ASSIGNMENT:
	            box1 = box1;
				the object is being assigned to itself, the self-assignment check prevents us from
	        	unnecessarily deleting and reallocating memory.
    */
    cout << "\nSelf-Assignment: box1 = box1" << endl;
    box1 = box1;
    cout << "\nAfter self-assignment:" << endl;
    cout << "box1 -> ";
    box1.display();

    return 0;
}
