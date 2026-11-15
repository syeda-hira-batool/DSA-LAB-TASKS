#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string tag;
    int count;
    Node* next;

    Node(string t) {
        tag = t;
        count = 1;
        next = NULL;
    }
};

class HashTable {
private:
    static const int SIZE = 10;
    Node* table[SIZE];

public:

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    int hashFunction(string tag) {

        int sum = 0;

        for (int i = 0; i < tag.length(); i++) {
            sum = sum + tag[i];
        }

        return sum % SIZE;
    }

    void insert(string tag) {

        int index = hashFunction(tag);

        Node* temp = table[index];

        while (temp != NULL) {

            if (temp->tag == tag) {
                temp->count++;

                cout << tag << " usage increased to "<< temp->count << endl;

                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(tag);

        newNode->next = table[index];

        table[index] = newNode;

        cout << tag << " inserted successfully" << endl;
        checkOverload();
    }

    int search(string tag) {

        int index = hashFunction(tag);

        Node* temp = table[index];

        while (temp != NULL) {

            if (temp->tag == tag) {
                return temp->count;
            }

            temp = temp->next;
        }

        return -1;
    }

    void remove(string tag) {

        int index = hashFunction(tag);

        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL) {

            if (temp->tag == tag) {

                if (prev == NULL) {
                    table[index] = temp->next;
                }

                else {
                    prev->next = temp->next;
                }

                delete temp;

                cout << tag << " removed successfully"<< endl;

                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << tag << " not found" << endl;
    }

    int longestChain() {

        int maxLength = 0;

        for (int i = 0; i < SIZE; i++) {

            int length = 0;

            Node* temp = table[i];

            while (temp != NULL) {
                length++;
                temp = temp->next;
            }

            if (length > maxLength) {
                maxLength = length;
            }
        }

        return maxLength;
    }

    void checkOverload() {

        int longest = longestChain();

        cout << "Longest Chain: " << longest << endl;

        if (longest > 5) {
            cout << "WARNING: SYSTEM OVERLOAD!"<< endl;
        }
    }

    void display() {

        cout << "\nHASH TABLE" << endl;

        for (int i = 0; i < SIZE; i++) {

            cout << i << " -> ";

            Node* temp = table[i];

            while (temp != NULL) {

                cout << "[" << temp->tag<< ", Count: " << temp->count << "] -> ";

                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }
    
    ~HashTable() {

        for (int i = 0; i < SIZE; i++) {

            Node* temp = table[i];

            while (temp != NULL) {

                Node* del = temp;
                temp = temp->next;

                delete del;
            }
        }
    }
};

int main() {

    HashTable ht;

    cout << "INSERTING HASHTAGS" << endl;

    ht.insert("#cat");
    ht.insert("#dog");
    ht.insert("#sun");
    ht.insert("#fun");
    ht.insert("#hot");
    ht.insert("#cool");

    ht.insert("#cat");
    ht.insert("#cat");

    ht.display();

    cout << "\nSEARCHING HASHTAG" << endl;

    int result = ht.search("#cat");

    if (result != -1) {
        cout << "#cat used " << result<< " times" << endl;
    }
    
    else {
        cout << "Hashtag not found" << endl;
    }

    cout << "\nREMOVING BANNED HASHTAG" << endl;

    ht.remove("#dog");

    ht.display();

    cout << "\nLongest Chain in Table: "<< ht.longestChain() << endl;

    return 0;
}

