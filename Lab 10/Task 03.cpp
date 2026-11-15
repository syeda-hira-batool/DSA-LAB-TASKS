#include <iostream>
using namespace std;

class HashTable {
	private:
	    static const int SIZE = 11;  // Prime number
	
	    int table[SIZE];
	    int count;
	
	public:
	
	    HashTable() {
	        count = 0;
	
	        for (int i = 0; i < SIZE; i++) {
	            table[i] = -1;
	        }
	    }
	
	    int hashFunction(int id) {
	        return id % SIZE;
	    }
	
	    double loadFactor() {
	        return (double)count / SIZE;
	    }
	
	    void insert(int id) {
	
	        if (loadFactor() > 0.5) {
	            cout << "WARNING: Load Factor exceeds 0.5!" << endl;
	            cout << "Rehash required. Cannot add booking." << endl;
	            return;
	        }
	
	        int index = hashFunction(id);
	
	        for (int j = 0; j < SIZE; j++) {
	
	            int current = (index + j * j) % SIZE;
	
	            if (table[current] == -1) {
	
	                table[current] = id;
	                count++;
	
	                cout << "Booking " << id
	                     << " inserted at index " << current << endl;
	
	                cout << "Current Load Factor: "
	                     << loadFactor() << endl;
	
	                return;
	            }
	
	            if (table[current] == id) {
	                cout << "Booking already exists!" << endl;
	                return;
	            }
	        }
	
	        cout << "No available slot found!" << endl;
	        cout << "Rehash required." << endl;
	    }
	
	    void search(int id) {
	
	        int index = hashFunction(id);
	
	        for (int j = 0; j < SIZE; j++) {
	
	            int current = (index + j * j) % SIZE;
	
	            if (table[current] == -1) {
	                cout << "Booking not found!" << endl;
	                return;
	            }
	
	            if (table[current] == id) {
	                cout << "Booking " << id
	                     << " found at index " << current << endl;
	                return;
	            }
	        }
	
	        cout << "Booking not found!" << endl;
	    }
	
	    void display() {
	
	        cout << "\n--- Theater Booking Table ---\n";
	
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
	
	        cout << "\nTotal Bookings: " << count << endl;
	        cout << "Load Factor: " << loadFactor() << endl;
	    }
};

int main() {

    HashTable theater;

    theater.insert(22);
    theater.insert(33);
    theater.insert(44);
    theater.insert(55);
    theater.insert(66);
    theater.insert(77);

    theater.display();

    cout << "\nSearching Bookings:\n";
    theater.search(44);
    theater.search(99);

    cout << "\nTrying another booking:\n";
    theater.insert(88);

    return 0;
}

