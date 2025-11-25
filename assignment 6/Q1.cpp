//1. Circular list
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

    void insertFirst(int x){
        Node* t=new Node(x);
        if(last==NULL){
            last=t;
            t->next=t;
            return;
        }
        t->next=last->next;
        last->next=t;
    }

    void insertLast(int x){
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

    void insertAfter(int key,int x){
        if(last==NULL) return;
        Node* p=last->next;
        do{
            if(p->data==key){
                Node* t=new Node(x);
                t->next=p->next;
                p->next=t;
                if(p==last) last=t;
                return;
            }
            p=p->next;
        }while(p!=last->next);
    }

    void insertBefore(int key,int x){
        if(last==NULL) return;
        Node* p=last->next;
        Node* prev=last;
        do{
            if(p->data==key){
                if(p==last->next){
                    insertFirst(x);
                    return;
                }
                Node* t=new Node(x);
                t->next=p;
                prev->next=t;
                return;
            }
            prev=p;
            p=p->next;
        }while(p!=last->next);
    }

    void deleteValue(int key){
        if(last==NULL) return;
        Node* p=last->next;
        Node* prev=last;
        while(true){
            if(p->data==key){
                if(p==last && p==last->next){
                    last=NULL;
                    delete p;
                    return;
                }
                prev->next=p->next;
                if(p==last) last=prev;
                delete p;
                return;
            }
            prev=p;
            p=p->next;
            if(p==last->next) break;
        }
    }

    int search(int key){
        if(last==NULL) return -1;
        Node* p=last->next;
        int pos=1;
        do{
            if(p->data==key) return pos;
            p=p->next;
            pos++;
        }while(p!=last->next);
        return -1;
    }

    void display(){
        if(last==NULL){ cout<<"Empty\n"; return; }
        Node* p=last->next;
        while(true){
            cout<<p->data<<" ";
            p=p->next;
            if(p==last->next) break;
        }
        cout<<endl;
    }
};

int main(){
    CLL c;
    int ch,x,key;

    while(true){
        cout<<"\n1.Insert First 2.Insert Last 3.Insert After 4.Insert Before 5.Delete 6.Search 7.Display 8.Exit\n";
        cin>>ch;

        if(ch==1){ cin>>x; c.insertFirst(x); }
        else if(ch==2){ cin>>x; c.insertLast(x); }
        else if(ch==3){ cin>>key>>x; c.insertAfter(key,x); }
        else if(ch==4){ cin>>key>>x; c.insertBefore(key,x); }
        else if(ch==5){ cin>>key; c.deleteValue(key); }
        else if(ch==6){ cin>>key; cout<<c.search(key)<<endl; }
        else if(ch==7){ c.display(); }
        else if(ch==8){ return 0; }
    }
}
//2. Dll
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){ data=x; next=NULL; prev=NULL; }
};

class DLL {
public:
    Node* head;

    DLL(){ head=NULL; }

    void insertFirst(int x){
        Node* t=new Node(x);
        if(head==NULL){
            head=t;
            return;
        }
        t->next=head;
        head->prev=t;
        head=t;
    }

    void insertLast(int x){
        Node* t=new Node(x);
        if(head==NULL){
            head=t;
            return;
        }
        Node* p=head;
        while(p->next!=NULL) p=p->next;
        p->next=t;
        t->prev=p;
    }

    void insertAfter(int key,int x){
        Node* p=head;
        while(p!=NULL){
            if(p->data==key){
                Node* t=new Node(x);
                t->next=p->next;
                t->prev=p;
                if(p->next) p->next->prev=t;
                p->next=t;
                return;
            }
            p=p->next;
        }
    }

    void insertBefore(int key,int x){
        Node* p=head;
        while(p!=NULL){
            if(p->data==key){
                if(p==head){ insertFirst(x); return; }
                Node* t=new Node(x);
                t->next=p;
                t->prev=p->prev;
                p->prev->next=t;
                p->prev=t;
                return;
            }
            p=p->next;
        }
    }

    void deleteValue(int key){
        Node* p=head;
        while(p!=NULL){
            if(p->data==key){
                if(p==head){
                    head=head->next;
                    if(head) head->prev=NULL;
                    delete p;
                    return;
                }
                if(p->next) p->next->prev=p->prev;
                if(p->prev) p->prev->next=p->next;
                delete p;
                return;
            }
            p=p->next;
        }
    }

    int search(int key){
        Node* p=head;
        int pos=1;
        while(p!=NULL){
            if(p->data==key) return pos;
            p=p->next;
            pos++;
        }
        return -1;
    }

    void display(){
        Node* p=head;
        if(!p){ cout<<"Empty\n"; return; }
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};

int main(){
    DLL d;
    int ch,x,key;

    while(true){
        cout<<"\n1.Insert First 2.Insert Last 3.Insert After 4.Insert Before 5.Delete 6.Search 7.Display 8.Exit\n";
        cin>>ch;

        if(ch==1){ cin>>x; d.insertFirst(x); }
        else if(ch==2){ cin>>x; d.insertLast(x); }
        else if(ch==3){ cin>>key>>x; d.insertAfter(key,x); }
        else if(ch==4){ cin>>key>>x; d.insertBefore(key,x); }
        else if(ch==5){ cin>>key; d.deleteValue(key); }
        else if(ch==6){ cin>>key; cout<<d.search(key)<<endl; }
        else if(ch==7){ d.display(); }
        else if(ch==8){ return 0; }
    }
}


