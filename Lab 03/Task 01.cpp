#include <iostream>
#include <utility>
using namespace std;

int arr[] = {67, 6, 7, 3, 20};
int size = 5;
//global scope

void adjacentSwapper(int arr[], int size) {
	
    int swaps = 0;
    int comp = 0;
    int pass = 0;

    // it is a Bubble Sort
    for (int i = 0; i < size - 1; i++){
    	
        bool swapped = false;
        pass++;
        
        for (int j = 0; j < size - 1 - i; j++){
            comp++;
            if (arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j+1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped){
            break; //condition for already sorted array
        }
    }

    int worstCaseComp = size * (size - 1) / 2; //worst-case no of comparisions
    int worstCasePass = size - 1; //worst case no of passes
    int passesSaved = worstCasePass - pass; //saved pass

    cout << "Total swaps: " << swaps << endl;
    cout << "Total comparisons: " << comp << endl;
    cout << "Passes saved: " << passesSaved << endl;

    cout << "Actual comparisons: " << comp << endl;
    cout << "Calculated worst-case comparisons: " << worstCaseComp << endl;
}

void display(){
	for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){ 

	cout<<"Array before sorting: " << endl;
	display();
	cout<<"Array after sorting: " << endl;
    adjacentSwapper(arr, size);
    display();

    return 0;
}
