#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of queue

class Queue {
private:
    int arr[MAX]; // Array to store elements
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) front = 0; // First element
        arr[++rear] = value;
        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        cout << arr[front++] << " dequeued.\n";
        if (front > rear) front = rear = -1; // Reset queue
    }

    // Get front element
    int getFront() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}

