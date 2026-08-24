#include <iostream>
#include <string>
using namespace std;

class StudentRecord{
	private:
	    string name;
	    int* marks;
	    int size;
	
	public:
	    
	    StudentRecord(string n, int s){
	        name = n;
	        size = s;
	        marks = new int[size];
	
	        cout << "Constructor: " << name
	             << " | Pointer: " << marks
	             << " | Size: " << size << endl;
	
	        for (int i = 0; i < size; i++){
	            marks[i] = 0;
	        }
	    }
	
	    StudentRecord(const StudentRecord& other){
	        name = other.name;
	        size = other.size;
	
	        marks = new int[size];
	
	        for (int i = 0; i < size; i++){
	            marks[i] = other.marks[i];
	        }
	
	        cout << "Copy Constructor: " << name
	             << " | New Pointer: " << marks
	             << " | Copied From: " << other.marks << endl;
	    }
	
	    StudentRecord& operator=(const StudentRecord& other){
	        cout << "Assignment Operator called for " << name << endl;
	
	        if (this == &other){
	            cout << "Self-assignment detected." << endl;
	            return *this;
	        }
	
	        delete[] marks;
	
	        name = other.name;
	        size = other.size;
	
	        marks = new int[size];
	
	        for (int i = 0; i < size; i++){
	            marks[i] = other.marks[i];
	        }
	
	        cout << "New Pointer: " << marks
	             << " | Copied From: " << other.marks << endl;
	
	        return *this;
	    }
	
	    ~StudentRecord(){
	        cout << "Destructor: " << name
	             << " | Deleting Pointer: " << marks << endl;
	
	        delete[] marks;
	    }
	
	    void enterMarks(){
	        cout << "Enter " << size << " marks for " << name << ": ";
	
	        for (int i = 0; i < size; i++){
	            cin >> marks[i];
	        }
	    }

	    void display() const{
	        cout << "\nName: " << name << endl;
	        cout << "Pointer: " << marks << endl;
	        cout << "Marks: ";
	
	        for (int i = 0; i < size; i++){
	            cout << marks[i] << " ";
	        }
	
	        cout << endl;
	    }
	
	    void modifyMark(int index, int newMark){
	        if (index >= 0 && index < size){
	            marks[index] = newMark;
	        }
	        else{
	            cout << "Invalid index!" << endl;
	        }
	    }
};


int main(){
    cout << "---- OBJECT A ----" << endl;

    StudentRecord A("Ali", 3);
    A.enterMarks();

    cout << "\n---- COPY CONSTRUCTOR -----" << endl;

    StudentRecord B = A;

    cout << "\nAfter copying A -> B:" << endl;
    A.display();
    B.display();

    cout << "\n---- MODIFY B -----" << endl;

    B.modifyMark(0, 99);

    cout << "A after modifying B:" << endl;
    A.display();

    cout << "B after modifying B:" << endl;
    B.display();

    cout << "\n---- OBJECT C ----" << endl;

    StudentRecord C("Sara", 4);
    C.enterMarks();

    cout << "\n---- ASSIGNMENT C = A ----" << endl;

    C = A;

    C.display();

    cout << "\n---- MODIFY C ----" << endl;

    C.modifyMark(1, 77);

    cout << "A after modifying C:" << endl;
    A.display();

    cout << "C after modifying C:" << endl;
    C.display();

    cout << "\n===== SELF ASSIGNMENT =====" << endl;

    A = A;

    cout << "\n===== INNER SCOPE =====" << endl;

    {
        StudentRecord D = C;

        cout << "\nD after copying C:" << endl;
        D.display();

        D.modifyMark(0, 55);

        cout << "\nC after modifying D:" << endl;
        C.display();

        cout << "\nD after modification:" << endl;
        D.display();

        cout << "\nLeaving inner scope" << endl;
    }

    cout << "\n===== BACK IN MAIN =====" << endl;

    A.display();
    B.display();
    C.display();


    return 0;
}



// Private data hides the student's name, marks array, and number of marks
// from outside code, enforcing the ADT's encapsulation

// Parameterized constructor creates a separate heap array for each object
// This object becomes the only one to hold its dynamically allocated marks

// Destructor releases the heap memory owned by this object

// Deep-copy constructor creates a new array and copies the marks values
// The new object owns its own memory instead of sharing the source object's array

// Deep-copy assignment first releases the current array, then allocates
// new memory and copies the values so both objects remain independent

// Self-assignment check prevents an object from deleting its own data
// before copying it back to itself

// Modifying one object does not affect its copy because each object
// has a different heap allocation

// Pointer, heap allocation, ownership, and lifetime are tracked here
// to verify the predicted memory behavior using debug output


// Shallow copying makes two objects point to the same dynamically allocated array,
// which can cause shared data, dangling pointers, double deletion, and undefined behavior.

// Shows which object is being constructed and the address of its heap allocation.

// Shows the object copying another object and confirms that a new heap allocation
// is created for the copied marks.

// Shows that assignment gives the destination its own independent heap memory.

// Shows that modifying one object does not modify the copied object's marks.

// Shows that self-assignment is detected and handled safely.

// Shows when an object leaves scope and its destructor releases its owned memory.

