#include <iostream>
using namespace std;

#define MAX 3 

class PlateStack {
public:
    int top;
    string plate_arr[MAX];  
    
    PlateStack() { 
        top = -1;  
    }

    bool isFull() {
        if (top == MAX - 1) {  
            return true;
        } else {
            return false;
        }
    }

    void push(string plate) {
        if (isFull()) {  
            cout << "Stack is full. Can't add more plates.\n";
            return;
        }
        top++; 
        plate_arr[top] = plate;   
        cout << "Added: " << plate << "\n";  
    }
    
    bool isEmpty() {
        if (top == -1) {  
            return true;
        } else {
            return false;
        }
    }

    string pop() {
        if (isEmpty()) {  
            cout << "Stack is empty. No plates to remove.\n";
            return "";  
        }
        
        string value = plate_arr[top]; 
        top--; 
        cout << "Removed: " << value << "\n";  
        return value;  
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No plates on top.\n";
            return "";
        }
        return plate_arr[top]; 
    }

    void display() { 
        if (top == -1) {
            cout << "Stack is empty.\n";  
            return;
        }
        cout << "Current stack of plates: ";
        for (int i = 0; i <= top; i++) {
            cout << plate_arr[i] << " ";  
        }
        cout << "\n";  
    }
};

int main() {
    PlateStack stack;  
    
    stack.push("Plate 1");
    stack.push("Plate 2");
    stack.push("Plate 3");
    
    stack.display();  
    
    cout << "Top plate: " << stack.peek() << "\n";
    
    stack.push("Plate 4"); 
    
    string data = stack.pop();  
    stack.display();  
    
    data = stack.pop();      
    stack.display();  
    
    data = stack.pop();      
    stack.display();  
    
    data = stack.pop();  

    return 0;
}
