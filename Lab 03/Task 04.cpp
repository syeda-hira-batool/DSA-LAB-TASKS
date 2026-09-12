#include <iostream>
using namespace std;

int arr[] = {67, 6, 7, 3, 20};
int size = 5;
//global scope

void diminishingDistanceScanner(int arr[], int size) {

    int gap = size / 2;
    
    while (gap >= 1) {
    	
        int comparisons = 0;
        int swaps = 0;
        
        for (int i = gap; i < size; i++) {  //it is a shell sort
            int j = i;
            
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > arr[j]) {

                    int temp = arr[j]; //actual swapping
                    arr[j] = arr[j - gap];
                    arr[j - gap] = temp;
                    swaps++;
                    j = j - gap;
                }
                else {
                    break;
                }
            }
        }
        
        double gapPercentage = (double)gap / size * 100; //gap as % of array size
		cout << "========================" << endl;
        cout << "Gap: " << gap << endl;
        cout << "Gap Percentage: " << gapPercentage << "%" << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "=======================" << endl;

        gap = gap / 2;
    }
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
    diminishingDistanceScanner(arr, size);
    cout<<"Array after sorting: " << endl;
    display();

    return 0;
    
}
