#include <iostream>
#include <cmath>  //for math functions (floor etc..)
using namespace std;

int binarySearch(int arr[], int size, int targetID) {
	
    for (int i = 0; i < size - 1; i++) { //checking for sorted array
    
        if (arr[i] > arr[i + 1]) {
            cout << "Error: Conveyor is unsorted. Search aborted." << endl;
            return -1;
        }
    }
	
	//if sorted: directly apply search:
    int low = 0; 
    int high = size - 1;

    int steps = 0;

    int maxSteps = floor(log2(size)) + 1; //max steps (theory)

    while (low <= high) {
        int mid = low + (high - low) / 2; //middle point

        steps++;
        int remainingItems = high - low + 1;

        double remainingPercentage =
            (double)remainingItems / size * 100;

        cout << "Step " << steps << ":" << endl;
        cout << "Low: " << low << endl;
        cout << "Mid: " << mid << endl;
        cout << "High: " << high << endl;
        cout << "Remaining Search Space: "<< remainingPercentage << "%" << endl;
        cout << "Steps: "<< steps << " / " << maxSteps << endl;

        if (arr[mid] == targetID) {
            cout << "Target found at index: " << mid << endl;
            return mid;
        }

        if (targetID > arr[mid]) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }

        cout << "==================================" << endl;
    }

    cout << "Target not found" << endl;

    return -1;
}


int main() {

    int size;

    cout << "Enter number of items: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter tracking IDs: ";

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int targetID;

    cout << "Enter target tracking ID: ";
    cin >> targetID;

    int result = binarySearch(arr, size, targetID);

    if (result != -1) {
        cout << "Result: Target found at index "<< result << endl;
    }
    else {
        cout << "Result: -1" << endl;
    }

    delete[] arr;

    return 0;
}
