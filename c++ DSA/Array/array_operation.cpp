#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int arr[100];
    int size;

public:
    ArrayOperations() : size(0) {}

    void insertAtBeginning(int value) {
        if (size >= 100) {
            cout << "Array is full!\n";
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 0 || pos > size || size >= 100) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    void insertAtEnd(int value) {
        if (size >= 100) { 
            cout << "Array is full!\n";
            return;
        }
        arr[size++] = value;
    }

    void deleteFromBeginning() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteFromPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        size--;
    }

    int linearSearch(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    int binarySearch(int value) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == value)
                return mid;
            else if (arr[mid] < value)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    void reverseArray() {
        int start = 0, end = size - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayOperations arr;
    arr.insertAtEnd(10);
    arr.insertAtEnd(20);
    arr.insertAtEnd(30);
    arr.insertAtEnd(40);
    arr.insertAtEnd(50);
    cout << "Array after insertions: ";
    arr.display();

    arr.insertAtBeginning(5);
    cout << "After inserting at beginning: ";
    arr.display();

    arr.insertAtPosition(25, 3);
    cout << "After inserting at position 3: ";
    arr.display();

    arr.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    arr.display();

    arr.deleteFromPosition(2);
    cout << "After deleting from position 2: ";
    arr.display();

    arr.deleteFromEnd();
    cout << "After deleting from end: ";
    arr.display();

    int searchValue = 30;
    int linearResult = arr.linearSearch(searchValue);
    cout << "Linear Search for " << searchValue << ": ";
    if (linearResult != -1)
        cout << "Found at index " << linearResult << endl;
    else
        cout << "Not Found\n";

    cout << "Reversing array...\n";
    arr.reverseArray();
    arr.display();

    return 0;
}
