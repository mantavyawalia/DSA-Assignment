#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    // (a) Insert at Beginning
    void insertBegin(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        cout << "Inserted at beginning.\n";
    }

    // (b) Insert at End
    void insertEnd(int x) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            cout << "Inserted at end.\n";
            return;
        }
        Node* p = head;
        while (p->next != NULL) p = p->next;
        p->next = temp;
        cout << "Inserted at end.\n";
    }

    // (c) Insert Before a Value
    void insertBefore(int value, int newVal) {
        if (head == NULL) { cout << "List empty!\n"; return; }

        if (head->data == value) {
            insertBegin(newVal);
            return;
        }

        Node* p = head;
        while (p->next != NULL && p->next->data != value)
            p = p->next;

        if (p->next == NULL) {
            cout << "Value not found!\n";
            return;
        }

        Node* temp = new Node(newVal);
        temp->next = p->next;
        p->next = temp;
        cout << "Inserted before " << value << ".\n";
    }

    // (c) Insert After a Value
    void insertAfter(int value, int newVal) {
        Node* p = head;

        while (p != NULL && p->data != value)
            p = p->next;

        if (p == NULL) {
            cout << "Value not found!\n";
            return;
        }

        Node* temp = new Node(newVal);
        temp->next = p->next;
        p->next = temp;
        cout << "Inserted after " << value << ".\n";
    }

    // (d) Delete from Beginning
    void deleteBegin() {
        if (head == NULL) { cout << "List empty!\n"; return; }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted from beginning.\n";
    }

    // (e) Delete from End
    void deleteEnd() {
        if (head == NULL) { cout << "List empty!\n"; return; }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted from end.\n";
            return;
        }

        Node* p = head;
        while (p->next->next != NULL)
            p = p->next;

        delete p->next;
        p->next = NULL;
        cout << "Deleted from end.\n";
    }

    // (f) Delete Specific Node
    void deleteValue(int value) {
        if (head == NULL) { cout << "List empty!\n"; return; }

        if (head->data == value) {
            deleteBegin();
            return;
        }

        Node* p = head;
        while (p->next != NULL && p->next->data != value)
            p = p->next;

        if (p->next == NULL) {
            cout << "Value not found!\n";
            return;
        }

        Node* temp = p->next;
        p->next = temp->next;
        delete temp;

        cout << "Deleted value " << value << ".\n";
    }

    // (g) Search Node Position
    void search(int value) {
        Node* p = head;
        int pos = 1;

        while (p != NULL) {
            if (p->data == value) {
                cout << "Found at position: " << pos << endl;
                return;
            }
            p = p->next;
            pos++;
        }
        cout << "Value not found.\n";
    }

    // (h) Display List
    void display() {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }
        Node* p = head;
        cout << "List: ";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, newVal, target;

    while (true) {
        cout << "\n--- MENU (Linked List Operations) ---\n";
        cout << "1.Insert Begin\n2.Insert End\n3.Insert Before\n4.Insert After\n"
             << "5.Delete Begin\n6.Delete End\n7.Delete Value\n8.Search\n9.Display\n10.Exit\nEnter: ";
        cin >> choice;

        if (choice == 1) { cin >> val; list.insertBegin(val); }
        else if (choice == 2) { cin >> val; list.insertEnd(val); }
        else if (choice == 3) { 
            cout << "Insert before which value? "; cin >> target;
            cout << "New value: "; cin >> newVal;
            list.insertBefore(target, newVal);
        }
        else if (choice == 4) {
            cout << "Insert after which value? "; cin >> target;
            cout << "New value: "; cin >> newVal;
            list.insertAfter(target, newVal);
        }
        else if (choice == 5) list.deleteBegin();
        else if (choice == 6) list.deleteEnd();
        else if (choice == 7) { cin >> val; list.deleteValue(val); }
        else if (choice == 8) { cin >> val; list.search(val); }
        else if (choice == 9) list.display();
        else if (choice == 10) return 0;
        else cout << "Invalid choice!\n";
    }
}
