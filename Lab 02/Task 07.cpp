#include <iostream>
using namespace std;

int main() {

    int n;
    int startIndex;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the starting index: ";
    cin >> startIndex;

    int* arr = new int[n];

    cout << "\nEnter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter value at index " << startIndex + i << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Array elements at Index " << startIndex + i
             << ": " << arr[i] << endl;
    }

    int choice;
    int index;

    cout << "\nChoose an operation:" << endl;
    cout << "1. Access an element" << endl;
    cout << "2. Modify an element" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the index you want to access: ";
    cin >> index;

    int endIndex = startIndex + n - 1;

    if (index >= startIndex && index <= endIndex) {

        int position = index - startIndex;

        switch (choice) {

            case 1:
                cout << "Value at index " << index << ": " << arr[position] << endl;
                break;

            case 2: {
                int newValue;

                cout << "Enter the new value: ";
                cin >> newValue;

                arr[position] = newValue;

                cout << "Value modified" << endl;
                cout << "New value at index " << index << ": "
                     << arr[position] << endl;

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
