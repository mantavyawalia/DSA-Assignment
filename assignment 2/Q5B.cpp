#include <iostream>
using namespace std;

class TriDiagonal {
    int *arr, n;
public:
    TriDiagonal(int size) {
        n = size;
        arr = new int[3*n - 2];
        for (int i = 0; i < 3*n-2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        if (i-j==1) return i-2;          // lower diag
        else if (i==j) return n-1 + i-1; // main diag
        else if (j-i==1) return 2*n-1+i-1; // upper diag
        else return -1;
    }
    void set(int i, int j, int val) {
        int k = index(i,j);
        if (k != -1) arr[k] = val;
    }
    int get(int i, int j) {
        int k = index(i,j);
        if (k != -1) return arr[k];
        else return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonal t(4);
    t.set(1,1,5); t.set(1,2,8);
    t.set(2,1,3); t.set(2,2,9); t.set(2,3,6);
    t.set(3,2,7); t.set(3,3,4); t.set(3,4,2);
    t.set(4,3,1); t.set(4,4,10);
    cout << "Tri-diagonal Matrix:\n";
    t.display();
}
