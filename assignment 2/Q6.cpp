#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
    int rows, cols, num; 
    Element *ele;
public:
    SparseMatrix(int r,int c,int n) {
        rows=r; cols=c; num=n;
        ele=new Element[num];
    }
    void read() {
        cout<<"Enter elements (row col value):\n";
        for(int i=0;i<num;i++) {
            cin>>ele[i].row>>ele[i].col>>ele[i].val;
        }
    }
    void display() {
        int k=0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(k<num && ele[k].row==i && ele[k].col==j)
                    cout<<ele[k++].val<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }

    // (a) Transpose
    SparseMatrix transpose() {
        SparseMatrix t(cols,rows,num);
        int k=0;
        for(int i=0;i<num;i++) {
            t.ele[k].row=ele[i].col;
            t.ele[k].col=ele[i].row;
            t.ele[k].val=ele[i].val;
            k++;
        }
        return t;
    }

    // (b) Addition
    SparseMatrix add(SparseMatrix &s) {
        if(rows!=s.rows || cols!=s.cols) throw "Incompatible";
        SparseMatrix sum(rows,cols,num+s.num);
        int i=0,j=0,k=0;
        while(i<num && j<s.num) {
            if(ele[i].row<s.ele[j].row || 
               (ele[i].row==s.ele[j].row && ele[i].col<s.ele[j].col))
                sum.ele[k++]=ele[i++];
            else if(s.ele[j].row<ele[i].row || 
               (ele[i].row==s.ele[j].row && s.ele[j].col<ele[i].col))
                sum.ele[k++]=s.ele[j++];
            else {
                sum.ele[k]=ele[i];
                sum.ele[k++].val=ele[i++].val+s.ele[j++].val;
            }
        }
        while(i<num) sum.ele[k++]=ele[i++];
        while(j<s.num) sum.ele[k++]=s.ele[j++];
        sum.num=k;
        return sum;
    }

    // (c) Multiplication (basic)
    SparseMatrix multiply(SparseMatrix &s) {
        if(cols!=s.rows) throw "Incompatible";
        SparseMatrix result(rows,s.cols,rows*s.cols); // upper bound
        int k=0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<s.cols;j++) {
                int sum=0;
                for(int x=0;x<num;x++) {
                    if(ele[x].row==i) {
                        for(int y=0;y<s.num;y++) {
                            if(s.ele[y].row==ele[x].col && s.ele[y].col==j)
                                sum += ele[x].val * s.ele[y].val;
                        }
                    }
                }
                if(sum!=0) {
                    result.ele[k].row=i;
                    result.ele[k].col=j;
                    result.ele[k].val=sum;
                    k++;
                }
            }
        }
        result.num=k;
        return result;
    }
};

int main() {
    SparseMatrix s1(3,3,3), s2(3,3,3);
    cout<<"Matrix 1:\n"; s1.read();
    cout<<"Matrix 2:\n"; s2.read();

    cout<<"Matrix 1:\n"; s1.display();
    cout<<"Matrix 2:\n"; s2.display();

    cout<<"\nTranspose of Matrix 1:\n"; s1.transpose().display();
    cout<<"\nAddition of Matrix 1 and Matrix 2:\n"; s1.add(s2).display();
    cout<<"\nMultiplication of Matrix 1 and Matrix 2:\n"; s1.multiply(s2).display();
}
