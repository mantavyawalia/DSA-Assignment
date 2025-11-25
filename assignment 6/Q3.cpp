#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int x){ data=x; next=NULL; prev=NULL; }
};

class DLL {
public:
    DNode* head;
    DLL(){ head=NULL; }

    void insertEnd(int x){
        DNode* t=new DNode(x);
        if(head==NULL){ head=t; return; }
        DNode* p=head;
        while(p->next!=NULL) p=p->next;
        p->next=t;
        t->prev=p;
    }

    int size(){
        int cnt=0;
        DNode* p=head;
        while(p!=NULL){ cnt++; p=p->next; }
        return cnt;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int x){ data=x; next=NULL; }
};

class CLL {
public:
    CNode* last;
    CLL(){ last=NULL; }

    void insertEnd(int x){
        CNode* t=new CNode(x);
        if(last==NULL){ last=t; t->next=t; return; }
        t->next=last->next;
        last->next=t;
        last=t;
    }

    int size(){
        if(last==NULL) return 0;
        int cnt=1;
        CNode* p=last->next;
        while(p!=last){ cnt++; p=p->next; }
        return cnt;
    }
};

int main(){
    DLL d;
    d.insertEnd(10);
    d.insertEnd(20);
    d.insertEnd(30);
    cout<<"Size of Doubly Linked List: "<<d.size()<<endl;

    CLL c;
    c.insertEnd(100);
    c.insertEnd(200);
    c.insertEnd(300);
    c.insertEnd(400);
    cout<<"Size of Circular Linked List: "<<c.size()<<endl;

    return 0;
}
