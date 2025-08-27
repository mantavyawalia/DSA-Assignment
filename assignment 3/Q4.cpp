#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c=='^') return 3;
    else if (c=='*'||c=='/') return 2;
    else if (c=='+'||c=='-') return 1;
    else return -1;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string res="";
    for (char c : exp) {
        if (isalnum(c)) res += c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.empty() && st.top()!='(') {
                res += st.top(); st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                res += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { res+=st.top(); st.pop(); }
    return res;
}

int main() {
    string infix = "a+b*(c^d-e)";
    cout << "Postfix: " << infixToPostfix(infix);
}
