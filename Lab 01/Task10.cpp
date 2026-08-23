#include <iostream>
#include <string>
using namespace std;

class StudentRecord
{
private:
    string name;
    int* marks;
    int size;

public:
    // Parameterized constructor
    StudentRecord(string n, int s)
    {
        name = n;
        size = s;
        marks = new int[size];

        cout << "Constructor: " << name
             << " | Pointer: " << marks
             << " | Size: " << size << endl;

        for (int i = 0; i < size; i++)
        {
            marks[i] = 0;
        }
    }

    // Deep-copy Copy Constructor
    StudentRecord(const StudentRecord& other)
    {
        name = other.name;
        size = other.size;

        marks = new int[size];

        for (int i = 0; i < size; i++)
        {
            marks[i] = other.marks[i];
        }

        cout << "Copy Constructor: " << name
             << " | New Pointer: " << marks
             << " | Copied From: " << other.marks << endl;
    }

    // Deep-copy Assignment Operator
    StudentRecord& operator=(const StudentRecord& other)
    {
        cout << "Assignment Operator called for " << name << endl;

        // Self-assignment check
        if (this == &other)
        {
            cout << "Self-assignment detected." << endl;
            return *this;
        }

        // Delete old memory
        delete[] marks;

        // Copy basic data
        name = other.name;
        size = other.size;

        // Allocate new memory
        marks = new int[size];

        // Deep copy
        for (int i = 0; i < size; i++)
        {
            marks[i] = other.marks[i];
        }

        cout << "New Pointer: " << marks
             << " | Copied From: " << other.marks << endl;

        return *this;
    }

    // Destructor
    ~StudentRecord()
    {
        cout << "Destructor: " << name
             << " | Deleting Pointer: " << marks << endl;

        delete[] marks;
    }

    // Enter marks
    void enterMarks()
    {
        cout << "Enter " << size << " marks for " << name << ": ";

        for (int i = 0; i < size; i++)
        {
            cin >> marks[i];
        }
    }

    // Display record
    void display() const
    {
        cout << "\nName: " << name << endl;
        cout << "Pointer: " << marks << endl;
        cout << "Marks: ";

        for (int i = 0; i < size; i++)
        {
            cout << marks[i] << " ";
        }

        cout << endl;
    }

    // Modify one mark
    void modifyMark(int index, int newMark)
    {
        if (index >= 0 && index < size)
        {
            marks[index] = newMark;
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }
};


int main()
{
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
