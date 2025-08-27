#include <iostream>
using namespace std;

class Symmetric {
    int *arr, n;
public:
    Symmetric(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for (int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }
    int index(int i,int j) {
        if (i>=j) return (i*(i-1))/2 + (j-1);
        else return (j*(j-1))/2 + (i-1);
    }
    void set(int i,int j,int val) {
        arr[index(i,j)] = val;
    }
    int get(int i,int j) {
        return arr[index(i,j)];
    }
    void display() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main() {
    Symmetric sm(3);
    sm.set(1,1,1); sm.set(1,2,2); sm.set(1,3,3);
    sm.set(2,2,4); sm.set(2,3,5);
    sm.set(3,3,6);
    cout<<"Symmetric Matrix:\n"; sm.display();
}
