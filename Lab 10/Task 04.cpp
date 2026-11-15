#include <iostream>
using namespace std;

class HashTable {
	private:
	    static const int SIZE = 11;
	    static const int PRIME = 7;
	
	    int table[SIZE];
	    int count;
	
	public:
	
	    HashTable() {
	        count = 0;
	
	        for (int i = 0; i < SIZE; i++) {
	            table[i] = -1;
	        }
	    }
	
	    int hash1(int key) {
	        return key % SIZE;
	    }
	    
	    int hash2(int key) {
	        return PRIME - (key % PRIME);
	    }
	
	    void insert(int key) {
	
	        int index = hash1(key);
	        int step = hash2(key);
	
	        cout << "\nInserting key: " << key << endl;
	
	        for (int j = 0; j < SIZE; j++) {
	
	            int current = (index + j * step) % SIZE;
	
	            if (table[current] == -1) {
	
	                table[current] = key;
	                count++;
	
	                cout << "Key inserted at index "
	                     << current << endl;
	
	                cout << "Total probes: " << j + 1 << endl;
	
	                return;
	            }
	
	            if (table[current] == key) {
	                cout << "Key already exists!" << endl;
	                cout << "Total probes: " << j + 1 << endl;
	                return;
	            }
	        }
	
	        cout << "VAULT FULL! No available slot found."
	             << endl;
	    }
	
	    void search(int key) {
	
	        int index = hash1(key);
	        int step = hash2(key);
	
	        for (int j = 0; j < SIZE; j++) {
	
	            int current = (index + j * step) % SIZE;
	
	            if (table[current] == -1) {
	                cout << "Key " << key << " not found!"
	                     << endl;
	                return;
	            }
	
	            if (table[current] == key) {
	                cout << "Key " << key
	                     << " found at index " << current
	                     << endl;
	                return;
	            }
	        }
	
	        cout << "Key not found after checking all slots!"<< endl;
	    }
	
	    void display() {
	
	        cout << "\n--- Bank Vault Table ---\n";
	
	        for (int i = 0; i < SIZE; i++) {
	
	            cout << "Index " << i << " : ";
	
	            if (table[i] == -1) {
	                cout << "EMPTY";
	            }
	            else {
	                cout << table[i];
	            }
	
	            cout << endl;
	        }
	
	        cout << "\nTotal stored keys: " << count << endl;
	    }
};

int main() {

    HashTable bank;

    bank.insert(22);
    bank.insert(33);
    bank.insert(44);
    bank.insert(55);
    bank.insert(66);

    bank.display();

    cout << "\nSearching Vault Codes:\n";
    bank.search(44);
    bank.search(99);

    return 0;
}

