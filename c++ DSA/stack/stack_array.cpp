#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the stack

class Stack {
private:
    int arr[MAX];  // Stack array
    int top;       // Top index

public:
    Stack() {
        top = -1;  // Initialize stack as empty
    }

    // Push operation (Insert element)
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack.\n";
    }

    // Pop operation (Remove top element)
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    // Peek operation (Get top element)
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Display stack elements
    void display() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack elements (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
