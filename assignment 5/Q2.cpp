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

    int countKey(int key) {
        Node* p = head;
        int count = 0;
        while (p != NULL) {
            if (p->data == key) count++;
            p = p->next;
        }
        return count;
    }

    void deleteAll(int key) {
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->next->data == key) {
                Node* temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else {
                p = p->next;
            }
        }
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
    list.insertEnd(10);
    list.insertEnd(30);
    list.insertEnd(10);

    cout << "Original List: ";
    list.display();

    int key = 10;

    int count = list.countKey(key);
    cout << "Occurrences of " << key << ": " << count << endl;

    list.deleteAll(key);

    cout << "List after deleting all occurrences of " << key << ": ";
    list.display();

    return 0;
}
