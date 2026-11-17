
#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx  = 0;      
int rearIdx   = -1;     
int itemCount = 0;      

bool isEmpty() { return itemCount == 0; }
bool isFull()  { return itemCount == MAX; }

void resetQueue() {
    frontIdx = 0;
    rearIdx = -1;
    itemCount = 0;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! " << value << " cannot be inserted.\n";
        return;
    }
    rearIdx = (rearIdx + 1) % MAX;
    queueArr[rearIdx] = value;
    itemCount++;
    cout << value << " inserted successfully.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully.\n";
    frontIdx = (frontIdx + 1) % MAX;
    itemCount--;
}

void front() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << "\n";
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue: ";
    for (int i = 0; i < itemCount; i++) {
        cout << queueArr[(frontIdx + i) % MAX] << " ";
    }
    cout << "\n";
}

void mandatoryTest() {
    resetQueue();
    cout << "\n--- Mandatory Test ---\n";
    int vals[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) enqueue(vals[i]);   // langkah 1-5
    dequeue();                                      // langkah 6
    dequeue();                                      // langkah 7
    enqueue(60);                                    // langkah 8 (wrap)
    enqueue(70);                                    // langkah 9 (wrap)
    display();                                      // langkah 10
}

int main() {
    int choice = 0, value;

    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue  3. Front\n";
        cout << "4. Display  5. Run Mandatory Test  6. Exit\n\n";
        cout << "Choose operation: ";

        if (!(cin >> choice)) {
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
                enqueue(value);
                break;
            case 2: dequeue();       break;
            case 3: front();         break;
            case 4: display();       break;
            case 5: mandatoryTest(); break;
            case 6: cout << "Program finished.\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);

    return 0;
}
