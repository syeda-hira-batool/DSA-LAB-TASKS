#include <iostream>
using namespace std;

int arr[] = {67, 6, 7, 3, 20};
int size = 5;
//global scope 

void minimalSwapCrane(int arr[], int size) {

    int swaps = 0;
    int skipped = 0;

    for (int i = 0; i < size - 1; i++) { //it is a selection sort
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex == i) { //checking if swap needed
            skipped++;
        }
        else {
            int temp = arr[i]; //the actual swapping 
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    
    int totalComp = size * (size - 1) / 2; //total formula
    double ratio = (double)swaps / totalComp * 100;


    cout << "Total Actual Swaps: " << swaps << endl;
    cout << "Number of Skipped Swaps: " << skipped << endl;
    cout << "Total Comparisons: " << totalComp << endl;
    cout << "Swap-to-Comparison Ratio: "<< ratio << "%" << endl;
    
}

void display(){
	for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
	
	cout<<"Array before sorting: " << endl;
    display();
    minimalSwapCrane(arr, size);
    cout<<"Array after sorting: " << endl;
	display();
	
    return 0;
}
