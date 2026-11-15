#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;

    int table[SIZE];
    int status[SIZE];
    // 0 = Empty
    // 1 = Occupied
    // 2 = Deleted

public:

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
            status[i] = 0;
        }
    }

    int hashFunction(int id) {
        return id % SIZE;
    }
    
    void insert(int id) {

        int index = hashFunction(id);
        int probes = 0;

        for (int i = 0; i < SIZE; i++) {

            int current = (index + i) % SIZE;
            probes++;

            if (status[current] == 0 || status[current] == 2) {

                table[current] = id;
                status[current] = 1;

                cout << "Package " << id<< " inserted at index " << current << endl;

                cout << "Probes made: " << probes << endl;

                return;
            }

            if (status[current] == 1 && table[current] == id) {
                cout << "Package already exists!" << endl;
                cout << "Probes made: " << probes << endl;
                return;
            }
        }

        cout << "Hash Table is FULL!" << endl;
        cout << "Probes made: " << probes << endl;
    }

    void search(int id) {

        int index = hashFunction(id);

        for (int i = 0; i < SIZE; i++) {

            int current = (index + i) % SIZE;

            if (status[current] == 0) {
                cout << "Package " << id << " not found!" << endl;
                return;
            }

            if (status[current] == 1 && table[current] == id) {
                cout << "Package " << id
                     << " found at index " << current << endl;
                return;
            }

        }

        cout << "Package " << id << " not found!" << endl;
    }

    void remove(int id) {

        int index = hashFunction(id);

        for (int i = 0; i < SIZE; i++) {

            int current = (index + i) % SIZE;

            if (status[current] == 0) {
                cout << "Package not found!" << endl;
                return;
            }

            if (status[current] == 1 && table[current] == id) {

                status[current] = 2;

                cout << "Package " << id
                     << " deleted successfully!" << endl;

                return;
            }
        }

        cout << "Package not found!" << endl;
    }

    void display() {

        cout << "\n--- Warehouse Locker Status ---\n";

        for (int i = 0; i < SIZE; i++) {

            cout << "Index " << i << " : ";

            if (status[i] == 0) {
                cout << "EMPTY";
            }
            else if (status[i] == 2) {
                cout << "DELETED";
            }
            else {
                cout << table[i];
            }

            cout << endl;
        }
    }
};

int main() {

    HashTable warehouse;

    warehouse.insert(25);
    warehouse.insert(35);
    warehouse.insert(45);
    warehouse.insert(15);
    warehouse.insert(55);

    warehouse.display();

    cout << "\nSearching Packages:\n";
    warehouse.search(45);
    warehouse.search(100);

    cout << "\nDeleting Package:\n";
    warehouse.remove(35);

    cout << "\nSearching after deletion:\n";
    warehouse.search(45);

    warehouse.display();

    return 0;
}

