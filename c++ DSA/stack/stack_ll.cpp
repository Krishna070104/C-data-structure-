#include <iostream>
using namespace std;

// Node structure for Stack
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push operation (Insert at top)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack.\n";
    }

    // Pop operation (Delete from top)
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack.\n";
        delete temp;
    }

    // Peek operation (Get top element)
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
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
