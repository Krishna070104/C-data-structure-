#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at a given position (0-based index)
    void insertAtPosition(int value, int pos) {
        if (pos < 0) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node(value);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from a given position
    void deleteFromPosition(int pos) {
        if (head == nullptr || pos < 0) {
            cout << "Invalid position or empty list!\n";
            return;
        }

        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Search for an element (Linear Search)
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse current node's pointer
            prev = current;        // Move prev to current
            current = next;        // Move to next node
        }
        head = prev;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout << "List after inserting at end: ";
    list.display();

    list.insertAtBeginning(5);
    cout << "After inserting at beginning: ";
    list.display();

    list.insertAtPosition(25, 2);
    cout << "After inserting at position 2: ";
    list.display();

    list.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    list.display();

    list.deleteFromPosition(1);
    cout << "After deleting from position 1: ";
    list.display();

    list.deleteFromEnd();
    cout << "After deleting from end: ";
    list.display();

    int searchValue = 20;
    cout << "Searching for " << searchValue << ": ";
    if (list.search(searchValue))
        cout << "Found!\n";
    else
        cout << "Not Found!\n";

    cout << "Reversing the list...\n";
    list.reverseList();
    list.display();

    return 0;
}
