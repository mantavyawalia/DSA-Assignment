#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "DataStructure";
    stack<char> st;
    for (char c : s) st.push(c);
    string rev="";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    cout << "Reversed: " << rev;
}
