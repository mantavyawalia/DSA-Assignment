#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

class CLL {
public:
    Node* last;
    CLL(){ last=NULL; }

    void insertEnd(int x){
        Node* t=new Node(x);
        if(last==NULL){
            last=t;
            t->next=t;
            return;
        }
        t->next=last->next;
        last->next=t;
        last=t;
    }

    void displayRepeatHead(){
        if(last==NULL){
            cout<<"Empty\n";
            return;
        }
        Node* head=last->next;
        Node* p=head;
        while(true){
            cout<<p->data<<" ";
            p=p->next;
            if(p==head) break;
        }
        cout<<head->data;
        cout<<endl;
    }
};

int main(){
    CLL c;
    c.insertEnd(10);
    c.insertEnd(20);
    c.insertEnd(30);
    c.insertEnd(40);

    c.displayRepeatHead();

    return 0;
}
