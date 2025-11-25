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

    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        if (head == NULL) return -1;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertEnd(50);

    int mid = list.findMiddle();
    cout << "Middle element: " << mid << endl;

    return 0;
}
