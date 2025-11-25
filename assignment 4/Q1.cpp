#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() { front = rear = -1; }

    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue is FULL\n"; return; }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << "Inserted: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is EMPTY\n"; return; }
        cout << "Deleted: " << arr[front++] << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is EMPTY\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is EMPTY\n"; return; }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    while (true) {
        cout << "\n1.Enqueue  2.Dequeue  3.Peek  4.Display  5.Exit\nEnter: ";
        cin >> choice;

        if (choice == 1) { cin >> val; q.enqueue(val); }
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.peek();
        else if (choice == 4) q.display();
        else if (choice == 5) return 0;
        else cout << "Invalid choice!\n";
    }
}
