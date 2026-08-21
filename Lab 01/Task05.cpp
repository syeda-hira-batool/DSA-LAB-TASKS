#include <iostream>
#include <cstring>
using namespace std;

class Exam {

	private:
	    char* studentName;
	
	    /*
	        studentName is a pointer that is part of the Exam object.
	        The character array that studentName points to is dynamically
	        allocated on the HEAP.
	
	        STACK                         HEAP
	
	           exam1
	       		|
	        studentName -----------> [S][y][e][d][a][\0]
	        
	    */
	
	public:
	
	    Exam(const char* name) {
	
	        // allocate memory on the HEAP
	        studentName = new char[strlen(name) + 1];
	
	        // copy name into the dynamically allocated memory using cstring function
	        strcpy(studentName, name);
	    }
	
	    void display() {
	        cout << "Student Name: " << studentName << endl;
	    }
	
	    // function to modify the dynamically allocated name
	    void changeName(const char* newName) {
	
	        // copy the new name into the SAME allocated memory
	        strcpy(studentName, newName);
	    }
	
	    /*
	        NO copy constructor is written here.
	
	        so the compiler-generated copy constructor
	        performs a SHALLOW COPY.
	
	        exam2 = exam1;
	
	        This copies the POINTER, not the character array.
	
	        STACK                         HEAP
	
	        	exam1                   [S][y][e][d][a][\0]
	              |         				  +
	         studentName ----------------------
	                        				  |
	            exam2						  |
				   |                          |    
	         studentName ---------------------+
	        
	
	        Both objects point to the SAME memory
	    */
	
	    ~Exam() {
	        delete[] studentName;
	    }
};

int main() {

    // exam1 gets its own dynamically allocated memory
    Exam exam1("Syeda");

    // compiler-generated copy constructor is called and it does shallow copy
    Exam exam2 = exam1;

    cout << "Before modifying exam2:" << endl;

    cout << "Exam 1: ";
    exam1.display();

    cout << "Exam 2: ";
    exam2.display();


    // modify the name through exam2
    exam2.changeName("Hira");

    cout << "\nAfter modifying exam2:" << endl;

    cout << "Exam 1: ";
    exam1.display();

    cout << "Exam 2: ";
    exam2.display();

    return 0;
}
