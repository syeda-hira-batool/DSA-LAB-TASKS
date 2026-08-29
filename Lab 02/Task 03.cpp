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

    for (int i = 0; i < n; i++) {
        cout << "Array Elements at Index " << i << ": " << arr[i] << endl;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "\nSum of all elements: " << sum << endl;

    delete[] arr;

    return 0;
}
