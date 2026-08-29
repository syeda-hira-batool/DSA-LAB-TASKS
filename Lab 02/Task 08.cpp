#include <iostream>
using namespace std;

int main() {

    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    int* rowSize = new int[rows];

    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) {

        cout << "Enter the size of row " << i << ": ";
        cin >> rowSize[i];

        arr[i] = new int[rowSize[i]];

        cout << "Enter " << rowSize[i] << " elements: ";

        for (int j = 0; j < rowSize[i]; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nJagged Array:" << endl;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < rowSize[i]; j++) {
            cout << arr[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nMaximum value of each row:" << endl;

    for (int i = 0; i < rows; i++) {

        int max= arr[i][0];

        for (int j = 1; j < rowSize[i]; j++) {

            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }

        cout << "Row " << i << ": " << max << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] rowSize;

    return 0;
}
