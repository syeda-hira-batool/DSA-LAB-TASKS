#include <iostream>
#include <cstring>
using namespace std;

class Exam {

	private:
	    char* studentName;
	
	public:
	    Exam(const char* name) {
	        studentName = new char[strlen(name) + 1];
	        strcpy(studentName, name);
	    }
	    /*
	        DEEP COPY CONSTRUCTOR:
				Instead of copying only the pointer, we create a NEW
	        	character array and copy the actual name into it.
	    */
	    Exam(const Exam& other) {
	
	        // allocate NEW memory on the heap
	        studentName = new char[strlen(other.studentName) + 1];
	
	        // copy the ACTUAL NAME into the NEW memory
	        strcpy(studentName, other.studentName);
	    }
	    
	    void display() {
	        cout << "Student Name: " << studentName << endl;
	    }
	
	    // change the student's name
	    void changeName(const char* newName) {
	        strcpy(studentName, newName);
	    }

	    ~Exam() {
	        delete[] studentName;
	    }
};

int main() {

    Exam exam1("Syeda");

    /*
        BEFORE DEEP COPY:

        STACK                         HEAP

        	exam1
        	  |
          studentName ----------------> [S][y][e][d][a][\0]
          
    */


    // copy exam1 into exam2
    
    Exam exam2 = exam1;

    /*
        AFTER DEEP COPY:

        STACK                         HEAP

      		 exam1
        	  |
          studentName ----------------> [S][y][e][d][a][\0]
       


        	exam1
        	  |
          studentName ---------------->[S][y][e][d][a][\0]
          

        The two pointers are DIFFERENT.
        The two character arrays are also DIFFERENT.

        They contain the same value, but occupy separate
        memory locations on the heap, later we will change the value using our modify function
        
    */


    cout << "Before modifying exam2:" << endl;

    cout << "Exam 1: ";
    exam1.display();

    cout << "Exam 2: ";
    exam2.display();


    // modify exam2
    exam2.changeName("Hira");


    cout << "\nAfter modifying exam2:" << endl;

    cout << "Exam 1: ";
    exam1.display();

    cout << "Exam 2: ";
    exam2.display();


    return 0;
}
