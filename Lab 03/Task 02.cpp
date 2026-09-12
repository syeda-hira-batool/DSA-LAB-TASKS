#include <iostream>
using namespace std;

int arr[] = {67, 6, 7, 3, 20};
int size = 5;
//global scope

void insertionArmSorter(int arr[], int size) {
	
    int totalShift = 0;
    
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        int shiftCount = 0;
        
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
            shiftCount++;
        }
        
        arr[j + 1] = key;
        cout << "Key: " << key << endl;
        
        if (shiftCount == 0){
            cout << "No shifting" << endl;
        }
        
        else{
            cout << "Shifting: " << shiftCount << " positions" << endl;
        }
        
        totalShift += shiftCount;
        cout << "Current array: ";
        
        for (int k = 0; k < size; k++){
            cout << arr[k] << " ";
        }
        cout << endl << endl;
    }
    
    cout << "Total shift distance: " << totalShift << endl;
}

int main(){

    insertionArmSorter(arr, size);

    return 0;
}
