#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
	private:
	    string name;
	    int* marks;
	    int size;
		// Private data hides the student's name, marks array, and number of marks
		// from outside code, enforcing the ADT's encapsulation

	public:
		// Parameterized constructor creates a separate heap array for each object
		// This object becomes the only one to hold its dynamically allocated marks
	    StudentRecord(string n, int s) {
	        name = n;
	        size = s;
	        marks = new int[size];
	
	        cout << "Constructor: " << name
	             << " | Pointer: " << marks
	             << " | Size: " << size << endl;
	
	        for (int i = 0; i < size; i++) {
	            marks[i] = 0;
	        }
	    }
		// Deep-copy constructor creates a new array and copies the marks values
		// The new object owns its own memory instead of sharing the source object's array
	    StudentRecord(const StudentRecord& other) {
	        name = other.name;
	        size = other.size;
	
	        marks = new int[size];
	
	        for (int i = 0; i < size; i++) {
	            marks[i] = other.marks[i];
	        }
	
	        cout << "Copy Constructor: " << name
	             << " | New Pointer: " << marks
	             << " | Copied From: " << other.marks << endl;
	    }
		// Deep-copy assignment first releases the current array, then allocates
		// new memory and copies the values so both objects remain independent
	    StudentRecord& operator=(const StudentRecord& other) {
	        cout << "Assignment Operator called for " << name << endl;
	
	        if (this == &other) {
	            cout << "Self-assignment detected." << endl; 
				// Self-assignment check prevents an object from deleting its own data
				// before copying it back to itself
	            return *this;
	        }
	
	        delete[] marks; // Free existing memory
	
	        name = other.name;
	        size = other.size;
	
	        marks = new int[size];
	
	        for (int i = 0; i < size; i++) {
	            marks[i] = other.marks[i];
	        }
	
	        cout << "New Pointer: " << marks
	             << " | Copied From: " << other.marks << endl;
	
	        return *this;
	    }

	    ~StudentRecord() {
	        cout << "Destructor: " << name
	             << " | Deleting Pointer: " << marks << endl;
	
	        delete[] marks;
	    }
		// Destructor releases the heap memory owned by this object
	
	    void enterMarks() {
	        cout << "Enter " << size << " marks for " << name << ": ";
	        for (int i = 0; i < size; i++) {
	            cin >> marks[i];
	        }
	    }
	
	    void display() const {
	        cout << "\nName: " << name << endl;
	        cout << "Pointer: " << marks << endl;
	        cout << "Marks: ";
	
	        for (int i = 0; i < size; i++) {
	            cout << marks[i] << " ";
	        }
	        cout << endl;
	    }
	
		// Modifying one object does not affect its copy because each object
		// has a different heap allocation

	    void modifyMark(int index, int newMark) {
	        if (index >= 0 && index < size) {
	            marks[index] = newMark;
	        } else {
	            cout << "Invalid index!" << endl;
	        }
	    }
};

int main() {
    StudentRecord s1("Ali", 2);
    s1.enterMarks();
    StudentRecord s2 = s1; //copy constructor
    cout << "\nAfter copying s1 -> s2:" << endl;
    s1.display();
    s2.display();
    s2.modifyMark(0, 67);
    cout << "s1 after modifying s2:" << endl;
    s1.display();
    cout << "s2 after modifying s2:" << endl;
    s2.display();
    StudentRecord s3("batool", 2);
    s3.enterMarks();
    s3 = s1; //assigment
    s3.display();
    s3.modifyMark(1, 77);
    cout << "s1 after modifying s3:" << endl;
    s1.display();
    cout << "s3 after modifying s3:" << endl;
    s3.display();
    s1 = s1; //self assigment

    cout << "\n--- INNER SCOPE ---" << endl;
    {
        StudentRecord s4 = s3;

        cout << "\ns4 after copying s3:" << endl;
        s4.display();

        s4.modifyMark(0, 55);

        cout << "\ns3 after modifying s4:" << endl;
        s3.display();

        cout << "\ns4 after modification:" << endl;
        s4.display();

        cout << "\n---exit inner scope---" << endl;
    }

    cout << "\n--- BACK IN MAIN ---" << endl;
    s1.display();
    s2.display();
    s3.display();

    return 0;
}

/*
Shallow copying makes two objects point to the same dynamically allocated array,
which can cause shared data, dangling pointers, double deletion, and undefined behavior.
Shallow copying copies pointer addresses instead of allocating new heap memory, causing two 
objects to share one array; this leads to unexpected shared modifications and a double 
deletion crash when both destructors call delete[] on the same memory.
*/
