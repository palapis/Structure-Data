#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = -1;
int rearIdx = -1;

bool isEmpty() {
    return frontIdx == -1;
}

bool isFull() {
    return rearIdx == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow " << value << "cannot be inserted.\n";
        return;
    }
    if (isEmpty()) {
        frontIdx = 0;
    }
    rearIdx++;
    queueArr[rearIdx] = value;
    cout << value << "inserted successfully.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "queue underflow ! queue is empty.\n";
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully.\n";
    if (frontIdx == rearIdx) {
        frontIdx = rearIdx = -1;
    } else {
        frontIdx++;
    }
}

void front() {
    if (isEmpty()) {
        cout << "queue is empty.\n";
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << "\n";
}

void display() {
    if (isEmpty()) {
        cout << "queue is empty.\n";
        return;
    }
    cout << "Queue: ";
    for (int i = frontIdx; i <= rearIdx; i++) {
        cout << queueArr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice = 0, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue  3. Front\n";
        cout << "4. Display  5. Exit\n\n";
        cout << "Choose operation: ";

        if (!(cin >> choice)) {
            if (cin.eof()) 
            return 0;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                front();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program finished.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);

    return 0;
}