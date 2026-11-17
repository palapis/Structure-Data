#include <iostream>
using namespace std;

const int MAX = 5;      
int stackArr[MAX];      
int top = -1;           

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! " << value << " cannot be inserted.\n";
        return;
    }
    top++;
    stackArr[top] = value;
    cout << value << " inserted successfully.\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }
    cout << stackArr[top] << " removed successfully.\n";
    top--;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element: " << stackArr[top] << "\n";
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice = 0, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push  2. Pop  3. Peek\n";
        cout << "4. Display  5. Exit\n\n";
        cout << "Choose operation: ";

        if (!(cin >> choice)) {          // input bukan angka
            if (cin.eof()) return 0;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                if (!(cin >> value)) {
                    if (cin.eof()) return 0;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid value.\n";
                    break;
                }
                push(value);
                break;
            case 2: pop();     
            break;
            case 3: peek();    
            break;
            case 4: display(); 
            break;
            case 5: cout << "Program finished.\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);

    return 0;
}
