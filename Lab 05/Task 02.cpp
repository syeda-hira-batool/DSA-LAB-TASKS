#include <iostream>
using namespace std;

const int n = 100;

string undoStack[n];
string redoStack[n];

class Editor {
	
	public:
	    int utop;
	    int rtop;
	
	    string text;
	
	    Editor() {
	        utop = -1;
	        rtop = -1;
	        text = "";
	    }
	
	    bool isUEmpty(){ 
			if(utop == -1){ 
				cout << "The redo stack is empty" << endl;
					return true; 
			} 
			else{ 
				return false; 
			} 
		}
		
		bool isREmpty(){ 
			if(rtop == -1){ 
				cout << "The redo stack is empty" << endl;
					return true; 
			} 
			else{ 
				return false; 
			} 
		} 
		
		bool isUFull(){ 
			if(utop == n-1){ 
				cout << "Redo Stack is full" << endl; 
				return true; 
			} 
			else{ 
				return false; 
			} 
		}
		
		bool isRFull(){ 
			if(rtop == n-1){ 
				cout << "Redo Stack is full" << endl; 
				return true; 
			} 
			else{ 
				return false; 
			} 
		}
	
	    void type(string word) {
	
	        if (isUFull()) {
	            cout << "Undo Stack is Full!" << endl;
	            return;
	        }
	        
	        utop++;
	        undoStack[utop] = word;
	
	        if (text == "") {
	            text = word;
	        }
	        else {
	            text = text + " " + word;
	        }
	        rtop = -1; //because new text so cannot redo
	        print();
	    }
	
	    void undo() {
	
	        if (isUEmpty()) {
	            cout << "Nothing to undo!" << endl;
	            return;
	        }

	        string word = undoStack[utop];
	        utop--;
	
	        if (isRFull()) {
	            cout << "Redo Stack is Full!" << endl;
	            return;
	        }
	
	        rtop++;
	        redoStack[rtop] = word;
	
	        // remove word from end of document, could have done w stack if qs says 3 stacks
	        int pos = text.rfind(word); //finding word position
	        if (pos != string::npos) {
	
	            if (pos == 0) {
	                text = "";
	            }
	            else {
	                text = text.substr(0, pos - 1);
	            }
	        }
	
	        cout << "After undo(): ";
	        print();
	    }
	
	    void redo() {
	
	        if (isREmpty()) {
	            cout << "Nothing to redo!" << endl;
	            return;
	        }
	        
	        string word = redoStack[rtop];
	        rtop--;
	        utop++;
	        undoStack[utop] = word;
	        if (text == "") {
	            text = word;
	        }
	        else {
	            text = text + " " + word;
	        }
	        cout << "After redo(): ";
	        print();
	    }
	
	    void print() {
	        if (text == "") {
	            cout << "[empty]" << endl;
	        }
	        else {
	            cout << text << endl;
	        }
	    }
};

int main() {

    Editor e1;

    e1.type("Hello");
    e1.type("World");

    e1.undo();

    e1.redo();

    e1.undo();

    e1.type("There");

    e1.redo();

    return 0;
}
