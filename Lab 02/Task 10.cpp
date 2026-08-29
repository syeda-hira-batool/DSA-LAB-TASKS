#include <iostream>
using namespace std;

int main() {
	
	/*
     -------------------
      Dynamic 1D Array: 
     -------------------
    */

    int n;

    cout << "Enter the size of the 1D array: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal 1D Array:" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int newSize;

    cout << "\n\nEnter the new size of the array: ";
    cin >> newSize;
    int* newArr = new int[newSize];

    // copy the existing values : 
    
    int lastIndex;

    if (n < newSize)
        lastIndex = n;
    else
        lastIndex = newSize;

    for (int i = 0; i < lastIndex; i++) {
        newArr[i] = arr[i];
    }

    // initialize new elements if the array is larger:
    for (int i = lastIndex; i < newSize; i++) {
        newArr[i] = 0;
    }
    
    // delete the old array
    delete[] arr;

    // making the arr point to the new array
    arr = newArr;
    n = newSize;
    
    cout << "\nResized 1D Array:" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
	
	//safe access implementation:

    int choice;
    int index;

    cout << "\n\nChoose an operation:" << endl;
    cout << "1. Access an element" << endl;
    cout << "2. Modify an element" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the index: ";
    cin >> index;

    if (index >= 0 && index < n) {

        switch (choice) {

            case 1:
                cout << "Value at index " << index << ": " << arr[index] << endl;
                break;

            case 2: {
                int value;
                cout << "Enter the new value: ";
                cin >> value;
                arr[index] = value;
                cout << "Value successfully modified." << endl;
                cout << "New value at index " << index << ": " << arr[index] << endl;

                break;
            }

            default:
                cout << "Invalid operation choice." << endl;
        }

    }
    else {
        cout << "Invalid index!" << endl;
    }

    /*
     --------------
      Jagged Array: 
     -------------- 
    */

    int rows;
    
    cout << "\n\nEnter the number of rows for the jagged array: ";
    cin >> rows;
    int* rowSize = new int[rows];
    int** jagged = new int*[rows];

    for (int i = 0; i < rows; i++) {

        cout << "Enter the size of row " << i << ": ";
        cin >> rowSize[i];

        jagged[i] = new int[rowSize[i]];

        cout << "Enter " << rowSize[i] << " elements:" << endl;

        for (int j = 0; j < rowSize[i]; j++) {
            cin >> jagged[i][j];
        }
    }
    
    cout << "\nJagged Array:" << endl;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < rowSize[i]; j++) {
            cout << jagged[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nMaximum value of each row:" << endl;

    for (int i = 0; i < rows; i++) {

        int max = jagged[i][0];

        for (int j = 1; j < rowSize[i]; j++) {

            if (jagged[i][j] > max) {
                max = jagged[i][j];
            }
        }

        cout << "Row " << i << " Size: " << rowSize[i] << endl;
        cout << "Row " << i << " Maximum: " << max << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] jagged[i];
    }
    
    delete[] jagged;
    delete[] rowSize;
    delete[] arr;

    return 0;
    
}
