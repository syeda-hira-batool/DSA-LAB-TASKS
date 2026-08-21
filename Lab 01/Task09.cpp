 #include <iostream>
using namespace std;

class Box {

	private:
	    int* value;
	    
	public:
	    Box(int num) {
	        value = new int;
	        *value = num;
	    }
	    
		// RULE 1: COPY CONSTRUCTOR:
	    Box(const Box& obj) {
	        value = new int;
	        *value = *(obj.value);
	    }
	    
		// RULE 2: COPY ASSIGNMENT OPERATOR:
	    Box& operator=(const Box& obj) {
	        cout << "Assignment Operator called" << endl;
	        if (this != &obj) {
	            cout << "Releasing old memory containing: " << *value << endl;
	            delete value;
	            value = new int;
	            *value = *(obj.value);
	            cout << "New memory allocated with value: " << *value << endl;
	        }
	        else {
	            cout << "Self-assignment detected " << "No changes made." << endl;
	        }
	        return *this;
	    }
	    
	    void setValue(int num) {
	        *value = num;
			cout << "Box value changed to: " << *value << endl;
	    }
	    
	    void display() const {
	        cout << "Box value: " << *value << endl;
	    }
	    
	    // RULE 3: DESTRUCTOR:
	    ~Box() {
	        cout << "Releasing Box memory containing: " << *value << endl;
	        delete value;
	    }
};


int main() {

    Box box1(67);
    cout << "box1: ";
    box1.display();
    cout << "\nCreating box2 using copy constructor:" << endl;
    Box box2 = box1;
    cout << "\nAfter copying:" << endl;
    cout << "box1: ";
    box1.display();
    cout << "box2: ";
    box2.display();
    box2.setValue(76);
    cout << "\nAfter modification:" << endl;
    cout << "box1: ";
    box1.display();
    cout << "box2: ";
    box2.display();
    Box box3(88);
    box3 = box1;
    cout << "\nAfter assignment:" << endl;
    cout << "box1: ";
    box1.display();
    cout << "box3: ";
    box3.display();
    box3.setValue(55);
    cout << "\nAfter modification:" << endl;
    cout << "box1: ";
    box1.display();
    cout << "box3: ";
    box3.display();
    //qs says: "several objects and operations such as construction, 
	//copying, assignment, modification, and destruction in different scopes"
    cout << "\nEntering inner scope:" << endl;
    {
        Box box4(22);
        cout << "box4: ";
        box4.display();
        Box box5 = box4;
        cout << "box4: ";
        box4.display();
        cout << "box5: ";
        box5.display();
        box5.setValue(45);
        cout << "\nAfter modification:" << endl;
        cout << "box4: ";
        box4.display();
        cout << "box5: ";
        box5.display();
        cout << "\nLeaving inner scope" << endl;
    }
    /*
        box4 and box5 are destroyed here.
		their destructors release their OWN heap memory, box1, box2 and box3 are still alive.
    */
    cout << "\nBack in main scope:" << endl;
    cout << "box1: ";
    box1.display();
    cout << "box2: ";
    box2.display();
    cout << "box3: ";
    box3.display();

    return 0;
}
