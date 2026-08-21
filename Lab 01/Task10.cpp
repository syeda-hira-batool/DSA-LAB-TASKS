#include <iostream>
#include <cstring>
using namespace std;

class StudentRecord {

	private:
	    char* studentName;
	    int* marks;
	    int size;
	public:
	    StudentRecord(const char* name, int numberOfMarks) {
	        size = numberOfMarks;
	        studentName = new char[strlen(name) + 1];
	        strcpy(studentName, name);
	        marks = new int[size];
	        for (int i = 0; i < size; i++) {
	            marks[i] = 0;
	        }
	        cout << "Created StudentRecord for: " << studentName << endl;
	        cout << "Name memory allocated" << endl;
	        cout << "Marks memory allocated for " << size << " marks" << endl;
	    }
	    
	    StudentRecord(const StudentRecord& obj) {
	    	
	        size = obj.size;
	        studentName = new char[strlen(obj.studentName) + 1];
	        strcpy(studentName, obj.studentName);
	        marks = new int[size];
	        
	        for (int i = 0; i < size; i++) {
	            marks[i] = obj.marks[i];
	        }
	        
	        cout << "Deep copied: " << studentName << endl;
	        cout << "New name memory allocated."<< endl;
			cout << "New marks array allocated."<< endl;
			
	    }
	
	    StudentRecord& operator=(const StudentRecord& obj) {
	    	
	        // Protect against self-assignment
	        if (this != &obj) {
	            cout << "    Releasing old memory of "  << studentName << endl;
	            delete[] studentName;
	            delete[] marks;
	            size = obj.size;
	            studentName = new char[strlen(other.studentName) + 1];
	            strcpy(studentName, obj.studentName);
	            marks = new int[size];
	
	            for (int i = 0; i < size; i++) {
	                marks[i] = other.marks[i];
	            }
	            cout << "New memory allocated for " << studentName << endl;
	        }
	        else {
	            cout << "Self-assignment detected so NO memory changed." << endl;
	        }
	        return *this;
	    }
	    
	    void enterMarks() {
	        cout << "\nEnter " << size << " marks for " << studentName << ":\n";
	        for (int i = 0; i < size; i++) {
	            cout << "Mark " << i + 1 << ": ";
	            cin >> marks[i];
	        }
	    }
	
	    void display() const {
	    	
	        cout << "\nStudent Name: " << studentName << endl;
	        cout << "Marks: ";
	
	        for (int i = 0; i < size; i++) {
	            cout << marks[i] << " ";
	        }
	        
	        cout << endl;
	    }

	    void modifyMark(int index, int newMark) {
	
	        if (index >= 0 && index < size) {
	
	            marks[index] = newMark;
	
	            cout << "Modification of " << studentName << "'s mark " << index + 1 << " changed to " << newMark << endl;
	        }
	        else {
	            cout << "Invalid mark index." << endl;
	        }
	    }
	
	    ~StudentRecord() {
	
	        cout << "Destroying " << studentName << endl;
	        cout << "Releasing name memory" << endl;
	        delete[] studentName;
	        cout << "Releasing marks memory." << endl;
	
	        delete[] marks;
	    }
};


int main() {
    /*
        OBJECT 1:
        student1 owns:

            name memory
            marks memory
    */

    StudentRecord student1("Syeda", 3);
    student1.enterMarks();
    cout << "\n--- Copying student1 into student2 ---"
         << endl;

    StudentRecord student2 = student1;


    cout << "\n--- Current records ---" << endl;

    cout << "\nStudent 1:";
    student1.display();

    cout << "\nStudent 2:";
    student2.display();


    cout << "\n--- Modifying student2 ---" << endl;

    student2.modifyMark(0, 100);


    cout << "\nAfter modification:" << endl;

    cout << "\nStudent 1:";
    student1.display();

    cout << "\nStudent 2:";
    student2.display();


    /*
        =====================================================
        ANOTHER OBJECT
        =====================================================

        student3 already exists.

        Therefore:

            student3 = student1;

        invokes the COPY ASSIGNMENT OPERATOR.
    */

    cout << "\n--- Creating student3 ---" << endl;

    StudentRecord student3("Ali", 2);

    student3.enterMarks();


    cout << "\n--- Assigning student1 to student3 ---"
         << endl;

    student3 = student1;


    cout << "\nAfter assignment:" << endl;

    cout << "\nStudent 1:";
    student1.display();

    cout << "\nStudent 3:";
    student3.display();


    /*
        Modify student3.

        student1 must remain unchanged.
    */

    cout << "\n--- Modifying student3 ---" << endl;

    student3.modifyMark(1, 99);


    cout << "\nAfter modification:" << endl;

    cout << "\nStudent 1:";
    student1.display();

    cout << "\nStudent 3:";
    student3.display();


    /*
        =====================================================
        SELF-ASSIGNMENT
        =====================================================

        student1 is assigned to itself.

            student1 = student1;

        The assignment operator must detect this.
    */

    cout << "\n--- Self-assignment ---" << endl;

    student1 = student1;


    /*
        =====================================================
        INNER SCOPE
        =====================================================

        temporaryStudent and copiedStudent will be
        destroyed when this scope ends.
    */

    cout << "\n--- Entering inner scope ---" << endl;

    {

        StudentRecord temporaryStudent("Sara", 2);

        temporaryStudent.modifyMark(0, 75);
        temporaryStudent.modifyMark(1, 85);


        cout << "\n--- Copying temporaryStudent ---"
             << endl;

        StudentRecord copiedStudent = temporaryStudent;


        cout << "\nTemporary Student:";
        temporaryStudent.display();

        cout << "\nCopied Student:";
        copiedStudent.display();


        cout << "\n--- Modifying copiedStudent ---"
             << endl;

        copiedStudent.modifyMark(0, 100);


        cout << "\nAfter modification:" << endl;

        cout << "\nTemporary Student:";
        temporaryStudent.display();

        cout << "\nCopied Student:";
        copiedStudent.display();


        cout << "\n--- Leaving inner scope ---"
             << endl;
    }


    /*
        temporaryStudent and copiedStudent have now been
        destroyed.

        student1, student2 and student3 are still alive.
    */


    cout << "\n--- Back in main scope ---" << endl;

    cout << "\nStudent 1:";
    student1.display();

    cout << "\nStudent 2:";
    student2.display();

    cout << "\nStudent 3:";
    student3.display();


    cout << "\n========== PROGRAM END ==========\n";

    return 0;
}
