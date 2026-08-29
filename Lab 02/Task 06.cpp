#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index;
    int choice;

    // asking the user what operation they want
    
    cout << "\nChoose an operation:" << endl;
    cout << "1. Access an element" << endl;
    cout << "2. Modify an element" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    cout << "Enter the index: ";
    cin >> index;

    // validating the index before accessing the array (safe array implementation)
    
    if (index >= 0 && index < n) {

        switch (choice) {

            case 1:
                cout << "Element at index " << index << ": " << arr[index] << endl;
                break;

            case 2: {
                int newValue;

                cout << "Enter the new value: ";
                cin >> newValue;

                arr[index] = newValue;

                cout << "Element is modified" << endl;
                cout << "New value at index " << index << ": "
                     << arr[index] << endl;

                break;
            }

            default:
                cout << "Invalid operation choice." << endl;
        }

    }
    else {
        cout << "Invalid index!" << endl;
    }

    delete[] arr;

    return 0;
}
