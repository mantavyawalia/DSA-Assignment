#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = NULL; }

    void insertEnd(int x) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            return;
        }
        Node* p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void display() {
        Node* p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
