#include <iostream>
using namespace std;

class Students {

	private:
	    int* marks;
	    int size;
	    /* int pointer is part of our object, it points to array dynamically allocated in heap */
	
	public:
	    Students(int studentMarks[], int n) {
	    	
	        size = n;
	        marks = new int[size];
	        
	        for (int i = 0; i < size; i++) {
	            marks[i] = studentMarks[i];
	        }
	    }
	    
	    /*
	        DEEP COPY CONSTRUCTOR:
				it is called when a NEW object is initialized
	        	from an existing object.
	        	
				Example:
	            	Students s2 = s1;
	    */
	    
	    Students(const Students& obj) {
	
	        size = obj.size;
	        marks = new int[size];
	        for (int i = 0; i < size; i++) {
	            marks[i] = obj.marks[i];
	        }
	
	        cout << "Copy constructor called." << endl;
	    }
	    /*
	        DEEP COPY ASSIGNMENT OPERATOR:
					it is called when BOTH objects already exist.
	
	        		Example:
	            		s3 = s1;
	
	    */
	    
	    Students& operator=(const Students& obj) {
	        if (this != &obj) { // this doesnot let self assignment happen
	            delete[] marks; //release the old memory
	            size = obj.size;
	            marks = new int[size];
	            for (int i = 0; i < size; i++) {
	                marks[i] = obj.marks[i];
	            }
	        }
	        cout << "\nCopy assignment operator called." << endl;
	
	        return *this;
	    }
	
	    void display() {
	
	        cout << "Marks: ";
	
	        for (int i = 0; i < size; i++) {
	            cout << marks[i] << " ";
	        }
	
	        cout << endl;
	    }
	
	    void changeMark(int index, int newMark) {
	
	        if (index >= 0 && index < size) {
	            marks[index] = newMark;
	        }
	    }

	    ~Students() {
	        delete[] marks;
	    }
};


int main() {

    int firstMarks[] = {67, 76, 96};
    Students s1(firstMarks, 3); // create the original student


    /*
        COPY CONSTRUCTOR:
	        s2 does NOT exist yet, so this statement calls the copy constructor
			Student s2 = s1;
			A NEW object s2 is created and initialized from s1.
    */

    Students s2 = s1;
    cout << "\nAfter copy constructor:" << endl;
    cout << "s1 -> ";
    s1.display();
    cout << "s2 -> ";
    s2.display();
    s2.changeMark(0, 43);
    cout << "\nAfter modifying s2:" << endl;
    cout << "s1 -> ";
    s1.display();
    cout << "s2 -> ";
    s2.display();

    /*
        COPY ASSIGNMENT OPERATOR:
	
	        s3 ALREADY EXISTS, so this statement calls the COPY ASSIGNMENT OPERATOR:
			s3 = s1;
	        the copy constructor is NOT called here.
	        the existing s3 object receives the data from s1.
    */

    int secondMarks[] = {81, 54, 23};

    Students s3(secondMarks, 3);
    
    cout << "\nBefore assignment:" << endl;
    cout << "s1 -> ";
    s1.display();
    cout << "s3 -> ";
    s3.display();
    s3 = s1;
    cout << "\nAfter s3 = s1:" << endl;
    cout << "s1 -> ";
    s1.display();
    cout << "s3 -> ";
    s3.display();
    s3.changeMark(1, 56);
    cout << "\nAfter modifying s3:" << endl;
    cout << "s1 -> ";
    s1.display();
    cout << "s3 -> ";
    s3.display();


    return 0;
}
