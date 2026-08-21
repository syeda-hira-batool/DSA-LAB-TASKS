#include <iostream>
#include <cstring>
using namespace std;

class Exam {
	
	private:
	    char* studentName;
	    
	    /* the char pointer is the part of our Exam object, it points to studentName character array 
	which is dynamically located in the heap 
	
	*char ---> [][][][][]
	
	*/
	
	public:
		
	    Exam(const char* name){ //this is a parameterized constructor
	        studentName = new char[strlen(name) + 1]; //allocate memory on the heap
	        strcpy(studentName, name); //cstring function: copy the name into the heap
	        cout<<"Memory Allocated for: " << studentName << endl;
	    }
	    
	    void display(){
	        cout << "Student Name: " << studentName << endl;
	    }
	    
	    ~Exam(){ //this is the destructor: runs in reverse order as constructor
	        cout << "Memory Released for: " << studentName << endl;
	        delete[] studentName;  //this releases the memory
	    }
};

int main() {
	
    /*each object is stored on the STACK, but each object's studentName points to a DIFFERENT 
	dynamically allocated character array on the HEAP */
    
	Exam exam1("Syeda"); 
    Exam exam2("Hira");
    Exam exam3("Batool");
    
	cout << "\n----------EXAMS----------\n";
    cout << "Exam 1: ";
    exam1.display();
    cout << "Exam 2: ";
    exam2.display();
    cout << "Exam 3: ";
    exam3.display();
    cout << "--------------------------\n";
    
    /*    
    stack visual: 
    
    exam1 ---------> [H][i][r][a][\0]

	*/

    return 0;
    
}
