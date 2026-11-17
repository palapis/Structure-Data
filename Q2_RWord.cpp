
#include <iostream>
using namespace std;

const int MAX = 100;
char stackArr[MAX];     
int top = -1;           

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow!\n";
        return;
    }
    top++;
    stackArr[top] = c;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return '\0';
    }
    char c = stackArr[top];
    top--;
    return c;
}

int main() {
    char word[MAX];
    char reversed[MAX];

    cout << "Enter a word: ";
    cin.getline(word, MAX);          

    int len = 0;
    while (word[len] != '\0') {
        len++;
    }

    if (len == 0) {
        cout << "\nNo word entered.\n";
        return 0;
    }

    for (int i = 0; i < len; i++) {
        push(word[i]);
    }

    int j = 0;
    while (!isEmpty()) {
        reversed[j] = pop();
        j++;
    }
    reversed[j] = '\0';

    cout << "\nOriginal word: " << word << "\n";
    cout << "Reversed word: " << reversed << "\n";

    return 0;
}
