#include <iostream>
using namespace std;

int main() {
	
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    cout << "\nEnter the elements of the matrix array:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nMatrix Array:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }

    cout << "\nSum of all elements: " << sum << endl;

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    
    delete[] arr;

    return 0;
}
