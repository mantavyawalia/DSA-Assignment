#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char x){ data=x; next=NULL; prev=NULL; }
};

class DLL {
public:
    Node* head;
    Node* tail;
    DLL(){ head=NULL; tail=NULL; }

    void insertEnd(char x){
        Node* t=new Node(x);
        if(head==NULL){ head=t; tail=t; return; }
        tail->next=t;
        t->prev=tail;
        tail=t;
    }

    bool isPalindrome(){
        Node* front=head;
        Node* rear=tail;
        while(front!=NULL && rear!=NULL && front!=rear && front->prev!=rear){
            if(front->data!=rear->data) return false;
            front=front->next;
            rear=rear->prev;
        }
        return true;
    }

    void display(){
        Node* p=head;
        while(p!=NULL){ cout<<p->data<<" "; p=p->next; }
        cout<<endl;
    }
};

int main(){
    DLL list;
    string s="radar";

    for(char ch : s) list.insertEnd(ch);

    cout<<"Doubly Linked List: ";
    list.display();

    if(list.isPalindrome()) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;

    return 0;
}
