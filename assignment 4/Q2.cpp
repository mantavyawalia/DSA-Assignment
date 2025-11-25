#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() { front = rear = -1; }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() { return front == -1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Circular Queue FULL\n"; return; }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cout << "Inserted: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Circular Queue EMPTY\n"; return; }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void peek() {
        if (isEmpty()) cout << "EMPTY\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "EMPTY\n"; return; }

        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nEnter: ";
        cin >> choice;

        if (choice == 1) { cin >> val; q.enqueue(val); }
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.peek();
        else if (choice == 4) q.display();
        else if (choice == 5) return 0;
        else cout << "Invalid!\n";
    }
}
